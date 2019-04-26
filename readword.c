#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define WORD_SIZE 50

char* get_token(FILE* fp)
{
	char* token = calloc(WORD_SIZE, sizeof(char));
	char ch;
	int fileStatus, i = 0;
	
	while(1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			fileStatus = 0;
			break;
		}
		
	
		else if (ch == '\n' || ch == ' ' || ch == '\t')
		{
			token [i] = '\0';
			printf("\nRaw token: %s" , token);
			
			while (ch == ' ' || ch == '\n' || ch == '\t')
            {
				ch = fgetc(fp);
                    
            }
                return token;
		}

		else 
			token[i++] = ch;
	}

	if (fileStatus == 0)
		return NULL;
}


int main(int argc, char* argv[])
{

FILE* fptr;
char* filename = argv[1];

fptr = fopen(filename, "r");

int tokens_count = 0;

char* word;

while((word = get_token(fptr))!= NULL)
{
	++tokens_count;

	printf("\nToken: %s", word);
	free(word);
}

printf("\n\nTotal number of tokens: %d\n", tokens_count);

return 0;
}

