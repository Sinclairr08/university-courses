/*================================================================================
* Written date : 2018.05.31
* Lastest revised date : 2018.06.01
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

#define MAX_QUEUE	100
#define MAX_ISLAND_SIZE	100

typedef enum { false, true } bool;

typedef struct {
	int x;
	int y;
}Pos;

typedef Pos Data;

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

// Input the number from the user.
void P1_GeneralTest();

int compare(void* first, void* second);

// Examples
void P1_Test1();
void P1_Test2();
void P1_Test3();
void P1_Test4();

typedef struct
{
	int n;
	int* sizes;
} Islands;

// Problem 1. Finding the sizes of Islands
Islands FindingIslandSize(int** arr, int m, int n);

int main()
{
	P1_GeneralTest();

	//P1_Test1();
	//P1_Test2();
	//P1_Test3();
	//P1_Test4();

	return 0;
}

// Input the number from the user.
void P1_GeneralTest()
{
	int m;
	int n;
	int i, j;
	Islands result;
	scanf("%d %d", &m, &n);

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}

	result = FindingIslandSize(arr, m, n);

	for (i = 0; i < result.n; i++)
	{
		printf("%d ", result.sizes[i]);
	}

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P1_Test1()
{
	int m = 6;
	int n = 6;
	int i, j;
	Islands result;
	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 1, arr[0][1] = 1, arr[0][2] = 1, arr[0][3] = 1, arr[0][4] = 0, arr[0][5] = 1;
	arr[1][0] = 1, arr[1][1] = 1, arr[1][2] = 0, arr[1][3] = 0, arr[1][4] = 1, arr[1][5] = 1;
	arr[2][0] = 1, arr[2][1] = 1, arr[2][2] = 0, arr[2][3] = 1, arr[2][4] = 1, arr[2][5] = 1;
	arr[3][0] = 1, arr[3][1] = 0, arr[3][2] = 1, arr[3][3] = 1, arr[3][4] = 1, arr[3][5] = 1;
	arr[4][0] = 0, arr[4][1] = 1, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 1;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 0, arr[5][4] = 1, arr[5][5] = 1;

	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	
	result = FindingIslandSize(arr, m, n);

	for (i = 0; i < result.n; i++)
	{
		printf("%d ", result.sizes[i]);
	}

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P1_Test2()
{
	int m = 6;
	int n = 6;
	int i, j;
	Islands result;
	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 1, arr[0][2] = 1, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 1;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 0, arr[1][4] = 0, arr[1][5] = 1;
	arr[2][0] = 1, arr[2][1] = 0, arr[2][2] = 1, arr[2][3] = 0, arr[2][4] = 1, arr[2][5] = 1;
	arr[3][0] = 1, arr[3][1] = 0, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 1, arr[3][5] = 0;
	arr[4][0] = 1, arr[4][1] = 0, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 0;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 1, arr[5][4] = 0, arr[5][5] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	result = FindingIslandSize(arr, m, n);

	for (i = 0; i < result.n; i++)
	{
		printf("%d ", result.sizes[i]);
	}

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P1_Test3()
{
	int m = 8;
	int n = 8;
	int i, j;
	Islands result;
	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0, arr[0][6] = 0, arr[0][7] = 0;
	arr[1][0] = 0, arr[1][1] = 1, arr[1][2] = 0, arr[1][3] = 1, arr[1][4] = 1, arr[1][5] = 1, arr[1][6] = 1, arr[1][7] = 0;	
	arr[2][0] = 0, arr[2][1] = 1, arr[2][2] = 0, arr[2][3] = 1, arr[2][4] = 0, arr[2][5] = 0, arr[2][6] = 1, arr[2][7] = 0;
	arr[3][0] = 0, arr[3][1] = 1, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 0, arr[3][5] = 1, arr[3][6] = 1, arr[3][7] = 0;
	arr[4][0] = 0, arr[4][1] = 1, arr[4][2] = 0, arr[4][3] = 1, arr[4][4] = 0, arr[4][5] = 1, arr[4][6] = 1, arr[4][7] = 0;
	arr[5][0] = 0, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 0, arr[5][6] = 0, arr[5][7] = 0;
	arr[6][0] = 1, arr[6][1] = 1, arr[6][2] = 1, arr[6][3] = 1, arr[6][4] = 1, arr[6][5] = 1, arr[6][6] = 1, arr[6][7] = 0;
	arr[7][0] = 0, arr[7][1] = 1, arr[7][2] = 0, arr[7][3] = 1, arr[7][4] = 0, arr[7][5] = 1, arr[7][6] = 1, arr[7][7] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	result = FindingIslandSize(arr, m, n);

	for (i = 0; i < result.n; i++)
	{
		printf("%d ", result.sizes[i]);
	}

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P1_Test4()
{
	int m = 8;
	int n = 8;
	int i, j;
	Islands result;
	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 1, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 1, arr[0][6] = 1, arr[0][7] = 1;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 0, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 1, arr[1][7] = 1;	
	arr[2][0] = 0, arr[2][1] = 0, arr[2][2] = 0, arr[2][3] = 0, arr[2][4] = 0, arr[2][5] = 1, arr[2][6] = 1, arr[2][7] = 0;
	arr[3][0] = 0, arr[3][1] = 0, arr[3][2] = 0, arr[3][3] = 0, arr[3][4] = 1, arr[3][5] = 1, arr[3][6] = 1, arr[3][7] = 1;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 0, arr[4][5] = 1, arr[4][6] = 0, arr[4][7] = 0;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 1, arr[5][6] = 1, arr[5][7] = 1;
	arr[6][0] = 0, arr[6][1] = 0, arr[6][2] = 0, arr[6][3] = 0, arr[6][4] = 0, arr[6][5] = 0, arr[6][6] = 0, arr[6][7] = 1;
	arr[7][0] = 0, arr[7][1] = 0, arr[7][2] = 0, arr[7][3] = 0, arr[7][4] = 0, arr[7][5] = 0, arr[7][6] = 1, arr[7][7] = 1;
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	result = FindingIslandSize(arr, m, n);

	for (i = 0; i < result.n; i++)
	{
		printf("%d ", result.sizes[i]);
	}

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 1. Finding the sizes of Islands
Islands FindingIslandSize(int** arr, int m, int n)
{	
	int i,j;
	int** mark = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		mark[i] = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			if (arr[i][j])
				mark[i][j] = 0;
			else
				mark[i][j] = 1;
		}

	int row, col;
	int island_size, island_num = 0;
	Queue que;
	Pos pos;
	InitQueue(&que);

	int* stor = (int*)malloc(sizeof(int) * MAX_ISLAND_SIZE);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (!mark[i][j])
			{
				mark[i][j] = 1;

				pos.x = i, pos.y = j;
				EnQueue(&que, pos);
				island_size = 1;

				while (!IsEmpty(&que))
				{
					pos = Peek(&que), DeQueue(&que);
					row = pos.x, col = pos.y;

					if (row < m - 1 && !mark[row + 1][col] && arr[row + 1][col]) {
						pos.x = row + 1, pos.y = col, mark[row + 1][col] = 1;
						EnQueue(&que, pos);
						island_size++;
					}

					if (col < n - 1 && !mark[row][col + 1] && arr[row][col + 1]) {
						pos.x = row, pos.y = col + 1, mark[row][col + 1] = 1;
						EnQueue(&que, pos);
						island_size++;
					}

					if (row > 0 && !mark[row - 1][col] && arr[row - 1][col]) {
						pos.x = row - 1, pos.y = col, mark[row - 1][col] = 1;
						EnQueue(&que, pos);
						island_size++;
					}

					if (col > 0 && !mark[row][col - 1] && arr[row][col - 1]) {
						pos.x = row, pos.y = col - 1, mark[row][col - 1] = 1;
						EnQueue(&que, pos);
						island_size++;
					}

				} // end of while
				
				stor[island_num++] = island_size;

			}
		}
	

	for (i = 0; i < m; i++)
		free(mark[i]);
	free(mark);

	int* sizes = (int*)malloc(sizeof(int) * island_num);

	for (i = 0; i < island_num; i++)
		sizes[i] = stor[i];

	free(stor);

	qsort(sizes, island_num, sizeof(int), compare);

	Islands result = { island_num, sizes };
	
	return result;
}

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

int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return -1;

	else if (*(int*)first < *(int*)second)
		return 1;

	else
		return 0;
}