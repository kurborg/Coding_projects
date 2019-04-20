#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

struct hashNode
{
    int len;
    char* token[100];   
}

hashNode hashTable[26];

int main()
{
    //INITIALIZE TABLE TO NULL
    for (int i = 0; i < 26; i++)
    {
        hashTable[i].token = "";
        hashTable[i].len = 0;
    }

    //OPEN FILE AND MAKE SURE NO ERRORS
    FILE* fptr;
    fptr = fopen("C:\\wordhash.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    
    
    //CREATE BUFFER FOR FILE INPUT
    char buff[100];
    char ch;
    int i = 0;
    
    
    //IF CHAR FROM FILE IS EOF THEN BREAK
    //IF CHAR FROM FILE IS END OF LINE ADD '\0' TO BUFFER, RESET BUFFER INDEX, THEN BREAK
    //ELSE ADD THE CHAR TO THE BUFFER
    while (1)
    {
        ch = fgetc(fptr);
       
        if (ch == EOF)
               break;
        
        else if (ch == '\n')
        {
            buff[i] = '\0';
            i = 0;
            break;
        }
        
        else 
            buff[i++] = ch;
    }
    
    //UPPERCASE THE FIRST ELEMENT OF BUFFER TO SIMPLIFY SORTING OF HASHTABLE
    buff[0] = toupper(buff[0]);
    //FIND ASCII VALUE OF THE FIRST ELEMENT FOR THE RIGHT ENTRY
    int entry = buff[0] - 'A';

    //IF ENTRY ISN'T FULL THEN ALLOCATE MEMORY FOR THE TOKEN 
    //WHEN MEMORY IS ALLOCATED, ADD THE BUFFER TO THE TOKEN 
    //ADD 1 TO THE TOKEN OF THE ENTRY
    if(hashTable[entry].len < 100)
    {
        int* letters = hashTable[value].len;
        hashTable[entry].token[letters] = malloc(strlen(buff) + 1);
        
        if(hashTable[entry].token[letters] != NULL)
        {
            hashTable[entry].token[letters] =  hashTable[entry].token[letters] + buff;
            hashTable[entry].len++;
        }
    }
    
    //IF TOKENS FOR THE ENTRY IS FULL PRINT ERROR MESSAGE
    else
      printf("“The token %s could not be entered. The corresponding entry in the hash table is already full\n\n", buff);
           
    
    
        
        
    for(int m = 0 ; m < 26 ; m++ )
     	{
     		printf("The words that begin with %c : ", 'A'+ m );
        
   			for( int n = 0 ; n < hash[m].len ; n++)
   			{
        		printf("%s ",hash[m].token[n]);
   			}
   
   			printf("\n\n");
     	}
    
    //FREE ALLOCATED MEMORY FOR EACH TOKEN FOR EACH ENTRY
	for(int m = 0 ; m < 26 ; m++ )
	{
   		for( int n = 0 ; n < hash[m].len ; n++)
   		{
       			free(hash[m].tokens[n]);
   		}
        
    }
    
    
    //CLOSE FILE ALWAYS
    fclose(fptr);
    
    system("pause");
    return 0;
}
    
    
    
    

