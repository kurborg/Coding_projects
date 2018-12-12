#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
void hw1();
void hw2();
void hw3();
void hw4();
void hw5();
void insert();
void print();
void delete();
void printSorted();

//hw1();

//hw2();

//hw3();

//hw4();

//hw5();

return 0;
}




void hw1()
{
char input[20];
int i = 0;

while (input != "exit")
{
printf("\nPlease enter a word\n");
scanf("%s", input);

if (input == "exit")
exit(1);

else
{

for (int j = 0; j < strlen(input); j++)
printf("****");

printf("\n");
while (input[i] != '\0')
{

printf("%c * ", toupper(input[i]));
i++;
}
printf("\n");
for (int j = 0; j < strlen(input); j++)
printf("****");

}
}
}


void hw2()
{
char word[30];
int count[26] = { 0 };
int i = 0;

printf("Please enter your word\n");
scanf("%s", word);

int length = strlen(word);

for (i = 0; i < length; i++)
{
char c = word[i];
if (!isalpha(c))
continue;
count[(int)(tolower(c) - 'a')]++;
}

for (i = 0; i < 26; i++)
{
if (count[i]> 0)
{
int length = strlen(word);
float percent = 100.0 * (count[i] / length);
printf("%c appears %d times. Percentage: %f \n", i + 'a', count[i], percent);
}
}

system("pause");
}


void hw3()
{
char message[50], eMessage[50], deMessage[50], key[10], tempKey[50];
int i, j;

printf("Please enter key: ");
scanf("%s", key);

printf("\nPlease enter message: ");
scanf("%[^\n]s", message);

for (i = 0; i < strlen(message); i++)
{
char c = message[i];
if (!isalpha(c))
message[i] + 'a';

message[i] = tolower(message[i]);
}

for (i = 0, j = 0; i < strlen(message); i++, j++)
{
if (j == strlen(key))
j = 0;

tempKey[i] = key[j];
}

for (i = 0; i < strlen(message); i++)
eMessage[i] = ((message[i] + tempKey[i]) % 26) + 'a';

eMessage[i] = '\0';

for (i = 0; i < strlen(message); i++)
deMessage[i] = (((eMessage[i] - tempKey[i]) + 26) % 26) + 'a';

deMessage[i] = '\0';


printf("\nMessage is: %s\n", message);
printf("Key is: %s\n", key);
printf("Encrypted message is: %s\n", eMessage);
printf("Decrypted message is: %s\n", deMessage);

system("pause");
}


void hw4()
{
int input[40];
int in;
int length = 0;

FILE* read = fopen("input.txt", "r");
FILE* write = fopen("output.txt", "w");

while (!feof(read))
{
fscanf(read, "%d", &in);
input[length++];
}

for (int i = 0; i < length; i++)
fprintf(write, "%d %d", input[i], input[length + 1]);

if (length % 2 != 0)
fprinft(write, "%d", input[length / 2]);

fclose(read);
fclose(write);
}




typedef struct book
{
char title[40];
char author[30];
int year;
float price;
struct book *next;
};

struct book newBook;
char find;
FILE *fp, *ft;

void hw5()
{

struct book library[20];
int choice;

void insert();
void print();
void delete();
void printSorted();

{
while(1)
{
printf("\nPress 1 to Insert\n");
printf("Press 2 to Print\n");
printf("Press 3 to Remove\n");
printf("Press 4 to Print sorted\n");
printf("Press 5 to Exit\n");
scanf("%d", &choice);
switch (choice)
{
case 1:
insert();
break;
case 2:
print();
break;
case 3:
delete();
case 4:
printSorted();
case 5:
exit(0);
default:
printf("Please re-enter valid choice");
}
}


return 0;
}
}

void insert()
{
char t[40], a[30];
int y, p;


printf("\nEnter title : ");
scanf("%s", &newBook.title);

printf("Enter author : ");
scanf("%s", &newBook.author);

printf("Enter year : ");
scanf("%d", &newBook.year);

printf("Enter price : ");
scanf("%f", &newBook.price);

fp = fopen("library.txt", "ab+");
fseek(fp, 0, SEEK_END);
fwrite(&newBook, sizeof(newBook), 1, fp);
fclose(fp);

printf("\n A new record was created.\n");
hw5();

}

void print()
{
int i = 0;
fp = fopen("library.txt", "rb");
while (fread(&newBook, sizeof(newBook), 1, fp) == 1);
{
printf("\n Book number #%d\n", i++);
printf("Title: %s\n", newBook.title);
printf("Author: %s\n", newBook.author);
printf("Year: %d\n", newBook.year);
printf("Price: %f\n", newBook.price);
}

getchar();
hw5();
}
void delete()
{
char t[40];
char temp;

printf("Enter the Book title to remove:");
scanf("%s", t);

fp = fopen("lib.txt", "rb+");
rewind(fp);

while (fread(&newBook, sizeof(newBook), 1, fp) == 1)
{
for (int i = 0; i < strlen(newBook.title); i++)
{
if (newBook.title[i] == t[i])
find = 't';
}
}

if (find != 't')
{
printf("\nNo such book exists in this library\n");
getchar();
hw5();
}

else
{

ft = fopen("libTemp.txt", "wb+");
rewind(fp);

while (fread(&newBook, sizeof(newBook), 1, fp) == 1)
{
temp = 'f';

for (int i = 0; i < strlen(newBook.title); i++)
{
if (newBook.title[i] == t[i])
temp = 't';
else
{
temp = 'f';
break;
}
}

if (temp == 'f')
{
fseek(ft, 0, SEEK_CUR);
fwrite(&newBook, sizeof(newBook), 1, ft);
}
}

fclose(ft);
fclose(fp);

remove("library.txt");
rename("libTemp.txt", "library.txt");

fp = fopen("library.txt", "rb+");
printf("\nThe book was deleted\n");
getchar();

}

hw5();
}

void sort()
{


}


void printSorted()
{





}
