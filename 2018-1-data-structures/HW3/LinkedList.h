#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#define true 1
#define false 0

//typedef enum { false, true } bool;
typedef int Data;

typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
} LinkedList;

// Make a list empty.
void InitList(LinkedList* plist);
// Check whether the list is empty.
int IsEmpty(LinkedList* plist);

// Insert an item at the first position.
void InsertFirst(LinkedList* plist, Data item);
// Insert an item at the last position.
void InsertLast(LinkedList* plist, Data item);
// Insert an item at the k-th position.
void InsertMiddle(LinkedList* plist, int pos, Data item);

// Remove an item at the first position.
void RemoveFirst(LinkedList* plist);
// Remove an item at the last position.
void RemoveLast(LinkedList* plist);
// Remove an item at the k-th position.
void RemoveMiddle(LinkedList* plist, int pos);

// Read an item at the k-th position.
Data ReadItem(LinkedList* plist, int pos);
// Replace an item at the k-th position.
void ReplaceItem(LinkedList* plist, int pos, Data item);

// Print each item in a list in sequence.
void PrintListChar(LinkedList* plist);
void PrintListInt(LinkedList* plist);

// Remove all nodes in a list in sequence.
void ClearList(LinkedList* plist);

// Merge two lists.
LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2);

// Make the list in reverse sequence.
void Reverse(LinkedList* plist);


#endif _LINKED_LIST_H