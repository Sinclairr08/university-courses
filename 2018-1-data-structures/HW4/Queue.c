#include "Queue.h"
#include <stdlib.h>

// Make queue empty.
void InitQueue(Queue *pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

// Check whether queue is full.
bool IsFull(Queue *pqueue)
{
	return pqueue->front
		== (pqueue->rear + 1) % MAX_QUEUE;
}

// Check whether queue is empty.
bool IsEmpty(Queue *pqueue)
{
	return pqueue->front == pqueue->rear;
}

// Read the item at the front.
Data Peek(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1); //error: empty stack
	return pqueue->items[pqueue->front];
}

// Insert an item at the rear.
void EnQueue(Queue *pqueue, Data item)
{
	if (IsFull(pqueue))
		exit(1); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

// Delete an item at the front.
void DeQueue(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1); //error: empty stack
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}


