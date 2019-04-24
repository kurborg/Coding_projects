#include <stdio.h>

size_t string_length(char word[]);


int main(int argc, char* argv[])
{

if(argc != 2)
{
  printf("Please enter only one string on the command line!\n");
  return -1;
}

char input[] = argv[1];

int len = string_length(input);
int middle = len /2;
int end = len - 1;
  

for(int i = 0; i < middle; i++)
{
  if(input[i] != input[end])
  {
    printf("%s is not a palindrome! \n\n", input);
    break;
  }
  
  end--; 
  
  if(i == middle)
    printf("%s is a palindrome! \n\n", input);
  
 }

  return 0;
}

size_t string_length(char word[])
{
  int counter = 0, i = 0;
  
  while(word[i] != '\0')
  {
    i++;
    ++counter;
  }
  
  return counter;
}
