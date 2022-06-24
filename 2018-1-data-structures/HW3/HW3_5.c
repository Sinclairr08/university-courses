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
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();


// Problm 5. Calculating Two Numbers
void CalculateTwoLists(LinkedList* num1, LinkedList* num2, LinkedList* result, char op);

int main()
{
	P5_GeneralTest();

	/*P5_Test1();
	printf("\n");
	P5_Test2();
	printf("\n");
	P5_Test3();
	printf("\n");
	P5_Test4();
	printf("\n");*/

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
{
	int n1, n2, i, data, op;
	
	LinkedList num1;
	LinkedList num2;
	LinkedList result;

	InitList(&num1);
	InitList(&num2);
	InitList(&result);
	
	// number 1
	scanf("%d", &n1);	
	for (i = 0; i < n1; i++) {
		scanf("%d", &data);
		InsertLast(&num1, data);	
	}

	// number 2
	scanf("%d", &n2);
	for (i = 0; i < n2; i++) {
		scanf("%d", &data);
		InsertLast(&num2, data);	
	}
	
	// operation
	scanf("%*[ \n\t]%c", &op);

	CalculateTwoLists(&num1, &num2, &result, op);

	if(result.len == 0) 
		PrintListInt(&num1); // in place
	else
		PrintListInt(&result);

	ClearList(&result);
	ClearList(&num1);
	ClearList(&num2);
}

// Example 1
void P5_Test1()
{
	int n1, n2, i, data, op;

	LinkedList num1;
	LinkedList num2;
	LinkedList result;

	InitList(&num1);
	InitList(&num2);
	InitList(&result);

	InsertLast(&num1, 1);
	InsertLast(&num1, 8);
	InsertLast(&num1, 2);
	InsertLast(&num1, 4);

	op = '+';

	InsertLast(&num2, 3);
	InsertLast(&num2, 2);

	CalculateTwoLists(&num1, &num2, &result, op);
	if (result.len == 0)
		PrintListInt(&num1); // in place
	else
		PrintListInt(&result);
	
	ClearList(&result);
	ClearList(&num1);
	ClearList(&num2);
}

// Example 2
void P5_Test2()
{
	int n1, n2, i, data, op;

	LinkedList num1;
	LinkedList num2;
	LinkedList result;

	InitList(&num1);
	InitList(&num2);
	InitList(&result);

	InsertLast(&num1, 1);
	InsertLast(&num1, 0);

	op = '-';

	InsertLast(&num2, 1);
	InsertLast(&num2, 0);

	CalculateTwoLists(&num1, &num2, &result, op);

	if (result.len == 0)
		PrintListInt(&num1); // in place
	else
		PrintListInt(&result);

	ClearList(&result);
	ClearList(&num1);
	ClearList(&num2);
}


// Example 3
void P5_Test3()
{
	int n1, n2, i, data, op;

	LinkedList num1;
	LinkedList num2;
	LinkedList result;

	InitList(&num1);
	InitList(&num2);
	InitList(&result);

	InsertLast(&num1, 9);
	InsertLast(&num1, 9);

	op = '+';

	InsertLast(&num2, 9);
	InsertLast(&num2, 9);

	CalculateTwoLists(&num1, &num2, &result, op);

	if (result.len == 0)
		PrintListInt(&num1); // in place
	else
		PrintListInt(&result);

	ClearList(&result);
	ClearList(&num1);
	ClearList(&num2);
}

// Example 4
void P5_Test4()
{
	int n1, n2, i, data, op;

	LinkedList num1;
	LinkedList num2;
	LinkedList result;

	InitList(&num1);
	InitList(&num2);
	InitList(&result);

	InsertLast(&num1, 1);
	InsertLast(&num1, 2);

	op = '-';

	InsertLast(&num2, 3);

	CalculateTwoLists(&num1, &num2, &result, op);

	if (result.len == 0)
		PrintListInt(&num1); // in place
	else
		PrintListInt(&result);

	ClearList(&result);
	ClearList(&num1);
	ClearList(&num2);
}

// Problm 5. Multipyinging Two Numbers
void CalculateTwoLists(LinkedList* num1, LinkedList* num2, LinkedList* result, char op)
{
	int val1, val2;
	int digit = 0;
	
	if (op == '+') {
		
		while (1) {
			
			if (!IsEmpty(num1)) {
				val1 = ReadItem(num1, num1->len - 1);
				RemoveLast(num1);
			}

			else
				val1 = 0;

			if (!IsEmpty(num2)) {
				val2 = ReadItem(num2, num2->len - 1);
				RemoveLast(num2);
			}

			else
				val2 = 0;
			
			if (val1 + val2 >= 10) {
				InsertFirst(result, val1 + val2 - 10 + digit);
				digit = 1;
			}

			else{
				InsertFirst(result, val1 + val2 + digit);
				digit = 0;
			}


			if (IsEmpty(num1) && IsEmpty(num2)) {
				if(digit == 1)
					InsertFirst(result,digit);
				break;
			}

		}// end while

	}// end if, '+'

	if (op == '-') {

		while (1) {

			if (!IsEmpty(num1)) {
				val1 = ReadItem(num1, num1->len - 1);
				RemoveLast(num1);
			}

			else
				val1 = 0;

			if (!IsEmpty(num2)) {
				val2 = ReadItem(num2, num2->len - 1);
				RemoveLast(num2);
			}

			else
				val2 = 0;

			if (val1 - val2 < 0) {
				InsertFirst(result, val1 - val2 + 10 + digit);
				digit = -1;
			}

			else {
				InsertFirst(result, val1 - val2 + digit);
				digit = 0;
			}

			if (IsEmpty(num1) && IsEmpty(num2))
				break;

		}// end while

	}// end if, '-'

	while (ReadItem(result, 0) == 0 && result->len > 1)
		RemoveFirst(result);

}