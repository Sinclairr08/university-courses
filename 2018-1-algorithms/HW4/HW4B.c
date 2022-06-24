/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Topological Sort Ex
*
* Project name : HW4
* File names : 2014310407_HW4B.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.05.23
* Lastest revised date : 2018.05.28
*
* Operation System : Windows 10
*
* Modification histroy :
* 1. 2018.05.28(Lee Jun Hyuk):
*	1) Some elimination of useless repetition
*   2) Add some comments
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_SIZE 20
#define MAX_GRAPH_SIZE 100
#define MAX_HEAP_SIZE 100

#define L_child(n) ((n)*(2))
#define R_child(n) (((n)*(2)) + (1))
#define Parent(n) ((n)/(2))

#undef max(a,b);
#define max(a,b) (((a) > (b)) ? (a) ; (b))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {WHITE, BLACK} node_color;
typedef enum {false, true} bool;

/* Linked List Node */
typedef struct _node {
	struct _node* next;
	int node_num;
}GraphListNode;

/* Linked List */
typedef struct {
	GraphListNode* head;
	char name[MAX_NAME_SIZE];
	int rank;
	node_color color;
}GraphList;

/* Graph with array of linked list */
typedef struct {
	GraphList** list;
	int size;
}Graph;

/* Heap node */
typedef struct {
	char* name;
	int priority;
}HNODE;

/* Heap */
typedef struct {
	HNODE item[MAX_HEAP_SIZE + 1];
	int size;
}Heap;

/* Linked List functions */
void delete_Node(GraphListNode* gnode);

void InsertFirst(GraphList* glist, int node_num);
bool RemoveItem(GraphList* glist, int item);
bool is_empty(GraphList* glist);

GraphList* new_List(char* _name);

/* Graph functions */
Graph* new_Graph(int num);
void delete_Graph(Graph* grap);

int Findindex(Graph* grap, char* _name);
void addEdge(Graph* grap, int idx1, int idx2);

/* Compare the priority of two components */
int Hnode_cmp(HNODE h1, HNODE h2);

/* Print the rank */
void print_rank(Graph* grap);

/* Heap functions */
void Min_Heapify(Heap* heap, int node);
void Swap(HNODE* h1, HNODE* h2);

int main()
{
	int num_animal, num_comp;
	char* input = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);

	/* Get the number of animal and comparison */
	scanf("%d %d", &num_animal, &num_comp);
	getchar();

	Graph* grap = new_Graph(num_animal);
	int idx_s, idx_e, i, j;

	/* Get the name of animals */
	for (i = 0; i < num_animal; i++)
	{
		scanf("%[^/\n]", input);
		getchar();
		grap->list[i] = new_List(input);
	}

	/* For each comparison, add the edge at the graph */
	for (i = 0; i < num_comp; i++)
	{
		scanf("%[^/\n]", input);
		getchar();
		idx_s = Findindex(grap, input);

		scanf("%[^/\n]", input);	
		getchar();
		idx_e = Findindex(grap, input);

		addEdge(grap, idx_s, idx_e);
	}

	bool cycle_cnt = false;
	int temp_rank;

	while (!cycle_cnt)
	{
		cycle_cnt = true;

		/* For each nodes */
		for (i = 0; i < num_animal; i++)
		{
			/* If node is not visited and if there are no predecessor */
			if (grap->list[i]->color == WHITE && is_empty(grap->list[i]))
			{
				cycle_cnt = false;

				/* Mark that node is visited and increase the rank */
				grap->list[i]->color = BLACK;
				temp_rank = ++(grap->list[i]->rank);
				
				/* Change the rank of all nodes that are indicated by current node */
				for (j = 0; j < num_animal; j++)
				{
					if (grap->list[j]->color != BLACK && RemoveItem(grap->list[j], i))
						/* Mark the rank as the bigger one */
						grap->list[j]->rank = max(grap->list[j]->rank, temp_rank);

				}
			}

		} // end of for 

	} // end of while
	
	cycle_cnt = false;

	/* Check that white color is remained. If then, cycle exists */
	for (int i = 0; i < num_animal; i++)
		if (!grap->list[i]->color)				
			cycle_cnt = true;

	/* If cycle exist */
	if (cycle_cnt)
		printf("Stupid David!\n");

	/* If there are no cycle, print the rank and name by using heap */
	else
		print_rank(grap);

	delete_Graph(grap);
	free(input);
	
	return 0;
}

/* Make a new linked list which represent the node */
GraphList* new_List(char* _name)
{
	GraphList* glist = (GraphList*)malloc(sizeof(GraphList));
	glist->head = NULL;
	glist->rank = 0;
	glist->color = WHITE;
	strcpy(glist->name, _name);

	return glist;
}

/* Make a new graph */
Graph* new_Graph(int num)
{
	Graph* grap = (Graph*)malloc(sizeof(Graph));
	grap->list = (GraphList**)malloc(sizeof(GraphList*) * num);

	for (int i = 0; i < num; i++)
		grap->list[i] = (GraphList*)malloc(sizeof(GraphList));

	grap->size = num;
	return grap;
}

/* Delete the graph */
void delete_Graph(Graph* grap)
{
	for (int i = 0; i < grap->size; i++)
		free(grap->list[i]);

	free(grap->list);
	free(grap);
}

/* Find the index at the graph corresponds to the given name */
int Findindex(Graph* grap, char* _name)
{
	for (int i = 0; i < grap->size; i++)
		if (strcmp(grap->list[i]->name, _name) == 0)
			return i;

	return -1;
}

/* 
 * Assume that two node is located idx1 -> idx2
 * To represent the predecessor of the node, link idx1 to idx2
 * i,e linked list represents the predecessor
 */
void addEdge(Graph* grap, int idx1, int idx2)
{
	InsertFirst(grap->list[idx2], idx1);
}

/* Insert the item to the linked list at the first position */
void InsertFirst(GraphList* glist, int node_num)
{
	GraphListNode* newNode = (GraphListNode*)malloc(sizeof(GraphListNode));
	newNode->next = NULL;
	newNode->node_num = node_num;

	if (glist->head == NULL)
		glist ->head = newNode;

	else
	{
		newNode->next = glist->head->next;
		glist->head = newNode;
	}
	
	return;
}

/* Check whether list is empty or not */
bool is_empty(GraphList* glist)
{
	return glist->head == NULL ? true : false;
}

/*
 * Remove the given item in the linked list.
 * If item exist, return true, else return false
 */
bool RemoveItem(GraphList* glist, int item)
{
	GraphListNode* cur, *prev;
	cur = glist->head;
	prev = NULL;

	while (cur != NULL)
	{
		/* If there exist corresponding item */
		if (cur->node_num == item)
		{
			if (prev == NULL)
				glist->head = cur->next;

			else
				prev->next = cur->next;

			delete_Node(cur);
			return true;
		}

		else
		{
			prev = cur;
			cur = cur->next;
		}

	}

	/* If there are no corresponding item, then return false */
	return false;
}

/* Delete the node of the linked list */
void delete_Node(GraphListNode* gnode)
{
	free(gnode);
}

/* Print the rank and name of the animals Use heap to sort the rank and names */
void print_rank(Graph* grap)
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = grap->size;

	/* Input the information of graph to the heap */
	for (int i = 1; i <= grap->size; i++)
	{
		heap->item[i].priority = grap->list[i-1]->rank;
		heap->item[i].name = grap->list[i-1]->name;
	}
	
	/* Build a heap */
	for (int i = Parent(heap->size); i >= 1; i--)
		Min_Heapify(heap, i);

	/* Print the rank and name by using heapsort */
	while (heap->size > 1)
	{
		printf("%d ", heap->item[1].priority);
		printf("%s\n", heap->item[1].name);

		Swap(&(heap->item[1]), &(heap->item[heap->size]));
		heap->size--;

		Min_Heapify(heap, 1);
	}

	/* Print the last element */
	printf("%d ", heap->item[1].priority);
	printf("%s\n", heap->item[1].name);

	free(heap);
}

/* Do min_heapify for the node of heap */
void Min_Heapify(Heap* heap, int node)
{
	/* If there are no child */
	if (L_child(node) > heap->size)
		return;

	/* If there is only left child */
	else if (L_child(node) == heap->size)
	{
		/* If left child has smaller rank, swap it */
		if (Hnode_cmp(heap->item[L_child(node)], heap->item[node]) == -1)
			Swap(&(heap->item[L_child(node)]), &(heap->item[node]));

		return;
	}

	/* If there are left & right child */
	else
	{
		/* If left child has smaller rank than right child */
		if (Hnode_cmp(heap->item[L_child(node)], heap->item[R_child(node)]) == -1)
		{
			/* If left child also has smaller rank than the node */
			if (Hnode_cmp(heap->item[L_child(node)], heap->item[node]) == -1)
			{
				Swap(&(heap->item[L_child(node)]), &(heap->item[node]));
				Min_Heapify(heap, L_child(node));
			}

			else
				return;

		}

		/* If right child has smaller rank than left child */
		else
		{
			/* If right child also has smaller rank than the node */
			if (Hnode_cmp(heap->item[R_child(node)], heap->item[node]) == -1)
			{
				Swap(&(heap->item[R_child(node)]), &(heap->item[node]));
				Min_Heapify(heap, R_child(node));
			}

			else
				return;
		}

	}
	
}

/*
 * Compare two heap nodes
 * If h1 is prior to h2, return -1, Opposite case, return 1
 * If their priorities are same, use strcmp function to compare
 */
int Hnode_cmp(HNODE h1, HNODE h2)
{
	if (h1.priority < h2.priority)
		return -1;

	else if (h2.priority < h1.priority)
		return 1;

	else
		return strcmp(h1.name, h2.name);
}

/* Swap two heap nodes */
void Swap(HNODE* h1, HNODE* h2)
{
	HNODE temp;
	temp = *h1;
	*h1 = *h2;
	*h2 = temp;
	return;
}