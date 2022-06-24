/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementation of Octal Calculator
*
* Project name : HW1
* File names : 2014310407_HW1C.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.03.16
* Lastest revised date : 2018.03.16
*
* Operation System : Windows 10
*
* Modification histroy :
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS						// To use the scanf function
#define MAX 50
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>									// To use the INT_MIN in merge sort

int to_dec(char hex[]);

inline int to_num(char c);
inline int is_num(char c);

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);

void InsertionSort(int arr[], int size);

int main() {
	char c;
	char temp[4];
	int cnt1 = 0, cnt2 = 0;
	int sort_dec;									// Determine the type of the sort
	int data[MAX];

	scanf("%d", &sort_dec);

	while ((c = getchar()) != '\n') {				// Recieve the input until the input is "enter"(i,e, \n)
		if (is_num(c)) {
			temp[cnt1++] = c;						// In the case when input is number, store it at the temp

			if (cnt1 == 4) {						// When four input is full
				data[cnt2++] = to_dec(temp);		// Change the hexadecimal input to decimal and store it at the data array
				cnt1 = 0;
			}

		}

		else if (isblank(c))						// Ignore the blank
			;

		else {
			printf("Wrong Input\n");
			exit(-1);
		}

	}

	if (sort_dec == 1)								// When the first input is 1 -> insertion sort
		InsertionSort(data, cnt2);

	else if (sort_dec == 2)							// When the first input is 2 -> merge sort
		MergeSort(data, 0, cnt2 - 1);


	for (int i = 0; i < cnt2; i++)
		printf("%-0.4X ", data[i]);					// Print the sorted data

	printf("\n");
	return 0;
}

// Change hexadecimal number (character) array to decimal number
int to_dec(char hex[]) {
	int result = 0;
	int temp;

	for (int i = 0; i < 4; i++) {
		temp = to_num(hex[3 - i]);
		for (int j = 0; j < i; j++)
			temp *= 16;
		result += temp;
	}

	return result;
}

// Using Recursion, sort the elements
void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;

		MergeSort(arr, left, middle);
		MergeSort(arr, middle + 1, right);
		Merge(arr, left, middle, right);
	}

}

void Merge(int arr[], int left, int middle, int right) {
	int size_1 = middle - left + 1;
	int size_2 = right - middle;

	int* larr = malloc(sizeof(int) * (size_1 + 1));			// For the efficient algorithm, INT_MIN is stored at the end of the array
	int* rarr = malloc(sizeof(int) * (size_2 + 1));			// So allocate one more place

	int cnt;
	int i = 0, j = 0;

	
	for (cnt = 0; cnt < size_1; cnt++)
		larr[cnt] = arr[left + cnt];				// Seperate the array

	for (cnt = 0; cnt < size_2; cnt++)
		rarr[cnt] = arr[middle + 1 + cnt];

	larr[size_1] = rarr[size_2] = INT_MIN;			// INT_MIN is the smallest number in the int

	for (cnt = left; cnt <= right; cnt++) {
		if (larr[i] >= rarr[j])
			arr[cnt] = larr[i++];
		else
			arr[cnt] = rarr[j++];
	}

	free(larr);										// Free the memory
	free(rarr);
}

void InsertionSort(int arr[], int size) {
	int key;
	int i, j;

	for (i = 1; i < size; i++) {					// Insertion of the first element is unnecessary, so start from 1
		key = arr[i];								// Save the element which will be inserted at key

		j = i - 1;
		while (j >= 0 && arr[j] < key) {			// Shift all the elements to the right which is smaller than key
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;							// Insert the key
	}
}

// change given hexadecimal character to integer number
inline int to_num(char c) {
	if ((c >= '0') && (c <= '9'))
		return c - '0';

	if ((c >= 'A') && (c <= 'F'))
		return c - 'A' + 10;
}

// check whether given char is hexadecimal number or not
inline int is_num(char c) {
	if ((c >= '0') && (c <= '9'))
		return 1;

	if ((c >= 'A') && (c <= 'F'))
		return 1;

	else
		return 0;
}