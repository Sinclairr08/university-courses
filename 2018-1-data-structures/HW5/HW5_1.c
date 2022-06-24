/*================================================================================
* Written date : 2018.05.19
* Lastest revised date : 2018.05.19
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

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


// Problm 1. Number of Swap Operations
int NumOfSwap(Heap* heap, int* arr, int n);

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
	Heap heap;
	int n, i;

	InitHeap(&heap);

	scanf("%d", &n);

	int* arr = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < n; i++)	scanf("%d", &arr[i]);

	printf("%d\n", NumOfSwap(&heap, arr, n));

	while (!IsEmpty(&heap))
		Delete(&heap);
	free(arr);
}

// Example 1
void P1_Test1()
{
	Heap heap;
	int n = 3;

	InitHeap(&heap);

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 3, arr[1] = 1, arr[2] = 2;

	printf("%d\n", NumOfSwap(&heap, arr, n));	// Result: 0

	while (!IsEmpty(&heap))
		Delete(&heap);
	free(arr);
}

// Example 2
void P1_Test2()
{
	Heap heap;
	int n = 4;

	InitHeap(&heap);

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 4, arr[1] = 3, arr[2] = 2, arr[3] = 1;

	printf("%d\n", NumOfSwap(&heap, arr, n));	// Result: 1

	while (!IsEmpty(&heap))
		Delete(&heap);
	free(arr);
}
// Example 3
void P1_Test3()
{
	Heap heap;
	int n = 5;

	InitHeap(&heap);

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 5, arr[1] = 3, arr[2] = 4, arr[3] = 1, arr[4] = 2;

	printf("%d\n", NumOfSwap(&heap, arr, n));	// Result: 2

	while (!IsEmpty(&heap))
		Delete(&heap);
	free(arr);
}
// Example 4
void P1_Test4()
{
	Heap heap;
	int n = 5;

	InitHeap(&heap);

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 5, arr[1] = 4, arr[2] = 3, arr[3] = 2, arr[4] = 1;

	printf("%d\n", NumOfSwap(&heap, arr, n));	// Result: 4

	while (!IsEmpty(&heap))
		Delete(&heap);
	free(arr);
}


// Problm 1. Number of Swap Operations
int NumOfSwap(Heap* heap, int* arr, int n)
{
	int swap_num = 0;

	for (int i = 0; i < n; i++)
		Insert(heap, arr[i], arr[i]);

	HNode last;
	int parent, child;

	/* Do until when the element is not 1*/
	while (heap->num != 1)
	{
		last = heap->items[heap->num];
		parent = 1;

		while (child = GetHighPrioityChild(heap, parent))
		{
			if (last.priority < heap->items[child].priority)
			{
				heap->items[parent] = heap->items[child];
				parent = child;
				swap_num++;
			}
			else
				break;
		}

		heap->items[parent] = last;
		heap->num--;
	}

	return swap_num;

}