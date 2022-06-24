/*================================================================================
* Written date : 2018.04.12
* Lastest revised date : 2018.04.12
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"

#define MAX_SIZE	100
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

// Problm 1. CheckPalindrome
int CheckPalindrome(LinkedList* list);

int main()
{
	P1_GeneralTest();

	/*P1_Test1();
	P1_Test2();
	P1_Test3();
	P1_Test4();*/

	return 0;
}

// Input the number from the user.
void P1_GeneralTest()
{
	int n, i, data;


	scanf("%d", &n);

	LinkedList list;
	InitList(&list);

	for (i = 0; i < n; i++) {
		// using scanf to skip whitespace characters
		scanf("%*[ \n\t]%c", &data);
		InsertLast(&list, data);
	}

	printf("%d", CheckPalindrome(&list));
	ClearList(&list);
}

// Example 1
void P1_Test1()
{	
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, 'M');
	InsertLast(&list, 'a');
	InsertLast(&list, 'd');
	InsertLast(&list, 'a');
	InsertLast(&list, 'm');
	InsertLast(&list, ',');
	InsertLast(&list, 'I');
	InsertLast(&list, '\'');
	InsertLast(&list, 'm');
	InsertLast(&list, 'A');
	InsertLast(&list, 'd');
	InsertLast(&list, 'a');
	InsertLast(&list, 'm');

	
	printf("%d", CheckPalindrome(&list)); // Result: 1
	ClearList(&list);
}

// Example 2
void P1_Test2()
{
	
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, 'D');
	InsertLast(&list, 'a');
	InsertLast(&list, 't');
	InsertLast(&list, 'a');
	InsertLast(&list, 'S');
	InsertLast(&list, 't');
	InsertLast(&list, 'r');
	InsertLast(&list, 'u');
	InsertLast(&list, 'c');
	InsertLast(&list, 't');
	InsertLast(&list, 'u');
	InsertLast(&list, 'r');
	InsertLast(&list, 'e');
	InsertLast(&list, 'i');
	InsertLast(&list, 's');
	InsertLast(&list, 'F');
	InsertLast(&list, 'u');
	InsertLast(&list, 'n');
	
	printf("%d", CheckPalindrome(&list)); // Result: 0
	ClearList(&list);
}

// Example 3 
void P1_Test3()
{
	
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, 'I');
	InsertLast(&list, 'd');
	InsertLast(&list, 'i');
	InsertLast(&list, 'd');
	InsertLast(&list, ',');
	InsertLast(&list, 'd');
	InsertLast(&list, 'i');
	InsertLast(&list, 'd');
	InsertLast(&list, 'I');
	InsertLast(&list, '?');

	printf("%d", CheckPalindrome(&list)); // Result: 0
	ClearList(&list);
}

// Example 4
void P1_Test4()
{
	int k = 6;
	
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, '!');
	InsertLast(&list, '1');
	InsertLast(&list, '?');

	printf("%d", CheckPalindrome(&list)); // Result: 1
	ClearList(&list);
}


// Problm 1. Check whether palindrom or not
int CheckPalindrome(LinkedList* list)
{
	char c_front, c_rear;
	
	while (list->len > 1) {
		c_front = ReadItem(list, 0);
		c_rear = ReadItem(list, list->len - 1);

		if (!isdigit(c_front) && !isalpha(c_front)) {
			RemoveFirst(list);
			continue;
		}

		if (!isdigit(c_rear) && !isalpha(c_rear)) {
			RemoveLast(list);
			continue;
		}

		if(isupper(c_front))
			c_front = tolower(c_front);
		
		if (isupper(c_rear))
			c_rear = tolower(c_rear);

		if (c_front != c_rear)
			return false;

		RemoveFirst(list);
		RemoveLast(list);
	}

	return true;
}
