/*================================================================================
* Written date : 2018.04.13
* Lastest revised date : 2018.04.13
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P4_GeneralTest();

// Examples
void P4_Test1();
void P4_Test2();
void P4_Test3();
void P4_Test4();

// Problm 4. Find the real password
void KeyLogger(LinkedList* list);

int main()
{
	P4_GeneralTest();

	/*P4_Test1();
	printf("\n");
	P4_Test2();
	printf("\n");
	P4_Test3();
	printf("\n");
	P4_Test4();
	printf("\n");*/
	
	return 0;
}

// Input the number from the user.
void P4_GeneralTest()
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

	KeyLogger(&list);
	PrintListChar(&list);
	ClearList(&list);
	
}

// Example 1
void P4_Test1()
{
	LinkedList list;
	InitList(&list);
	
	InsertLast(&list, '<');
	InsertLast(&list, '<');
	InsertLast(&list, 'B');
	InsertLast(&list, 'P');
	InsertLast(&list, '<');
	InsertLast(&list, 'A');
	InsertLast(&list, '+');
	InsertLast(&list, '>');
	InsertLast(&list, '>');
	InsertLast(&list, 'C');
	InsertLast(&list, 'd');
	InsertLast(&list, '-');
	
	KeyLogger(&list);
	PrintListChar(&list); // Result: B a P C
	ClearList(&list);
}

// Example 2
void P4_Test2()
{
	LinkedList list;
	InitList(&list);

	InsertLast(&list, 'a');
	InsertLast(&list, '6');
	InsertLast(&list, '+');
	InsertLast(&list, 'B');
	InsertLast(&list, '2');
	InsertLast(&list, 'C');
	InsertLast(&list, '+');
	InsertLast(&list, '5');
	InsertLast(&list, '<');
	InsertLast(&list, '<');
	InsertLast(&list, '-');
	InsertLast(&list, '-');
	InsertLast(&list, 'd');
	InsertLast(&list, '7');
	InsertLast(&list, '>');
	InsertLast(&list, '>');
	InsertLast(&list, 'E');
	InsertLast(&list, '8');


	KeyLogger(&list);
	PrintListChar(&list); // Result: a 6 d 7 c 5 E 8
	ClearList(&list);
}
// Example 3
void P4_Test3()
{
	LinkedList list;
	InitList(&list);

	InsertLast(&list, '-');
	InsertLast(&list, '-');
	InsertLast(&list, '<');
	InsertLast(&list, '>');
	InsertLast(&list, '>');
	InsertLast(&list, 'a');
	InsertLast(&list, '<');
	InsertLast(&list, 'b');
	InsertLast(&list, '>');
	InsertLast(&list, 'c');

	KeyLogger(&list);
	PrintListChar(&list); // Result: b a c
	ClearList(&list);
}
// Example 4
void P4_Test4()
{
	LinkedList list;
	InitList(&list);

	InsertLast(&list, 'p');
	InsertLast(&list, 'a');
	InsertLast(&list, 's');
	InsertLast(&list, 's');
	InsertLast(&list, 'w');
	InsertLast(&list, 'o');
	InsertLast(&list, 'r');
	InsertLast(&list, 'd');


	KeyLogger(&list);
	PrintListChar(&list); // Result: p a s s w o r d
	ClearList(&list);
}

// Problm 4. Find the real password
void KeyLogger(LinkedList* list)
{
	LinkedList klist;
	InitList(&klist);

	int pos = -1;
	char c, temp;

	while (!IsEmpty(list)) {
		c = ReadItem(list, 0);

		if (isalnum(c)) {
			pos++;
			InsertMiddle(&klist, pos, c);
		}

		else
			switch (c) {
			case'<':
				if (pos > -1)
					pos--;
				break;

			case '>':
				if (pos < klist.len - 1)
					pos++;
				break;

			case '+':	
				if (pos == -1)
					break;
				
				temp = ReadItem(&klist, pos);

				if(isupper(temp))
					ReplaceItem(&klist, pos, tolower(temp));

				else if (islower(temp))
					ReplaceItem(&klist, pos, toupper(temp));

				break;

			case '-':
				if (pos == -1)
					break;

				RemoveMiddle(&klist, pos);
				pos--;
				break;

			default:
				printf("Wrong Representation");
				exit(-1);
			}

		RemoveFirst(list);

	}// end of while

	PrintListChar(&klist);

}