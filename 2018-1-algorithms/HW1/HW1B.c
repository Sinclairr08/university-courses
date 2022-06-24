/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementation of Octal Calculator
*
* Project name : HW1
* File names : 2014310407_HW1B.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.03.14 ~ 2018.03.16
* Lastest revised date : 2018.03.16
*
* Operation System : Windows 10
*
* Modification histroy :
* 1. 2018.03.16 (Lee Jun Hyuk)
*	1) use of %o, to simplify the code
* 2. 2018.04.04 (Lee Jun Hyuk)
*	1) modify to follow stdin & stdout
*
* ==================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
	int stor[MAX];	// since input length is at most 200 byte, stack can contain at most 50 numbers.(Each number's length is 4)
	int top;
} STACK;

STACK* new_stack();
void delete_stack(STACK* s);

int pop(STACK* s);
void push(STACK* s, int num);

inline int to_num(char c);
inline int is_num(char c);
int to_dec(char oct[]);
int calc(int fir, int sec, char op);

int main() {
	char c;
	char temp[4];
	int cnt = 0;
	int fir, sec;
	
	STACK* sp = new_stack();					// make the stack

	while ((c = getchar()) != '\n') {			// Recieve the input until the input is "enter"(i,e, \n)
		if (is_num(c)) {
			temp[cnt++] = c;					// In the case when input is number, store it at the temp

			if (cnt == 4) {						// When four inputs are full
				push(sp, to_dec(temp));			// Change the octal input to decimal and push it
				cnt = 0;
			}
		}

		else if (isblank(c))					// Ignore the blank
			;

		else 	
			switch (c) {
			case '+':							// Case when the input is an operator
			case '-':
			case '*':
			case '/':
			case '%':
				sec = pop(sp);					// Firstly popped one is the later operand
				fir = pop(sp);
				push(sp, calc(fir, sec, c));
				break;

			default:							// If the input is neither number nor operator, give the error message
				printf("Wrong Input\n");
				exit(-1);
			}
	}

	printf("%0.4o",pop(sp));					// Print the result as a octal representation
	
	delete_stack(sp);							// Free the stack
	return 0;
}

// Initializing stack
STACK* new_stack() {
	STACK* s = malloc(sizeof(STACK));
	s->top = -1;

	return s;
}

// Deleting stack
void delete_stack(STACK* s) {
	free(s);
}

// pops the highest element of the stack
int pop(STACK* s) {
	if (s->top == -1) {
		printf("Stack is empty!");
		exit(-1);
	}
	
	return s->stor[(s->top)--];
}

// pushes the element to the stack
void push(STACK* s, int num) {
	if (s->top == MAX - 1) {
		printf("Stack is full!");
		exit(-1);
	}

	s->stor[++(s->top)] = num;
	return;
}

// Change octal number (character) array to decimal number
int to_dec(char oct[]) {
	int result = 0;
	int temp;

	for (int i = 0; i < 4; i++) {
		temp = to_num(oct[3 - i]);
		for (int j = 0; j < i; j++)	
			temp *= 8;	
		result += temp;
	}

	return result;
}

/*
 * Calculate the given numbers and operation
 * In the place of 'op', operation must be placed.
*/
int calc(int fir, int sec, char op) {
	int num;

	switch (op) {
	case '+':
		num = fir + sec;
		break;
	case '-':
		num = fir - sec;
		break;
	case '*':
		num = fir * sec;
		break;
	case '/':
		num = fir / sec;
		break;
	case '%':
		num = fir % sec;
		break;
	}

	num %= 4096;			// 4096 = 8^4, to delete the exceeding value

	return num;
}

// change given character to integer number
inline int to_num(char c) {
	return c - '0';
}

// check whether given char is number or not
inline int is_num(char c) {
	if ((c >= '0') && (c <= '9'))
		return 1;
	else
		return 0;
}
