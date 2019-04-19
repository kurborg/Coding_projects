#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeroBitCount(int bin)
{

    int count = 0;

    if (bin == 0)
        return 1;

    while (bin > 0)
    {
        if ((bin & 1) == 0)
            count = count + 1;

        bin = bin >> 1;
    }


    return count;

}

int main(int argc, char* argv[])
{
    int num;
    num= atoi(argv[1]);

    if(num < 0)
    {
        printf(“Please enter a non-negative integer in the command line \n\n”);
        return 0;
    }

    printf("\n\nThe number of 0's in %d in binary is %d \n\n", num, zeroBitCount(num));  


    system("pause");
    return 0;

}
