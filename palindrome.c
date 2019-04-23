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

for(int n = 0, m = len; n != m; n++, m--)
{
  if(input[n] != input[m])
  {
    printf("%s is not a palindrome! \n\n", input);
    return 1;
  }
  
  else 
  {
    printf("%s is a palindrome! \n\n", input);
    return 1;
  }
  
 }

}

size_t string_length(char word[])
{
  int counter = 0;

  while(word[i] != '\0')
  {
    ++counter;
  }
  
  return counter;
}
