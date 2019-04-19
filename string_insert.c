#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    if(argc!=4)
    {
        printf(“Please enter 3 input commands! \n\n”);
        return 0;
    }

    int i, num, len1 = 0, len2 = 0;
    char s1[10], s2[10], s3[10];

    s1[10] = argv[1];
num = atoi(argv[2]);
    s2[10] = argv[3];
    
    if (num > len1 || num < 0) 
{
        printf("invalid position given.\n\n");
        return 1;
    }

    i = 0;
    while (s1[i] != '\0') 
    {
        len1++;
        i++;
    }
    i = 0;
    while (s3[i] != '\0') 
    {
        len2++;
        i++;
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
        result[num + i] = s3[i];
    }
    for (int i = num; i < len1; i++) 
    {
        result[len2 + i] = s1[i];
    }


    result[len1 + len2] = '\0';

    printf("\n\nFinal string is: %s \n\n", result);

    free(result);


    system("pause");
    return 0;

}
