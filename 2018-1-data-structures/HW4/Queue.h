#ifndef _QUEUE_H
#define _QUEUE_H

#include "BinaryTree.h"

#define MAX_QUEUE	100

typedef enum { false, true } bool; 

typedef BTreeNode* Data;

typedef struct {
	int front, rear;
	Data items[MAX_QUEUE];
} Queue;

// Make queue empty.
void InitQueue(Queue *pqueue);
// Check whether queue is full.
bool IsFull(Queue *pqueue);
// Check whether queue is empty.
bool IsEmpty(Queue *pqueue);

// Read the item at the front.
Data Peek(Queue *pqueue);
// Insert an item at the rear.
void EnQueue(Queue *pqueue, Data item);
// Delete an item at the front.
void DeQueue(Queue *pqueue);

#endif _QUEUE_H