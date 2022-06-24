/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementing heap and heapsort
*
* Project name : HW2
* File names : 2014310407_HW2B.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.04.03
* Lastest revised date : 2018.04.03
*
* Operation System : Windows 10
*
* Modification histroy :
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 101

#define TRUE 1
#define FALSE 0

void Min_Heapify(int* heap, int node, int size, int X);

int is_num(char c);
int to_num(char c);

int X_i_child(int node, int X, int i);
int X_Parent(int node, int X);

void printheap(int* heap, int size);

int main() {
	int tr_size, heap_size = 0;						// Size of tree(how many childern at the tree), Size of heap
	int* heap = (int*)malloc(sizeof(int)*MAX_LEN);
	char c;
	int temp_num = 0;
	int i, swap;

	scanf("%d", &tr_size);
	getchar();										// To remove the '\n' in the buffer

	// Recieve the inputs until '\n'
	while ((c = getchar()) != '\n') {				
		if (c == ' ') {
			heap[++heap_size] = temp_num;
			temp_num = 0;
		}

		else if (is_num(c))
			temp_num = temp_num * 10 + to_num(c);	// To treat the consecutive number input as a decimal number

		else {
			printf("Wrong representation!\n");
			exit(-1);
		}

	}

	if (temp_num != 0)								// When number is remained
		heap[++heap_size] = temp_num;

	// Build a heap
	for (i = X_Parent(heap_size, tr_size); i >= 1; i--)
		Min_Heapify(heap, i, heap_size, tr_size);

	int total_size = heap_size;						// Record the input size
	printheap(heap, total_size);

	// Heapsort and print it until heap contains one element
	while (heap_size >= 2) {
		swap = heap[1];								// Swap first and last element of heap
		heap[1] = heap[heap_size];
		heap[heap_size] = swap;

		heap_size--;								// Reduce the heap size and apply min_heapify at the root node
		Min_Heapify(heap, 1, heap_size, tr_size);

		printheap(heap, total_size);				// Print the heap and sorted array
	}

	free(heap);
}

/*
 * Make a min heap under given node.
 * Childern of given node should already be min heap to apply this.
 * Use recursion to the way for increasing the depth, until min heap is completed
 */
void Min_Heapify(int* heap, int node, int size, int X) {
	int min_index = node, min = heap[node];
	
	// Check all the child nodes, and find the minimum and its index
	for(int i = 0; i < X && X_i_child(node, X, i) <= size; i++)
		if (heap[X_i_child(node, X, i)] < min) {
			min = heap[X_i_child(node, X, i)];
			min_index = X_i_child(node, X, i);
		}

	if (min_index != node) {						// If there is the smaller number at child
		int temp;

		temp = heap[min_index];
		heap[min_index] = heap[node];
		heap[node] = temp;

		Min_Heapify(heap, min_index, size, X);		// Apply the min_heapify again at the changed node
	}

}

// Function returns index of i_th child of given node, in X-nary tree
int X_i_child(int node, int X, int i) {

	return X * (node - 1) + 2 + i;
}

// Function returns index of parent of given node, in X-nary tree
int X_Parent(int node, int X) {
	if (node <= 1) {
		printf("No Parent!\n");
		exit(-1);
	}

	return (node + (X - 2)) / X;
}

// Print all the elements in the heap(array)
void printheap(int* heap, int size) {
	for (int i = 1; i <= size; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

// Function returns whether given character is number or not
int is_num(char c) {
	if (c >= '0' && c <= '9')
		return TRUE;
	return FALSE;
}

// Function returns the integer value of corresponding character
int to_num(char c) {
	return c - '0';
}