#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0
#define MAX_STACK 100

typedef int Data;
typedef struct {
	Data items[MAX_STACK];
	int top;
}Stack;

// Make stack empty.
void InitStack(Stack *pstack);

// Check whether stack is full.
int IsFull(Stack *pstack);

// Check whether stack is empty
int IsEmpty(Stack *pstack);

// Read the item at the top.
Data Peek(Stack *pstack);

// Insert an item at the top.
void Push(Stack *pstack, Data item);

// Remove the item at the top.
void Pop(Stack *pstack);


#endif