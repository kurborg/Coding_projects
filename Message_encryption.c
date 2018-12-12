#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main()
{
char message[], eMessage[], deMessage[], key[], tempKey[];
int i, j , count = 0;

printf("Please enter key: ");
scanf("%s" , key);

printf("\nPlease enter message: ");
scanf("%s" , message);

for (i = 0, j = 0; i < strlen(message); i++ j++)
{
	if (j == strlen(key))
		j = 0;

	tempKey = key[j];
}

while (count < strlen(message))
{
	eMessage[count] = (((message[count] + tempKey[count]) + 26) %26) + 'A';
	count++;
}

count = 0;

while (count <strlen(message))
{
	deMessage[count] = (((eMessage[count] - tempKey[count]) + 26) %26) + 'A';
	count++;
}


printf("\nMessage is: %s\n", message);
printf("Key is: %s\n", key);
printf("Encrypted message is: %s\n" , eMessage);
printf("Decrypted message is: %s\n" , deMessage);


return 0;
}
