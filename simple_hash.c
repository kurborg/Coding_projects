#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main()
{

    char* hashT[26][100];
    char* inputs[100], temp[100];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            hashT[i][j] = NULL;
        }
    }

    int i = 0;
    FILE* fptr;
    fptr = fopen("C:\\wordhash.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    while (fgets(temp, 80, fptr) != NULL)
    {
        char* inputs = (char*)malloc(sizeof(temp));
        toUpper(inputs[i]);

        for (int m = 65; m < 91; m++)
        {
            int k = 0, n = 0, i;
            if (inputs[0] == m)
            {
                for (i = 0; i < 100; i++)
                {
                        while ((inputs[k] != '\0') && (hashT[m - 65][i] == NULL))
                        {
                            hashT[m - 65][i] = inputs[k];
                            i++; k++;
                        }
                            
                        If (hashT[m-65][99] != NULL)
                            printf(“Token not added. Array with that hash is full\n\n”);

                            hashT[m - 65][i + 1] = '\0';
                        }
                    }
                }

        free(inputs);
    }
    

        for (i = 0; i < 26; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (hashT[i][j] != NULL)
                {
                    if (hashT[i][j] != '\0')
                        printf("Words with %c : %s", hashT[i], hashT[i][j]);
                    else
                        printf("\n");
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (hashT[i][j] != NULL)
                {
                    free(hashT[i][j]);
                }
                
            }
        }

        fclose(fptr);

        system("pause");
        return 0;
}
