/*================================================================================
* Written date : 2018.06.13
* Lastest revised date : 2018.06.17
* ==================================================================================*/

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX 100000

#define Parent(n) ((n)/(2))
#define L_Child(n) ((2)*(n))
#define R_Child(n) (((2)*(n)) + (1))

#define swap(a, b, temp) do { \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)

typedef struct
{
	int key[MAX + 1];
	int size;
}Heap;

int compare(const void *a, const void* b);

void Bubblesort(const int* arr, int size);
void Selectionsort(const int* arr, int size);
void Insertionsort(const int* arr, int size);
void Shellsort(const int* arr, int size);
void Mergesort(const int* arr, int size);
void ItvMergesort(const int* arr, int size);
void Heapsort(const int* arr, int size);
void RandQuicksort(const int* arr, int size);
void Quicksort(const int* arr, int size);

void QuickSort_R(int* arr, int left, int right, long long * comp);
int Partition(int* arr, int left, int right, long long * comp);
void QuickSort_Rand_R(int* arr, int left, int right, long long * comp);
int Partition_Rand(int* arr, int left, int right, long long * comp);
long long IncInsertionSort(int* arr, int first, int last, int diff);
void MergeSort_R(int* arr, int left, int right, long long* comp);
void Merge(int* arr, int left, int middle, int right, long long* comp);

void Max_heapify(Heap* heap, int index, long long* comp);

int main() {
	int* arr1 = (int*)malloc(sizeof(int) * MAX);
	int i;

	srand(time(NULL));

	for(i = 0; i < MAX; i++)
	{
		arr1[i] = (rand() * rand());
	}

	printf("Randomized\n\n");
		
	Bubblesort(arr1, MAX);
	Selectionsort(arr1, MAX);
	Insertionsort(arr1, MAX);
	Shellsort(arr1, MAX);
	Mergesort(arr1, MAX);
	ItvMergesort(arr1, MAX);
	Heapsort(arr1, MAX);
	RandQuicksort(arr1, MAX);
	Quicksort(arr1, MAX);

	printf("\nSorted\n\n");

	/* Library function */
	qsort(arr1, MAX, sizeof(int), compare);

	Bubblesort(arr1, MAX);
	Selectionsort(arr1, MAX);
	Insertionsort(arr1, MAX);
	Shellsort(arr1, MAX);
	Mergesort(arr1, MAX);
	ItvMergesort(arr1, MAX);
	Heapsort(arr1, MAX);
	RandQuicksort(arr1, MAX);
	Quicksort(arr1, MAX);

	free(arr1);

	return 0;
}


int compare(const void *a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return 1;

	if (*(int*)a > *(int*)b)
		return -1;

	return 0;
}

void Bubblesort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(int)*size);

	int i, j, temp = 0;
	long long num_comp = 0;

	printf("Bubble Sort\n");

	clock_t start, end;

	start = clock();

	for (j = size - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			num_comp++;
			if (sarr[i] > sarr[i + 1])
				swap(sarr[i], sarr[i + 1], temp);
		}
	}
	
	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}


void Selectionsort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(int)*size);

	int i, j, min, temp = 0;
	long long num_comp = 0;

	printf("Selection Sort\n");

	clock_t start, end;

	start = clock();

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			num_comp++;
			if (sarr[j] < sarr[min])
				min = j;
		}

		swap(sarr[i], sarr[min], temp);
	}

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	
	free(sarr);
}

void Quicksort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(int)*size);

	int temp = 0;
	long long num_comp = 0;

	printf("Quick Sort\n");

	clock_t start, end;

	start = clock();

	QuickSort_R(sarr, 0, MAX - 1, &num_comp);

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

void QuickSort_R(int* arr, int left, int right, long long * comp)
{
	if (left < right)
	{
		int middle = Partition(arr, left, right, comp);
		QuickSort_R(arr, left, middle - 1, comp);
		QuickSort_R(arr, middle + 1, right, comp);
	}
}

// Partition
int Partition(int* arr, int left, int right, long long* comp) {
	int ind1 = left, ind2 = left + 1, piv = left;
	int temp = 0;

	while (ind2 <= right)
	{
		(*comp)++;
		if (arr[piv] <= arr[ind2])
			ind2++;

		else
		{
			++ind1;
			swap(arr[ind1], arr[ind2], temp);
			ind2++;
		}

	}// end while

	swap(arr[piv], arr[ind1], temp);
	return ind1;
}

void Insertionsort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(int)*size);

	int i, j, piv, temp = 0;
	long long num_comp = 0;

	printf("Insertion Sort\n");

	clock_t start, end;

	start = clock();

	for (i = 1; i < size; i++)
	{
		j = i - 1;
		piv = sarr[i];
		
		num_comp++;
		while (piv < sarr[j] && j >= 0)
		{
			num_comp++;
			sarr[j + 1] = sarr[j];
			j--;
		}

		sarr[j + 1] = piv;
	}

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

void Shellsort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(arr) * size);

	int i, j;
	long long num_comp = 0;

	printf("Shell Sort\n");

	clock_t start, end;

	start = clock();

	for (j = size / 2; j > 0; j /= 2)
	{
		if (j % 2 == 0)
			j++;

		for (i = 0; i < j; i++)
			num_comp += IncInsertionSort(sarr, i, size, j);
	}

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

long long IncInsertionSort(int* arr, int first, int last, int diff)
{
	int i, j, piv;
	long long num_comp = 0;

	for (i = first + diff; i < last; i += diff)
	{
		piv = arr[i];
		j = i - diff;

		num_comp++;
		while (piv < arr[j] && j >= 0)
		{
			num_comp++;
			arr[j + diff] = arr[j];
			j -= diff;
		}

		arr[j + diff] = piv;

	}

	return num_comp;
}

void Mergesort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(arr) * size);

	long long num_comp = 0;

	printf("Merge Sort\n");

	clock_t start, end;

	start = clock();

	MergeSort_R(sarr, 0, size - 1, &num_comp);

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

void MergeSort_R(int* arr, int left, int right,long long* comp)
{
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort_R(arr, left, middle, comp);
		MergeSort_R(arr, middle + 1, right, comp);
		Merge(arr, left, middle, right, comp);
	}
}

void Merge(int* arr, int left, int middle, int right, long long* comp)
{
	int size_1 = middle - left + 1;
	int size_2 = right - middle;

	int cnt_1, cnt_2;

	int* larr = (int*)malloc(sizeof(int) * (size_1 + 1));
	int* rarr = (int*)malloc(sizeof(int) * (size_2 + 1));

	for (cnt_1 = 0; cnt_1 < size_1; cnt_1++)
		larr[cnt_1] = arr[left + cnt_1];

	for (cnt_2 = 0; cnt_2 < size_2; cnt_2++)
		rarr[cnt_2] = arr[middle + 1 + cnt_2];

	larr[cnt_1] = rarr[cnt_2] = INT_MAX;
	cnt_1 = cnt_2 = 0;

	for (int cnt = left; cnt <= right; cnt++)
	{
		(*comp)++;
		if (larr[cnt_1] <= rarr[cnt_2])
			arr[cnt] = larr[cnt_1++];
		else
			arr[cnt] = rarr[cnt_2++];
	}

	free(larr), free(rarr);
}

void ItvMergesort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(arr) * size);

	int i, temp = 0;
	long long num_comp = 0;

	printf("Iterative Merge Sort\n");

	clock_t start, end;

	start = clock();

	for (i = 1; i <= size - 1; i *= 2)
	{
		for (int left_start = 0; left_start < size - 1; left_start += 2 * i)
		{
			int mid = min(left_start + i - 1, size - 1);
			int right_end = min(left_start + 2 * i - 1, size - 1);

			Merge(sarr, left_start, mid, right_end, &num_comp);
		}
	}

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

void Heapsort(const int* arr, int size)
{
	int i, temp = 0;
	long long num_comp = 0;

	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = size;

	printf("Heap Sort\n");

	clock_t start, end;

	start = clock();
		
	memcpy(&(heap->key[1]), arr, sizeof(arr) * size);

	for (i = Parent(heap->size); i >= 1; i--)
		Max_heapify(heap, i, &num_comp);

	while (heap->size > 1)
	{
		swap(heap->key[1], heap->key[heap->size], temp);
		heap->size--;
		Max_heapify(heap, 1, &num_comp);
	}

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(heap);
}


void Max_heapify(Heap* heap, int index, long long* comp)
{
	int temp = 0;
	int largest = index;
	
	(*comp)++;
	if (L_Child(index) <= heap->size && heap->key[index] < heap->key[L_Child(index)])
		largest = L_Child(index);

	(*comp)++;
	if (R_Child(index) <= heap->size && heap->key[largest] < heap->key[R_Child(index)])
		largest = R_Child(index);

	if (largest != index) {
		swap(heap->key[largest], heap->key[index], temp);
		Max_heapify(heap, largest, comp);
	}
}

void RandQuicksort(const int* arr, int size)
{
	int* sarr = malloc(sizeof(int)*size);
	memcpy(sarr, arr, sizeof(int)*size);

	int temp = 0;
	long long num_comp = 0;

	printf("Randomized Quick Sort\n");

	clock_t start, end;

	start = clock();

	QuickSort_Rand_R(sarr, 0, MAX - 1, &num_comp);

	end = clock();

	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("Comp : %lld\n\n", num_comp);

	free(sarr);
}

void QuickSort_Rand_R(int* arr, int left, int right, long long * comp)
{
	if (left < right)
	{
		int middle = Partition_Rand(arr, left, right, comp);
		QuickSort_Rand_R(arr, left, middle - 1, comp);
		QuickSort_Rand_R(arr, middle + 1, right, comp);
	}
}

// Partition
int Partition_Rand(int* arr, int left, int right, long long* comp) {
	int ind1 = left, ind2 = left+1;
	int piv = (rand() % (right - left + 1)) + left;
	int temp = 0;

	swap(arr[ind1], arr[piv], temp);
	piv = ind1;

	while (ind2 <= right)
	{
		(*comp)++;
		if (arr[piv] <= arr[ind2])
			ind2++;

		else
		{
			++ind1;
			swap(arr[ind1], arr[ind2], temp);
			ind2++;
		}

	}// end while

	swap(arr[ind1], arr[piv], temp);
	return ind1;
}