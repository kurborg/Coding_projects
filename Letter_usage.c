#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char word[];
char alphabet['a', 'b' , 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' ,'l','m','n','o','p', 'q','r','s','t','u','v','w','x','y','z'];
int count[26];

int match( char word[], char c)
{
	int num = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == c)
			num = num +1;
	}

	return num;
} 

int main()
{

printf("Please enter your word\n");
scanf("%s", word);

for (int j = 0, l = strlen(alphabet); j < l; j ++)
{
	char ch = alphabet[j];
	count[ch] = match(word, ch);

	printf("\nLetter %c was used %d times.Percentage of usage is: %d\n",ch, count[ch], ((count[ch]/strlen(word))*100));
}


return 0;

}
