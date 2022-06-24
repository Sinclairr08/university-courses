/*================================================================================
* Written date : 2018.04.01
* Lastest revised date : 2018.04.10
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
void P2_GeneralTest();

// Examples
void P2_Test1();
void P2_Test2();
void P2_Test3();
void P2_Test4();

// Problem 2. Calculating Parenthesis
int CalParenthesis(char *sent);

int CalAdd(Stack* sp, Stack* num);
int CalMin(Stack* sp, Stack* num);
int CalGcd(Stack* sp, Stack* num);

int CalcTwoGcd(int num1, int num2);
int to_num(int c);
int is_num(int c);

int main()
{
	P2_GeneralTest();

	//P2_Test1();
	//P2_Test2();
	//P2_Test3();
	//P2_Test4();

	return 0;
}

// Input the number from the user.
void P2_GeneralTest()
{
	char sent[MAX_LEN];
	scanf("%s", sent);		// User input
	fflush(stdin);

	printf("%d\n", CalParenthesis(sent));

}

// Example 1
void P2_Test1()
{
	char sent[MAX_LEN] = "((241)[])(<84>)";

	
	printf("%d\n", CalParenthesis(sent));	// Result: 12
}

// Example 2
void P2_Test2()
{
	char sent[MAX_LEN] = "([])<<>)";

	printf("%d\n", CalParenthesis(sent));	// Result: -1

}
// Example 3
void P2_Test3()
{
	char sent[MAX_LEN] = "((12345)[12345])";

	printf("%d\n", CalParenthesis(sent));	// Result: 16

}
// Example 4
void P2_Test4()
{
	char sent[MAX_LEN] = "3(2[4<>]9)8";

	printf("%d\n", CalParenthesis(sent));	// Result: 23

}


// Problem 2. Calculating Parenthesis
int CalParenthesis(char *sent)
{
	int cnt = 0, result = 0;						
	int temp;
	int cnt_par = 0;								// To check that parenthesis matching is well
	Stack* sp = malloc(sizeof(Stack));				// Contains Parenthesis & number
	Stack* num = malloc(sizeof(Stack));				// Contains TRUE if number, FALSE if parenthesis
	InitStack(sp), InitStack(num);

	while (sent[cnt] != '\0') {
		if (is_num(sent[cnt]))						// If the input is the number
			Push(sp, to_num(sent[cnt++])), Push(num, TRUE);

		else										// If the input is the parenthesis
			switch (sent[cnt]) {
			case '(':
			case '[':
			case '<':
				Push(sp, sent[cnt++]), Push(num, FALSE);	// If left parenthesis, push it
				cnt_par++;
				break;

			case ')':									// If ')', sum all elements until find '(' and push it
				if ((temp = CalAdd(sp, num)) == -1) {	// Mismatching case	
					free(sp), free(num);
					return -1;
				}

				Push(sp, temp), Push(num, TRUE);
				cnt++, cnt_par--;
				break;

			case ']':									// If ']', calculate minimum until find '[' and push it
				if ((temp = CalMin(sp, num)) == -1) {	// Mismatching case	
					free(sp), free(num);
					return -1;
				}

				Push(sp, temp), Push(num, TRUE);
				cnt++, cnt_par--;
				break;


			case '>':									// If '>', calculate Gcd until find '<' and push it
				if ((temp = CalGcd(sp, num)) == -1) {	// Mismatching case	
					free(sp), free(num);
					return -1;
				}

				Push(sp, temp), Push(num, TRUE);
				cnt++, cnt_par--;
				break;

			default:
				printf("Wrong Representation!\n");
				exit(-1);
			}
	}

	if (cnt_par != 0) {								// If parentesis does not matches, return -1	
		free(sp), free(num);
		return -1;
	}

	while (!IsEmpty(sp))							// Sum the all remaining values
		result += Peek(sp), Pop(sp);

	free(sp), free(num);
	return result;
}

// Function that calculates the sum in the parenthesis
int CalAdd(Stack* sp, Stack* num) {
	if (Peek(sp) == '(' && Peek(num) == FALSE) {	// If no number in parenthesis, return 1
		Pop(sp), Pop(num);
		return 1;
	}

	int result = 0;

	while (Peek(sp) != '(' || Peek(num) == TRUE) {	// sum all elements until find '('
		result += Peek(sp), Pop(sp), Pop(num);

		if (IsEmpty(sp))							// Parenthesis missmatching, return -1
			return -1;
	}

	Pop(sp), Pop(num);								// Pop the left Parenthesis
	return result;
}

// Function that calculates the minimum in the parenthesis
int CalMin(Stack* sp, Stack* num) {

	if (Peek(sp) == '[' && Peek(num) == FALSE) {
		Pop(sp), Pop(num);
		return 1;
	}
	int min = 10, temp;								// Firstly set min as 10 since no one digit number exceed 10

	while (Peek(sp) != '[' || Peek(num) == TRUE) {	// Calculate the minimum until find '['
		if (Peek(sp) < min)
			min = Peek(sp);
		Pop(sp), Pop(num);

		if (IsEmpty(sp))							// Parenthesis missmatching, return -1
			return -1;
	}

	Pop(sp), Pop(num);
	return min;
}

// Function that calculates the gcd in the parenthesis
int CalGcd(Stack* sp, Stack* num) {

	if (Peek(sp) == '<' && Peek(num) == FALSE) {
		Pop(sp), Pop(num);
		return 1;
	}

	int gcd;

	while (1) {
		gcd = Peek(sp), Pop(sp), Pop(num);

		if (IsEmpty(sp))							// Parenthesis missmatching, return -1
			return -1;

		if (Peek(sp) == '<' && Peek(num) == FALSE) {
			Pop(sp), Pop(num);
			break;
		}

		gcd = CalcTwoGcd(gcd, Peek(sp));			// Calculate the gcd of two numbers
		Pop(sp), Pop(num);

		Push(sp, gcd), Push(num, TRUE);				// Push the calculated gcd back to stack
	}
	return gcd;
}

// Function that calculates the gcd of two numbers by using Euclidean algorithm
int CalcTwoGcd(int num1, int num2) {
	int rem;

	while (num1 % num2 != 0) {
		rem = num1 % num2;
		num1 = num2;
		num2 = rem;
	}

	return num2;
}

// The function returns whether it is number or not
int to_num(int c) {
	return c - '0';
}

// The function returns the integer value corresponds to character
int is_num(int c) {
	if (c >= '0' && c <= '9')
		return TRUE;

	return FALSE;
}