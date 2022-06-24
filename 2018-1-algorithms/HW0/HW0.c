/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementing Merge Sort
*
* Project name : Pre_Workig
* File names : main.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.03.12
* Lastest revised date : 2018.03.12
*
* Operation System : Windows 10
* Used compiler : Visual Studio 2017
*
* Modification histroy : None
*
* ==================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#define int_MAX 2147483647

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);

int main() {
	int arr[30];
	int size;

	scanf("%d", &size);

	for (int cnt = 0; cnt < size; cnt++) {
		scanf("%d", &arr[cnt]);
	}

	MergeSort(arr, 0, size - 1);

	for (int cnt = 0; cnt < size; cnt++)
		printf("%d ", arr[cnt]);

	return 0;
}

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

	int* larr = malloc(sizeof(int) * (size_1 +1));
	int* rarr = malloc(sizeof(int) * (size_2 + 1));

	int cnt;
	int i = 0, j = 0;

	for (cnt = 0; cnt < size_1; cnt++)
		larr[cnt] = arr[left + cnt];

	for (cnt = 0; cnt < size_2; cnt++)
		rarr[cnt] = arr[middle + 1 + cnt];

	larr[size_1] = rarr[size_2] = int_MAX;

	for(cnt = left; cnt <= right; cnt++){
		if (larr[i] <= rarr[j])
			arr[cnt] = larr[i++];
		else
			arr[cnt] = rarr[j++];

	}

	free(larr);
	free(rarr);
}