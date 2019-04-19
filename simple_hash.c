#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

struct hashNode
{
    char token[100];   
    struct hashNode* next;
}

int addNewToken(hashNode[26], char token[]);
int asciiLetterValue(char c);
void addTokenToHash(char fileWord[], char token[]);
void loadFileStrings(hashNode[26], FILE* fptr);


hashNode hashTable[26];


int main()
{
    //INITIALIZE TABLE TO NULL
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            hashTable[i] = NULL;
        }
    }

    //OPEN FILE AND MAKE SURE NO ERRORS
    FILE* fptr;
    fptr = fopen("C:\\wordhash.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    

    while (fgets(temp, 100, fptr) != NULL)
    {
        char* inputs = (char*)malloc(sizeof(temp));
        toUpper(inputs[0]);

        for (int m = 'A'; m <= 'Z'; m++)
        {
            int k = 0, n = 0, i;
            if (inputs[0] == m)
            {
                for (i = 0; i < 100; i++)
                {
                        if ((inputs[k] != '\0') && (hashT[m - 'A'][i] == NULL))
                        {
                            hashT[m - 'A'][i] = inputs[k];
                            i++; k++;
                        }
                            
                        if (hashT[m - 'A'][99] != NULL)
                        {
                            printf(“Token not added. Array with that hash is full\n\n”);
                            break;
                        }
                    
                        if(inputs[k] == '\0')
                            hashT[m - 'A'][i + 1] = '\0';
                        
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
                        printf("Words with %c: %s", hashT[i], hashT[i][j]);
                    else
                        printf("\n             ");
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
    
    
    
    
    //Calculates ASCII value of letter to match to right place in array
    int asciiLetterValue(char c)
    {
        if(!isalpha(c))
        {
            printf("Not a letter!\n");
            return -1;
        }
        
        int value;
        
        value = toupper(c);
        
        return value - 'A';
        
    }
