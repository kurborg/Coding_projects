/*
******************************************************************
*   Compile using: gcc -g -Wall -std=gnu99 wordhash.c -o wordhash
******************************************************************
*/

#ifndef WORDHASH_H_
	#include "wordhash.h"
#endif


char* get_token(FILE* fp)
{
    char* token = calloc(WORD_SIZE, sizeof(char));

    fgets(token, WORD_SIZE, fp);

    // reached end of file -->
    if (fgets(token, WORD_SIZE, fp) == NULL)
    {
    return NULL;
    }

    // Otherwise return token
    printf("\nRaw token = %s",token);
    return token;
}


void init_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0; i < HASH_TABLE_SIZE;i++) {
		hash_table[i].head = NULL;
		hash_table[i].count = 0;
	}

	return;
}


void insert_in_hash_table(struct hash_entry hash_table[], char *token) {
    // This function will insert a token into the correct location
	// of the hash table. The token is inserted at the head of the correct
	// location in the hash table. Note that if there are duplicate tokens,
	// then the linked list will have multiple entries corresponding to each
	// occurrence of the duplicate token.

	return;
}

void print_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0;i < HASH_TABLE_SIZE;i++) {
		printf("\n(%c, %d) :: \t",i + 65, (hash_table[i].head != NULL ? hash_table[i].count : 0));		// character value in A-Z range

		// Now traverse linked list of hash_table[i]
		while (ptr != NULL) {
			printf("%s --> ",ptr->data);
		}
		printf("NULL\n");
	}

	return;
}

void delete_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (hash_table[i].head != NULL) {
			struct node *ptr = hash_table[i].head->next;
			struct node *prev = hash_table[i].head;
			do {
				// YOUR CODE GOES HERE

			} while (prev != NULL);
		}
		hash_table[i].head = NULL;
	}

	return;
}


int main(int argc, char *argv[]) {
	char* word = NULL;

	struct hash_entry hash_table[HASH_TABLE_SIZE];
	init_hash_table(hash_table);

	FILE *fp = NULL;
	if (argc > 1) {
		if ((fp = fopen(argv[1],"r")) == NULL) {
			fprintf(stderr,"\nError in opening file %s. Exiting...\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	int tokens_count = 0, raw_tokens_count = 0;

	while ((word = get_token(fp)) != NULL) {
		// first convert token to upper case
		++raw_tokens_count;
		// If word starts with a letter, then insert into hash table
			printf("\nToken to insert into hash table: %s", word);
			insert_in_hash_table(hash_table, word);
		} else {		// otherwise discard the raw token
			free(word);
		}
	}

	print_hash_table(hash_table);
	printf("\nTotal raw tokens found = %d\n", raw_tokens_count);
	printf("\nTotal tokens inserted into hash table = %d\n", tokens_count);

	return 0;
}
