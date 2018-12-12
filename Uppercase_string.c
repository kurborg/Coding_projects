#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char input[];
int i, j;

while( input != "exit")
{
	printf("Please enter a word");
	scanf("%s", input);

	if (input == "exit")
		exit(0);

	else
	{

		while (input[j])
		{
			putchar( toupper(input[j]);
			j++
		}

		printf("*********************\n")

		while(input[i] != "\o")
		{
			printf("%c * ", input[i]);
			i++
		}

		printf("\n*********************")

		return 0;
	}

}
