/*================================================================================
* Written date : 2018.04.13
* Lastest revised date : 2018.04.13
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
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();

// Problm 3. Discard Cards According to the rules
void DiscardCards(LinkedList* list);

int main()
{
	P3_GeneralTest();

	/*P3_Test1();
	printf("\n");
	P3_Test2();
	printf("\n");
	P3_Test3();
	printf("\n");
	P3_Test4();
	printf("\n");*/
	
	return 0;
}

// Input the number from the user.
void P3_GeneralTest()
{
	int n, i;
	scanf("%d", &n);
	
	LinkedList list;
	InitList(&list);
	
	for (i = 1; i <= n; i++) {
		InsertLast(&list, i);	
	}

	DiscardCards(&list);
	ClearList(&list);
}

// Example 1
void P3_Test1()
{
	int n, i;
	
	n = 4;

	LinkedList list;
	InitList(&list);

	for (i = 1; i <= n; i++) {
		InsertLast(&list, i);
	}

	DiscardCards(&list);
	ClearList(&list);
}

// Example 2
void P3_Test2()
{
	int n, i;
	
	n = 7;

	LinkedList list;
	InitList(&list);

	for (i = 1; i <= n; i++) {
		InsertLast(&list, i);
	}

	DiscardCards(&list);
	ClearList(&list);
}
// Example 3
void P3_Test3()
{
	int n, i;
	
	n = 1;

	LinkedList list;
	InitList(&list);

	for (i = 1; i <= n; i++) {
		InsertLast(&list, i);
	}

	DiscardCards(&list);
	ClearList(&list);
}
// Example 4
void P3_Test4()
{
	int n, i;
	
	n = 15;

	LinkedList list;
	InitList(&list);

	for (i = 1; i <= n; i++) {
		InsertLast(&list, i);
	}

	DiscardCards(&list);
	ClearList(&list);
}

// Problm 3. Reordering Multiples of k Position First
void DiscardCards(LinkedList* list)
{
	if (list->len == 1) {
		printf("%d ", ReadItem(list, 0));
		return;
	}

	int half, i;
	Node* front = list->head;
	Node* middle;
	Node* rear;
	Node* first;

	while (list->len > 2) {

		printf("%d ", ReadItem(list, 0));
		RemoveFirst(list);

		front = list->head;

		// Set the middle point
		middle = front;
		half = (list->len) / 2;
		for (i = 0; i < half; i++)
			middle = middle->next;

		// Set the rear point
		rear = middle;
		for (i = 0; i < list->len - half; i++)
			rear = rear->next;

		// Even case
		if (list->len % 2 == 0) {
			rear->next = front->next;
			front->next = middle->next;
			middle->next = NULL;
		}

		// Odd case
		else {
			first = front->next;

			rear->next = middle->next;
			front->next = middle->next->next;
			middle->next->next = first;
			middle->next = NULL;

		}
	}// end of while

	printf("%d ", ReadItem(list, 0));
	RemoveFirst(list);

	printf("%d ", ReadItem(list, 0));
}