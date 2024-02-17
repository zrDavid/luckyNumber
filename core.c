//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char name[30];
char response;
int lnumber;

void welcomeMessage(char str[])
{
	printf("\nHello %s\n", str);
}

void byeMessage(char str[])
{
	printf("Goodbye %s. See you soon\n", str);
}

void getName(void (*ptrf)(char str[]))
{
	printf("Write your name: ");
	scanf_s("%31s", name, 31);
	ptrf(name);
}

void main()
{
	printf("... Starting program \n");
	// Declaring a function pointer to welcomeMessage
	void (*fnptr)(char str[]);
	fnptr = welcomeMessage;
	getName(fnptr);

	srand( time(NULL) );

	// Print a random number or leave the program
	printf("Do you want to print a random number? (y/n): ");
	scanf_s(" %c", &response, 1);
	
	while (response == 'y')
	{
		printf("\nGood! \n");
		lnumber = ( (rand() % 60) + 1);
		printf("Your lucky number is: %d\n", lnumber);
		printf("Do you want to get another lucky number? (y/n): ");
		scanf_s(" %c", &response, 1);
	}
	byeMessage(name);

}