#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct hashNode
{
	int len;
	char* token[100];
};


int main(int argc, char* argv[])
{

	char* filename;
	filename = argv[1];


	struct hashNode hashTable[26];

	//INITIALIZE TABLE TO NULL
	for (int i = 0; i < 26; i++)
	{
		hashTable[i].len = 0;
	}

	//OPEN FILE AND MAKE SURE NO ERRORS
	FILE* fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("\nError opening file!\n");
		exit(1);
	}

	int fileStatus = 1;

	while(fileStatus)
	{
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
			{
				fileStatus = 0;
				break;
			}

			else if (ch == '\n')
			{
				buff[i] = '\0';
				i = 0;
				break;
			}

			else
				buff[i++] = ch;
		}

		//SECONDARY CHECK TO SEE IF EOF SO 2ND WORD NOT PRINTED TWICE
		if (fileStatus == 0)
			break;

		//UPPERCASE THE FIRST ELEMENT OF BUFFER TO SIMPLIFY SORTING OF HASHTABLE
		buff[0] = toupper(buff[0]);
		//FIND ASCII VALUE OF THE FIRST ELEMENT FOR THE RIGHT ENTRY
		int entry = buff[0] - 'A';

		//IF ENTRY ISN'T FULL THEN ALLOCATE MEMORY FOR THE TOKEN 
		//WHEN MEMORY IS ALLOCATED, ADD THE BUFFER TO THE TOKEN 
		//ADD 1 TO THE TOKEN OF THE ENTRY
		if (hashTable[entry].len < 100)
		{
			int word = hashTable[entry].len;
			hashTable[entry].token[word] = malloc(strlen(buff) + 1);

			if (hashTable[entry].token[word] != NULL)
			{
				strcpy(hashTable[entry].token[word], buff);
				hashTable[entry].len++;
			}
		}

		//IF TOKENS FOR THE ENTRY IS FULL PRINT ERROR MESSAGE
		else
			printf("The token %s could not be entered. The corresponding entry in the hash table is already full\n\n", buff);

	}



	for (int entry = 0; entry < 26; entry++)
	{
		if (hashTable[entry].len != 0)
		{
			printf("The words that begin with %c : ", 'A' + entry);

			for (int word = 0; word < hashTable[entry].len; word++)
			{
				printf("%s ", hashTable[entry].token[word]);
			}

			printf("\n");
		}
	}

	//FREE ALLOCATED MEMORY FOR EACH TOKEN FOR EACH ENTRY
	for (int entry = 0; entry < 26; entry++)
	{
		for (int word = 0; word < hashTable[entry].len; word++)
		{
			free(hashTable[entry].token[word]);
		}

	}


	//CLOSE FILE ALWAYS
	fclose(fptr);

	return 0;
}
