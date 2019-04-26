/*
*****************************************************************
Compile using: gcc -g -Wall -std=gnu99 wordhash.c -o wordhash
******************************************************************
*/

#ifndef WORDHASH_H_
	#include "wordhash.h"
#endif


char* get_token(FILE* fp)
{
	char* token = calloc(WORD_SIZE, sizeof(char));
	char ch;
	int fileStatus, i = 0;
    int eof_flag = 1, whitespace_flag = 0;
	
	while((ch = fgetc(fp))!= EOF)
	{
		eof_flag = 0;
		
	
		if(ch == '\n' || ch == ' ' || ch == '\t')
		{
            whitespace_flag = 1;
		}
		
		else if(!whitespace_flag)
			token[i++] = ch;

		else 
        {
            ungetc(ch, fp);
            break;
        }
	}
	
    if (!eof_flag)
		{
            token[i] = '\0';
            printf("\nRaw token: %s" , token);
			return token;
		}
	else
		return NULL;
}


void init_hash_table(struct hash_entry hash_table[]) 
{
	for (int i = 0; i < HASH_TABLE_SIZE;i++) 
	{
		hash_table[i].head = NULL;
		hash_table[i].count = 0;
	}

	return;
}


void insert_in_hash_table(struct hash_entry hash_table[], char *token) 
{
    // This function will insert a token into the correct location
	// of the hash table. The token is inserted at the head of the correct
	// location in the hash table. Note that if there are duplicate tokens,
	// then the linked list will have multiple entries corresponding to each
	// occurrence of the duplicate token.
	
	int row = toupper(token[0]) - 65;
	
	struct node* new_node = malloc(sizeof(struct node));
	
	if (new_node == NULL)
	{
		printf("Error allocating memory!\n\n");
		exit(1);
	}
	
	new_node->data = token;
	new_node->next = hash_table[row].head;
    
    hash_table[row].head = new_node;
    hash_table[row].count++;
}

void print_hash_table(struct hash_entry hash_table[]) 
{
	for (int i = 0;i < HASH_TABLE_SIZE;i++) 
	{
		printf("\n(%c, %d) :: \t",i + 65, (hash_table[i].head != NULL ? hash_table[i].count : 0));		
		// character value in A-Z range
        struct node* ptr = hash_table[i].head;
		// Now traverse linked list of hash_table[i]
		while (ptr != NULL) 
		{
			printf("%s --> ",ptr->data);
            ptr = ptr->next;
		}
		printf("NULL\n");
	}

	return;
}

void delete_hash_table(struct hash_entry hash_table[]) 
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) 
	{
		if (hash_table[i].head != NULL) 
		{
			struct node *ptr = hash_table[i].head->next;
			struct node *prev = hash_table[i].head;
			
			while(1)
			{
				if(ptr != NULL)
                {   prev = ptr;
					ptr = ptr->next;
					free(prev);
				}
				
				else
					break;
			}
		}
		hash_table[i].head = NULL;
	}
}


int main(int argc, char *argv[]) {
	char* word = NULL;

	struct hash_entry hash_table[HASH_TABLE_SIZE];
	init_hash_table(hash_table);

	FILE *fp = NULL;
	if (argc > 1) 
	{
		if ((fp = fopen(argv[1],"r")) == NULL) 
		{
			fprintf(stderr,"\nError in opening file %s. Exiting...\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	int tokens_count = 0, raw_tokens_count = 0, i = 0;

	while ((word = get_token(fp)) != NULL) 
	{
		++raw_tokens_count;
		// If word starts with a letter, then insert into hash table
		if(word[0] >= 'a' || word[0] <= 'Z')
		{
			printf("\nToken to insert into hash table: %s", word);
			insert_in_hash_table(hash_table, word);
		} 
		
		else 		// otherwise discard the raw token
			free(word);
	}

	print_hash_table(hash_table);
	printf("\nTotal raw tokens found = %d\n", raw_tokens_count);
	printf("\nTotal tokens inserted into hash table = %d\n", tokens_count);
    
    delete_hash_table(hash_table);

	return 0;
}
