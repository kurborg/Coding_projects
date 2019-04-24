#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define WORD_SIZE 50

typedef enum {false  = 0, true = 1} boolean;

// This function will extract tokens from file - one word at a time
// A word is defined by a sequence of non-whitespace characters surrounded
// on both sides by one or more whitespace characters
// Your code MUST be able to handle consecutive whitespace characters
// while extracting the tokens!

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

      printf("Token: %s", word);

      free(word);
  }

  printf("\nTotal tokens found = %d\n", tokens_count);
  

  return 0;

}
