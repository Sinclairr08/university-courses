/*================================================================================
* Written date : 2018.04.03
* Lastest revised date : 2018.04.03
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

// Input the number from the user.
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();


// Problem 5. The Number of SOS Signals
int NumOfSignals(int num, int *arr);


int main()
{
	P5_GeneralTest();

	//P5_Test1();
	//P5_Test2();
	//P5_Test3();
	//P5_Test4();

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
{
	int n;
	scanf("%d", &n);

	int* arr = (int *)malloc(sizeof(int)* n);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	printf("%d\n", NumOfSignals(n, arr));

	free(arr);
}

void P5_Test1()
{
	int n = 3;
	int arr[3] = { 2, 4, 1 };


	printf("%d\n", NumOfSignals(n, arr));	// Result: 2
}

void P5_Test2()
{
	int n = 5;
	int arr[5] = { 1, 1, 2, 1, 1 };


	printf("%d\n", NumOfSignals(n, arr));	// Result:6
}

void P5_Test3()
{
	int n = 8;
	int arr[8] = { 2, 8, 5, 6, 3, 4, 9, 7 };


	printf("%d\n", NumOfSignals(n, arr));	// Result: 11
}

void P5_Test4()
{
	int n = 5;
	int arr[5] = {3, 2, 2, 2, 2};


	printf("%d\n", NumOfSignals(n, arr));	// Result: 10
}


// Problem 5. The Number of SOS Signals
int NumOfSignals(int num, int *arr)
{
	Stack* sp = (Stack*)malloc(sizeof(Stack));
	InitStack(sp);
	int i, j;
	int cnt = 0;									// Total number of signals

	for (i = 0; i < num - 1; i++) {					// From first to N-1 th building

		for (j = i + 1; j < num; j++) {				// Check the all right buildings from the ith building

			if (arr[j] > arr[i]) {					// If one find the higher building, then stops for ith building
				cnt++;
				break;
			}

			// If stack is empty or find the higher building than the maximum until now, then we can send a signal
			if (IsEmpty(sp) || Peek(sp) <= arr[j]) {	
				Push(sp, arr[j]);				// Push the height of building. The top of stack always contains the maximum until now
				cnt++;
			}

		}	
		InitStack(sp);							// Every end of ith building, Initialize the stack 

	}
	free(sp);
	return cnt;
}