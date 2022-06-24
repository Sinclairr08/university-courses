/*================================================================================
* Written date : 2018.04.01
* Lastest revised date : 2018.04.09
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#define MAX_LEN 100

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P1_GeneralTest();

// Examples
void P1_Test1();
void P1_Test2();
void P1_Test3();
void P1_Test4();

// Problem 1. Palindrome Checker
int PalindromeChecker(char *sent);

int main()
{
	P1_GeneralTest();

	//P1_Test1();
	//P1_Test2();
	//P1_Test3();
	//P1_Test4();

	return 0;
}

// Input the number from the user.
void P1_GeneralTest()
{
	char sent[MAX_LEN];
	gets(sent);
	fflush(stdin);

	printf("%d\n", PalindromeChecker(sent));
}

// Example 1
void P1_Test1()
{
	char *sent = "Madam, I'm Adam";

	printf("%d\n", PalindromeChecker(sent)); // Result: 1
}

// Example 2
void P1_Test2()
{
	char *sent = "I did, did I?";

	printf("%d\n", PalindromeChecker(sent)); // Result: 1
}
// Example 3
void P1_Test3()
{
	char *sent = "Data Structure is Fun";

	printf("%d\n", PalindromeChecker(sent)); // Result: 0
}
// Example 4
void P1_Test4()
{
	char *sent = "!1?";

	printf("%d\n", PalindromeChecker(sent)); // Result: 1
}

// Problem 1. Palindrome Checker
int PalindromeChecker(char *sent)
{
	char temp[MAX_LEN];
	int cnt_sent = 0, cnt_temp = 0;
	int half, i;
	Stack* sp = malloc(sizeof(Stack));
	InitStack(sp);

	while (sent[cnt_sent] != '\0') {
		if (isalpha(sent[cnt_sent]))						// If input is an alphabet
			temp[cnt_temp++] = tolower(sent[cnt_sent++]);	// Change to lowercase

		else if (isdigit(sent[cnt_sent]))
			temp[cnt_temp++] = sent[cnt_sent++];

		else
			cnt_sent++;							// Ignore when neither alphabet nor number
	}
	
	if (cnt_temp % 2 == 0)
		half = cnt_temp / 2;

	else
		half = (cnt_temp - 1) / 2;				// To ignore the center one


	for (i = 0; i < half; i++)					// Push the element until the half
		Push(sp, temp[i]);

	for (i = cnt_temp - half; i < cnt_temp; i++) {
		if (Peek(sp) != temp[i]) {				// If not a Palindrome
			free(sp);
			return 0;
		}
		Pop(sp);
	}

	free(sp);
	return 1;									// If Palindrome
}