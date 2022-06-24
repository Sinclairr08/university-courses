/*================================================================================
* Written date : 2018.05.19
* Lastest revised date : 2018.05.19
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// Write your student id, name, and discusser.
// StudentID: 20141310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P2_GeneralTest();

// Examples
void P2_Test1();
void P2_Test2();
void P2_Test3();
void P2_Test4();


// Problm 2. Finding Top-k Smallest Elements
int FindingSmallestElements(Heap* heap, int** arr, int k, int m);

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
	Heap heap;
	int k = 3;
	int m = 4;
	int i, j;

	InitHeap(&heap);

	scanf("%d %d", &k, &m);

	int** arr = (int **)malloc(sizeof(int*)* k);
	for (i = 0; i < k; i++)
		arr[i] = (int *)malloc(sizeof(int)* m);

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("%d\n", FindingSmallestElements(&heap, arr, k, m));

	while (!IsEmpty(&heap))
		Delete(&heap);

	for (i = 0; i < k; i++)
		free(arr[i]);
	free(arr);

}

// Example 1
void P2_Test1()
{
	Heap heap;
	int k = 3;
	int m = 4;
	int i;

	InitHeap(&heap);

	int** arr = (int **)malloc(sizeof(int*)* k);
	for (i = 0; i < k; i++)
		arr[i] = (int *)malloc(sizeof(int)* m);

	arr[0][0] = 7, arr[0][1] = 4, arr[0][2] = 3, arr[0][3] = 2;
	arr[1][0] = 9, arr[1][1] = 8, arr[1][2] = 6, arr[1][3] = 5;
	arr[2][0] = 6, arr[2][1] = 3, arr[2][2] = 2, arr[2][3] = 1;

	printf("%d\n", FindingSmallestElements(&heap, arr, k, m));		// Result: 5

	while (!IsEmpty(&heap))
		Delete(&heap);
	for (i = 0; i < k; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P2_Test2()
{
	Heap heap;
	int k = 2;
	int m = 5;
	int i;

	InitHeap(&heap);

	int** arr = (int **)malloc(sizeof(int*)* k);
	for (i = 0; i < k; i++)
		arr[i] = (int *)malloc(sizeof(int)* m);

	arr[0][0] = 11, arr[0][1] = 10, arr[0][2] = 7, arr[0][3] = 3, arr[0][4] = 2;
	arr[1][0] = 19, arr[1][1] = 8, arr[1][2] = 6, arr[1][3] = 5, arr[1][4] = 4;

	printf("%d\n", FindingSmallestElements(&heap, arr, k, m));		// Result: 5

	while (!IsEmpty(&heap))
		Delete(&heap);
	for (i = 0; i < k; i++)
		free(arr[i]);
	free(arr);
}
// Example 3
void P2_Test3()
{
	Heap heap;
	int k = 4;
	int m = 4;
	int i;

	InitHeap(&heap);

	int** arr = (int **)malloc(sizeof(int*)* k);
	for (i = 0; i < k; i++)
		arr[i] = (int *)malloc(sizeof(int)* m);

	arr[0][0] = 8, arr[0][1] = 4, arr[0][2] = 3, arr[0][3] = 2;
	arr[1][0] = 9, arr[1][1] = 8, arr[1][2] = 5, arr[1][3] = 4;
	arr[2][0] = 7, arr[2][1] = 6, arr[2][2] = 5, arr[2][3] = 2;
	arr[3][0] = 6, arr[3][1] = 3, arr[3][2] = 2, arr[3][3] = 1;

	printf("%d\n", FindingSmallestElements(&heap, arr, k, m));		// Result: 7

	while (!IsEmpty(&heap))
		Delete(&heap);
	for (i = 0; i < k; i++)
		free(arr[i]);
	free(arr);
}
// Example 4
void P2_Test4()
{
	Heap heap;
	int k = 4;
	int m = 4;
	int i;

	InitHeap(&heap);

	int** arr = (int **)malloc(sizeof(int*)* k);
	for (i = 0; i < k; i++)
		arr[i] = (int *)malloc(sizeof(int)* m);

	arr[0][0] = 4, arr[0][1] = 3, arr[0][2] = 2, arr[0][3] = 1;
	arr[1][0] = 4, arr[1][1] = 3, arr[1][2] = 2, arr[1][3] = 1;
	arr[2][0] = 4, arr[2][1] = 3, arr[2][2] = 2, arr[2][3] = 1;
	arr[3][0] = 4, arr[3][1] = 3, arr[3][2] = 2, arr[3][3] = 1;

	printf("%d\n", FindingSmallestElements(&heap, arr, k, m));		// Result: 4

	while (!IsEmpty(&heap))
		Delete(&heap);
	for (i = 0; i < k; i++)
		free(arr[i]);
	free(arr);
}


// Problm 2. Finding Top-k Smallest Elements
int FindingSmallestElements(Heap* heap, int** arr, int k, int m)
{
	int sum = 0;
	int i, j;

	for (i = 0; i < k; i++)
		for (j = 0; j < m; j++)
			Insert(heap, arr[i][j], -arr[i][j]);

	for (i = 0; i < k; i++)
		sum += Delete(heap);

	return sum;
	
}