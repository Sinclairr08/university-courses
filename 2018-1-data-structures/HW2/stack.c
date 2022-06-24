#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Make stack empty.
void InitStack(Stack *pstack)
{
	pstack->top = -1;
}

// Check whether stack is full.
int IsFull(Stack *pstack)
{
	if (pstack->top == MAX_STACK - 1) return TRUE;
	else return FALSE;
}

// Check whether stack is empty
int IsEmpty(Stack *pstack)
{
	if (pstack->top == -1) return TRUE;
	else return FALSE;
}

// Read the item at the top.
Data Peek(Stack *pstack)
{
	if (IsEmpty(pstack)) exit(-1);
	return pstack->items[pstack->top];
}

// Insert an item at the top.
void Push(Stack *pstack, Data item)
{
	if (IsFull(pstack)) exit(-1);
	pstack->items[++(pstack->top)] = item;
}


// Remove the item at the top.
void Pop(Stack *pstack)
{
	if (IsEmpty(pstack)) exit(-1);
	--(pstack->top);
}