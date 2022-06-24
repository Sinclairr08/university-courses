/*================================================================================
* Written date : 2018.04.12
* Lastest revised date : 2018.04.12
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P2_GeneralTest();

// Examples
void P2_Test1();
void P2_Test2();
void P2_Test3();
void P2_Test4();


// Problm 2. Swap Adjacent Two Blocks
void SwapTwoBlocks(LinkedList* list, int b_size);

int main()
{
	P2_GeneralTest();

	/*P2_Test1();
	printf("\n");
	P2_Test2();
	printf("\n");
	P2_Test3();
	printf("\n");
	P2_Test4();
	printf("\n");*/

	return 0;
}

// Input the number from the user.
void P2_GeneralTest()
{
	int i, n, b_size, data;
	scanf("%d", &n);
	
	LinkedList list;
	InitList(&list);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		InsertLast(&list, data);	
	}
	
	scanf("%d", &b_size);
	
	SwapTwoBlocks(&list, b_size);
	PrintListInt(&list);
	ClearList(&list);
	
}

// Example 1
void P2_Test1()
{
	int b_size = 3;
	
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, 45);
	InsertLast(&list, 24);
	InsertLast(&list, 12);
	InsertLast(&list, 43);
	InsertLast(&list, 51);
	InsertLast(&list, 99);
	
	SwapTwoBlocks(&list, b_size);
	PrintListInt(&list); // Result: 43 51 99 45 24 12
	ClearList(&list);

}

// Example 2
void P2_Test2()
{
	int b_size = 2;

	LinkedList list;
	InitList(&list);

	InsertLast(&list, 45);
	InsertLast(&list, 24);
	InsertLast(&list, 12);
	InsertLast(&list, 9);
	InsertLast(&list, 51);
	InsertLast(&list, 99);
	InsertLast(&list, 72);

	SwapTwoBlocks(&list, b_size);
	PrintListInt(&list); // Result: 12 9 45 24 51 99 72
	ClearList(&list);
}
// Example 3
void P2_Test3()
{
	int b_size = 1;

	LinkedList list;
	InitList(&list);

	InsertLast(&list, 45);
	InsertLast(&list, 24);
	InsertLast(&list, 12);
	InsertLast(&list, 43);
	InsertLast(&list, 51);
	InsertLast(&list, 99);
	InsertLast(&list, 82);
	InsertLast(&list, 10);
	InsertLast(&list, 35);

	SwapTwoBlocks(&list, b_size);
	PrintListInt(&list); // Result: 24 45 43 12 99 51 10 82 35
	ClearList(&list);
}
// Example 4
void P2_Test4()
{
	int b_size = 10;

	LinkedList list;
	InitList(&list);

	InsertLast(&list, 34);
	InsertLast(&list, 25);
	InsertLast(&list, 33);
	InsertLast(&list, 11);
	InsertLast(&list, 54);
	InsertLast(&list, 23);
	InsertLast(&list, 42);
	InsertLast(&list, 41);
	InsertLast(&list, 7);
	InsertLast(&list, 65);
	InsertLast(&list, 0);

	SwapTwoBlocks(&list, b_size);
	PrintListInt(&list); // Result: 34 25 33 11 54 23 42 41 7 65 0
	ClearList(&list);
}

// Problm 2. Swap Adjacent Two Blocks
void SwapTwoBlocks(LinkedList* list, int b_size)
{
	int cnt = (list->len) / (2 * b_size);
	int i, j;
	Node* node1 = list->head;
	Node* node2, *node3;
	Node* temp;

	for (i = 0; i < cnt; i++) {
		temp = node1->next;
		
		node2 = node1;
		for (j = 0; j < b_size; j++)
			node2 = node2->next;

		node3 = node2;
		for (j = 0; j < b_size; j++)
			node3 = node3->next;

		node1->next = node2->next;
		node2->next = node3->next;
		node3->next = temp;

		node1 = node2;
	}
}