#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE* fptr;
  
  char filename[100] = argv[1];
  int counter;
  
  fptr = fopen(filename, 'r');
  
  if(fptr)
  {
    while((ch = getc(fptr)) != EOF)
    {
      if (ch == ' ' || ch == '\n')
        ++counter;
    }
  
  }
  
  else
    prinft("ERROR OPENING FILE\n\n");
    
  
  printf("The number of words in the file are: %d", counter);
  
  
  return 0;
}
