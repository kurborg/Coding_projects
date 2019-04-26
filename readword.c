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

