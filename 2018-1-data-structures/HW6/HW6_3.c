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
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();

// Problem 3. Finding when cheese is divided.
int CheeseTime(int** arr, int m, int n);

bool is_connected(int** arr, int m, int n);

int main()
{
	P3_GeneralTest();

	//P3_Test1();
	//P3_Test2();
	//P3_Test3();
	//P3_Test4();

	return 0;
}

// Input the number from the user.
void P3_GeneralTest()
{
	int m;
	int n;
	int i, j;

	scanf("%d %d", &m, &n);
	
	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("%d", CheeseTime(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P3_Test1()
{
	int m = 5;
	int n = 5;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 5;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 5, arr[1][4] = 4;
	arr[2][0] = 0, arr[2][1] = 0, arr[2][2] = 5, arr[2][3] = 4, arr[2][4] = 2;
	arr[3][0] = 0, arr[3][1] = 5, arr[3][2] = 4, arr[3][3] = 2, arr[3][4] = 4;
	arr[4][0] = 5, arr[4][1] = 4, arr[4][2] = 2, arr[4][3] = 4, arr[4][4] = 5;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", CheeseTime(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P3_Test2()
{
	int m = 6;
	int n = 5;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0;
	arr[1][0] = 0, arr[1][1] = 1, arr[1][2] = 1, arr[1][3] = 1, arr[1][4] = 0;
	arr[2][0] = 0, arr[2][1] = 1, arr[2][2] = 2, arr[2][3] = 1, arr[2][4] = 0;
	arr[3][0] = 0, arr[3][1] = 2, arr[3][2] = 3, arr[3][3] = 2, arr[3][4] = 0;
	arr[4][0] = 0, arr[4][1] = 1, arr[4][2] = 2, arr[4][3] = 1, arr[4][4] = 0;
	arr[5][0] = 0, arr[5][1] = 0, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", CheeseTime(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P3_Test3()
{
	int m = 4;
	int n = 4;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 8, arr[0][1] = 1, arr[0][2] = 6, arr[0][3] = 9;
	arr[1][0] = 7, arr[1][1] = 5, arr[1][2] = 4, arr[1][3] = 2;
	arr[2][0] = 4, arr[2][1] = 2, arr[2][2] = 3, arr[2][3] = 5;
	arr[3][0] = 7, arr[3][1] = 6, arr[3][2] = 5, arr[3][3] = 0;
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", CheeseTime(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P3_Test4()
{
	int m = 5;
	int n = 7;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0, arr[0][6] = 0;
	arr[1][0] = 0, arr[1][1] = 2, arr[1][2] = 4, arr[1][3] = 5, arr[1][4] = 3, arr[1][5] = 0, arr[1][6] = 0;
	arr[2][0] = 0, arr[2][1] = 3, arr[2][2] = 0, arr[2][3] = 2, arr[2][4] = 5, arr[2][5] = 2, arr[2][6] = 0;
	arr[3][0] = 0, arr[3][1] = 7, arr[3][2] = 6, arr[3][3] = 2, arr[3][4] = 4, arr[3][5] = 0, arr[3][6] = 0;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 0, arr[4][5] = 0, arr[4][6] = 0;


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	printf("%d", CheeseTime(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 3. Finding when cheese is divided.
int CheeseTime(int** arr, int m, int n)
{
	int time = 0;

	while (is_connected(arr, m, n))
	{
		int i, j;
		time++;

		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (arr[i][j])
					arr[i][j]--;
	}

	return time;
}

bool is_connected(int** arr, int m, int n)
{
	int i, j;
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
	int cheese_num = 0;
	Queue que;
	Pos pos;
	InitQueue(&que);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (!mark[i][j])
			{
				mark[i][j] = 1;

				pos.x = i, pos.y = j;
				EnQueue(&que, pos);

				while (!IsEmpty(&que))
				{
					pos = Peek(&que), DeQueue(&que);
					row = pos.x, col = pos.y;

					if (row < m - 1 && !mark[row + 1][col] && arr[row + 1][col]) {
						pos.x = row + 1, pos.y = col, mark[row + 1][col] = 1;
						EnQueue(&que, pos);
					}

					if (col < n - 1 && !mark[row][col + 1] && arr[row][col + 1]) {
						pos.x = row, pos.y = col + 1, mark[row][col + 1] = 1;
						EnQueue(&que, pos);
					}

					if (row > 0 && !mark[row - 1][col] && arr[row - 1][col]) {
						pos.x = row - 1, pos.y = col, mark[row - 1][col] = 1;
						EnQueue(&que, pos);
					}

					if (col > 0 && !mark[row][col - 1] && arr[row][col - 1]) {
						pos.x = row, pos.y = col - 1, mark[row][col - 1] = 1;
						EnQueue(&que, pos);
					}

				} // end of while

				cheese_num++;

			}
		}


	for (i = 0; i < m; i++)
		free(mark[i]);
	free(mark);

	if (cheese_num == 1)
		return true;

	else
		return false;


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

