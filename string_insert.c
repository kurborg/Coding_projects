#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Please enter 3 input commands!\n\n");
		return 0;
	}

	int i = 0, num, len1 = 0, len2 = 0;
	char* s1;
	char* s2;

	s1 = argv[1];
	num = atoi(argv[2]);
	s2 = argv[3];

	//printf("\nword 1: %s \nword 2: %s \n", s1, s2);


	while (s1[i] != '\0')
	{
		++len1;
		i++;
	}
	
	//printf("\nlength 1: %d \nword: %s \n", len1, s1);

	i = 0;
	while (s2[i] != '\0')
	{
		++len2;
		i++;
	}

	//printf("\n length 2: %d \nword: %s \n", len2, s2);
	
	if (num > len1 || num < 0)
	{
		printf("\ninvalid position given.\n\n");
		return 1;
	}


	char *result = (char*)malloc(sizeof(char) * (1 + len1 + len2));

	if (result == NULL)
	{
		printf("Error allocating memory");
		exit(1);
	}

	for (int i = 0; i < num; i++)
	{
		result[i] = s1[i];
	}
	for (int i = 0; i < len2; i++)
	{
		result[num + i] = s2[i];
	}
	for (int i = num; i < len1; i++)
	{
		result[len2 + i] = s1[i];
	}


	result[len1 + len2] = '\0';

	printf("\n\nFinal string is: %s \n\n", result);

	free(result);

	return 0;

}
