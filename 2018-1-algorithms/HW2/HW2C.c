/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementing Radix & Counting sort
*
* Project name : HW2
* File names : 2014310407_HW2C.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.04.06
* Lastest revised date : 2018.04.06
*
* Operation System : Windows 10
*
* Modification histroy :
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void Radix_sort(int **arr, int digit, int size);
void printarr(int** arr, int size);

int is_num(char c);
int to_num(char c);

int main() {
	
	int i;

	int** stor = (int **)malloc(sizeof(int*)* 20);	// Number can be at most 20, so make 20 storage
	for (i = 0; i < 20; i++)
		stor[i] = (int *)malloc(sizeof(int)* 10);	// Each number has a 10  digit, so make 10 digit for every storage

	int cnt_num = 0, cnt_dig = 0;
	char c;

	// Recieve the inputs until '\n'
	while ((c = getchar()) != '\n') {
		if (is_num(c))
			stor[cnt_num][cnt_dig++] = to_num(c);	// store every one digit input at a one memory

		else if (c == ' ' && cnt_dig == 10) {		// If 10-digit is entered
			cnt_num++;								// Recieve the next number
			cnt_dig = 0;
		}

		else
			exit(-1);
	}

	if (cnt_dig == 10)
		cnt_num++;

	
	for (i = 9; i >= 0; i--) {						// From the lowest digit to highest digit
		Radix_sort(stor, i, cnt_num);				// Apply radix sort for every digit
		printarr(stor, cnt_num);
	}
	
	for (i = 0; i < 20; i++)
		free(stor[i]);
	free(stor);

	return 0;
}

// Print every number to a hexadecimal number
void printarr(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++)
			printf("%X", arr[i][j]);
		printf(" ");
	}
	printf("\n");
}

// Apply the counting sort at the ith digit of given numbers
void Radix_sort(int **arr, int digit, int size) {
	int** outarr = (int**)malloc(sizeof(int*) * size);	// The array of pointer(not 2d-array)
	int* auxarr = (int*)calloc(16, sizeof(int));		// Auxiliary memory, initialized to 0
	int i;

	// Increase the number of auxiliary array, corresponding index is same with the value of input
	for (i = 0; i < size; i++)
		auxarr[arr[i][digit]] += 1;

	// Make the auxiliary array's number as cumulative
	for (i = 1; i < 16; i++)
		auxarr[i] += auxarr[i - 1];

	// Store the address of the array of the input number, instead of the ith value itself.
	// This is required since want to shift the total number, not only single digit number
	for (i = size - 1; i >= 0; i--) {
		outarr[auxarr[arr[i][digit]] - 1] = arr[i];
		auxarr[arr[i][digit]] -= 1;
	}

	// Store the sorted value to a original array
	for (i = 0; i < size; i++)
		arr[i] = outarr[i];

	free(outarr);
	free(auxarr);

}

// Function returns whether given character is hexadecimal number or not
int is_num(char c) {
	if (c >= '0' && c <= '9')
		return TRUE;

	if (c >= 'A' && c <= 'F')
		return TRUE;

	return FALSE;
}

// Function returns the hexadecimal integer value of corresponding character
int to_num(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';

	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
}