/*================================================================================
* Written date : 2018.04.02
* Lastest revised date : 2018.04.10
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>												// added one
#include "stack.h"

#define MAX_LEN 100

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P4_GeneralTest();

// Examples
void P4_Test1();
void P4_Test2();
void P4_Test3();
void P4_Test4();


// Problm 4. Funny Calculator
int FunnyCalculator(char *sent);

int op_priority(char c);

int is_num(char c);
int to_num(char c);

int isprime(int num);
int Concat(int op_1, int op_2);
int get_digit(int num);

int main()
{
	P4_GeneralTest();

	//P4_Test1();
	//P4_Test2();
	//P4_Test3();
	//P4_Test4();

	return 0;
}

// Input the number from the user.
void P4_GeneralTest()
{
	char sent[MAX_LEN];
	scanf("%s", sent);        // User input
	fflush(stdin);

	printf("%d\n", FunnyCalculator(sent)); 
}

// Example 1
void P4_Test1()
{
	char sent[MAX_LEN] = "20-5*(2+1)";
	
	printf("%d\n", FunnyCalculator(sent)); // Result: 5
}

// Example 2
void P4_Test2()
{
	char sent[MAX_LEN] = "(~4|(4%4))|(4*4+(4+4)/4)";

	printf("%d\n", FunnyCalculator(sent)); // Result: 2018
}
// Example 3
void P4_Test3()
{
	char sent[MAX_LEN] = "(19|1-1)%(3|1)*4/(3-1)";

	printf("%d\n", FunnyCalculator(sent)); // Result: 8
}

// Example 4
void P4_Test4()
{
	char sent[MAX_LEN] = "~100|~(99*100)-3";

	printf("%d\n", FunnyCalculator(sent)); // Result: 19
}


// Problm 4. Funny Calculator
int FunnyCalculator(char *sent)
{
	Stack* sp = (Stack*)malloc(sizeof(Stack));					// Stack, firstly used to save the operators, for postfix
	InitStack(sp);
	
	char* temp = (char*)malloc(sizeof(char) * MAX_LEN);			// Character array which saves the postfix representation
	int* isnumber = (int*)malloc(sizeof(int) * MAX_LEN);		// Array which saves the information about data isnumber or not

	int i = 0, j = 0, num = 0;
	int num_cnt = FALSE;

	while (sent[i] != '\0') {
		if (is_num(sent[i])) {									// If it is a number
			num = num * 10 + to_num(sent[i++]);					// To save as a decimal number
			num_cnt = TRUE;
		}

		else {
			if (num_cnt) {										// If number is saved at num
				temp[j] = num, isnumber[j++] = TRUE;			// Save the number value at temp
				num = 0, num_cnt = FALSE;
			}

			if (!op_priority(sent[i]))					// If the input is neither number nor operator, ignore
				i++;

			else if (sent[i] == '(')					// If the input is the left parenthesis, Push it to a stack
				Push(sp, sent[i++]);

			else if (sent[i] == ')') {					// If the input is the right parenthesis
				while (Peek(sp) != '(') {
					temp[j] = Peek(sp), Pop(sp);		// Pop all the operators until finding the '('
					isnumber[j++] = FALSE;
				}

				Pop(sp);								// Pop the '('
				i++;
			}

			else {
				while (!IsEmpty(sp)) {
					// Pop all the operators in the stack until the input operator has larger priority than peeked one(or empty)
					if (op_priority(Peek(sp)) >= op_priority(sent[i])) {		
						temp[j] = Peek(sp), Pop(sp);
						isnumber[j++] = FALSE;
					}

					else
						break;
				}

				Push(sp, sent[i++]);					// Pushes the input operator
			}

		} // end of the case when input is not number

	} // end of while

	if (num_cnt)										// If the number is remained
		temp[j] = num, isnumber[j++] = TRUE;


	while (!IsEmpty(sp)) {								// Pop all operators until stack becomes empty
		temp[j] = Peek(sp), Pop(sp);
		isnumber[j++] = FALSE;
	}

	for (i = 0; i < j; i++)
		sent[i] = temp[i];
	sent[j] = '\0', isnumber[j] = FALSE;				// Add NULL character to remark the end
	

	free(temp);
	InitStack(sp);										// Stack, secondly used to save the numbers, for calculation

	int op_1, op_2;

	for (i = 0; sent[i] != '\0' || isnumber[i]; i++) {
		if (isnumber[i])
			Push(sp, sent[i]);							// If it is a number, push to the stack

		else											// If it is an operator, pops the elements from the stack and pushes the calculated value
			switch (sent[i]) {									
			case '+':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, op_1 + op_2);
				break;

			case '-':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, op_1 - op_2);
				break;

			case '*':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, op_1 * op_2);
				break;

			case '/':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, op_1 / op_2);
				break;

			case '%':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, op_1 % op_2);
				break;

			case '|':
				op_2 = Peek(sp), Pop(sp);
				op_1 = Peek(sp), Pop(sp);

				Push(sp, Concat(op_1, op_2));
				break;

			case '~':
				op_1 = Peek(sp), Pop(sp);

				Push(sp, isprime(op_1));
				break;

			default:
				exit(-1);

			}// end switch

	}// end for

	int result = Peek(sp);							// At the end, the last value at the stack is the result			

	free(isnumber);
	free(sp);

	return result;
}

/*
 * The function returns the priority of operators. Exceptionally, the parentesis are regarded as
 * the lowest priority since it is treated differently.
 * If argument is not operator, returns 0
 */
int op_priority(char c) {
	switch (c) {

	case '~':
		return 5;

	case '*':
	case '/':
	case '%':
		return 4;

	case '|':
		return 3;

	case '+':
	case '-':
		return 2;

	case '(':
	case ')':
		return 1;

	default:
		return 0;
	}
}

// If given number is prime, return 1, otherwise, return 2
int isprime(int num) {
	if (num == 1 || num == 0)
		return 2;

	if (num == 2)
		return 1;

	for (int div = 2; div < (int)ceil(sqrt(num)) + 1; div++)		// We only have to check until the sqrt of given number
		if (num % div == 0)
			return 2;

	return 1;
}

// The function returns the concatenation of the given number
int Concat(int op_1, int op_2) {
	int dig = get_digit(op_2);

	for (int i = 0; i < dig; i++)
		op_1 *= 10;

	return op_1 + op_2;
}

// The function returns the digit of the given number
int get_digit(int num) {
	int cnt = 0;

	do {
		num /= 10;
		cnt++;
	} while (num != 0);
		
	return cnt;

}

// The function returns whether it is number or not
int is_num(char c) {
	if (c >= '0' && c <= '9')
		return TRUE;
	return FALSE;
}

// The function returns the integer value corresponds to character
int to_num(char c) {
	return c - '0';
}