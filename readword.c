#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define WORD_SIZE 50


// This function will extract tokens from file - one word at a time
// A word is defined by a sequence of non-whitespace characters surrounded
// on both sides by one or more whitespace characters
// Your code MUST be able to handle consecutive whitespace characters
// while extracting the tokens!

char* get_token(FILE* fp)
{
	char* token = calloc(WORD_SIZE, sizeof(char));
	char ch;
	int fileStatus, i = 0;

	while (1)
	{
		ch = fgetc(fp);

		if (ch == EOF)
		{
			fileStatus = 0;
			break;
		}

		else if (ch == '\n' || ch == ' ' || ch == '\t')
		{
			token[i] = '\0';
			i = 0;
			printf("\nRaw token = %s",token);
			return token;
			while((ch == ' ' || ch == '\n' || ch == '\t')&& (ch != EOF))
				ch = fgetc(fp);
			break;
		}

		else
			token[i++] = ch;
	}

    	if(fileStatus == 0) 
		return NULL;
  
}


int main(int argc, char *argv[]) 
{

  FILE* fptr;
  char* filename = argv[1];

  fptr = fopen(filename, "r");

  int tokens_count = 0;
  char* word = calloc(WORD_SIZE, sizeof(char));

  while ((word = get_token(fptr)) != NULL)
  {
      ++tokens_count;

      printf("\nToken: %s", word);

      free(word);
  }

  printf("\nTotal tokens found = %d\n", tokens_count);
  

  return 0;

}
