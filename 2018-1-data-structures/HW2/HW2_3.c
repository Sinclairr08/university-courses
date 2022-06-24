/*================================================================================
* Written date : 2018.04.01
* Lastest revised date : 2018.04.10
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

// Structure that represents the movements
typedef struct {
	int ver;
	int hor;
} Move;

// Input the number from the user.
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();

// Problem 3. Finding Path in Maze
int FindingPath(int** arr, int m, int n);
void FindTarget(int** arr, int row, int col, int* next_row, int* next_col, int target, int m, int n);

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

	printf("%d\n", FindingPath(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P3_Test1()
{
	int m = 6;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 1, arr[0][2] = 1, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 1;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 0, arr[1][4] = -1, arr[1][5] = 1;
	arr[2][0] = 1, arr[2][1] = 0, arr[2][2] = 1, arr[2][3] = 0, arr[2][4] = 1, arr[2][5] = 1;
	arr[3][0] = 1, arr[3][1] = 0, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 1, arr[3][5] = -1;
	arr[4][0] = 1, arr[4][1] = 0, arr[4][2] = 1, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 0;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 0;


	printf("%d\n", FindingPath(arr, m, n)); // Result: 1

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P3_Test2()
{
	int m = 6;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 1, arr[0][2] = 1, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 1;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 0, arr[1][4] = 0, arr[1][5] = 1;
	arr[2][0] = 1, arr[2][1] = 0, arr[2][2] = 1, arr[2][3] = 0, arr[2][4] = 1, arr[2][5] = 1;
	arr[3][0] = 1, arr[3][1] = 0, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 1, arr[3][5] = 0;
	arr[4][0] = 1, arr[4][1] = 0, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 0;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 1, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 0;


	printf("%d\n", FindingPath(arr, m, n)); // Result: 0

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P3_Test3()
{
	int m = 8;
	int n = 8;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0, arr[0][6] = -1, arr[0][7] = 1;
	arr[1][0] = 1, arr[1][1] = 1, arr[1][2] = 1, arr[1][3] = 1, arr[1][4] = 1, arr[1][5] = 1, arr[1][6] = 0, arr[1][7] = 1;
	arr[2][0] = 0, arr[2][1] = 0, arr[2][2] = 0, arr[2][3] = 0, arr[2][4] = 0, arr[2][5] = 0, arr[2][6] = 0, arr[2][7] = 1;
	arr[3][0] = 1, arr[3][1] = 1, arr[3][2] = 0, arr[3][3] = 1, arr[3][4] = 1, arr[3][5] = 1, arr[3][6] = 0, arr[3][7] = 1;
	arr[4][0] = 1, arr[4][1] = 1, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 0, arr[4][6] = 1, arr[4][7] = 1;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 1, arr[5][5] = 0, arr[5][6] = 0, arr[5][7] = 0;
	arr[6][0] = -1, arr[6][1] = 1, arr[6][2] = 0, arr[6][3] = 0, arr[6][4] = 0, arr[6][5] = 0, arr[6][6] = 1, arr[6][7] = 0;
	arr[7][0] = 1, arr[7][1] = 0, arr[7][2] = 1, arr[7][3] = 0, arr[7][4] = 1, arr[7][5] = 0, arr[7][6] = 1, arr[7][7] = 0;


	printf("%d\n", FindingPath(arr, m, n)); // Result: 1

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P3_Test4()
{
	int m = 12;
	int n = 12;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0, arr[0][6] = -1, arr[0][7] = 0, arr[0][8] = 0, arr[0][9] = 0, arr[0][10] = 0, arr[0][11] = 0;
	arr[1][0] = 1, arr[1][1] = 1, arr[1][2] = 1, arr[1][3] = 1, arr[1][4] = 1, arr[1][5] = 1, arr[1][6] = 1, arr[1][7] = 1, arr[1][8] = 1, arr[1][9] = 1, arr[1][10] = 1, arr[1][11] = 1;
	arr[2][0] = 0, arr[2][1] = 0, arr[2][2] = 0, arr[2][3] = 1, arr[2][4] = -1, arr[2][5] = 0, arr[2][6] = -2, arr[2][7] = 0, arr[2][8] = 0, arr[2][9] = 0, arr[2][10] = 0, arr[2][11] = 0;
	arr[3][0] = 1, arr[3][1] = 1, arr[3][2] = 0, arr[3][3] = 1, arr[3][4] = 1, arr[3][5] = 1, arr[3][6] = 0, arr[3][7] = 1, arr[3][8] = 0, arr[3][9] = 0, arr[3][10] = 0, arr[3][11] = 0;
	arr[4][0] = 1, arr[4][1] = 1, arr[4][2] = 0, arr[4][3] = 0, arr[4][4] = 1, arr[4][5] = 0, arr[4][6] = -3, arr[4][7] = 1, arr[4][8] = 1, arr[4][9] = 1, arr[4][10] = 1, arr[4][11] = 1;
	arr[5][0] = 1, arr[5][1] = 1, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 1, arr[5][5] = 0, arr[5][6] = 0, arr[5][7] = 0, arr[5][8] = 0, arr[5][9] = 0, arr[5][10] = 1, arr[5][11] = 1;
	arr[6][0] = 1, arr[6][1] = 1, arr[6][2] = -2, arr[6][3] = 0, arr[6][4] = 1, arr[6][5] = 1, arr[6][6] = 1, arr[6][7] = 1, arr[6][8] = 0, arr[6][9] = 0, arr[6][10] = 0, arr[6][11] = 0;
	arr[7][0] = 0, arr[7][1] = 0, arr[7][2] = 0, arr[7][3] = 0, arr[7][4] = 1, arr[7][5] = 0, arr[7][6] = 0, arr[7][7] = 1, arr[7][8] = 1, arr[7][9] = 1, arr[7][10] = 1, arr[7][11] = 1;
	arr[8][0] = 0, arr[8][1] = 1, arr[8][2] = 0, arr[8][3] = 1, arr[8][4] = 1, arr[8][5] = 0, arr[8][6] = 0, arr[8][7] = 1, arr[8][8] = 0, arr[8][9] = 0, arr[8][10] = -3, arr[8][11] = 0;
	arr[9][0] = 0, arr[9][1] = 1, arr[9][2] = 0, arr[9][3] = 1, arr[9][4] = 1, arr[9][5] = 1, arr[9][6] = 1, arr[9][7] = 1, arr[9][8] = 0, arr[9][9] = 1, arr[9][10] = 0, arr[9][11] = 0;
	arr[10][0] = 0, arr[10][1] = 0, arr[10][2] = 0, arr[10][3] = 1, arr[10][4] = 0, arr[10][5] = 1, arr[10][6] = 1, arr[10][7] = 0, arr[10][8] = 0, arr[10][9] = 0, arr[10][10] = 1, arr[10][11] = 1;
	arr[11][0] = 0, arr[11][1] = 0, arr[11][2] = 0, arr[11][3] = 0, arr[11][4] = 1, arr[11][5] = 0, arr[11][6] = 0, arr[11][7] = 0, arr[11][8] = 0, arr[11][9] = 0, arr[11][10] = 0, arr[11][11] = 0;


	printf("%d\n", FindingPath(arr, m, n)); // Result: 1

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 3. Finding Path in Maze
int FindingPath(int** arr, int m, int n)
{
	if (arr[0][0] == 1 || arr[m - 1][n - 1] == 1)
		return 0;

	Move move[4] = { { 0,-1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };	// Means the movement. Each means left, down, right, up.
	int found = FALSE;											// variable represents that the exit of maze is found or not

	Stack* sp = (Stack*)malloc(sizeof(Stack));		// Stack that contains the possible ways
	InitStack(sp);

	int row, col, next_row, next_col;
	int dir, i, j, target;

	int** mark = (int **)malloc(sizeof(int*)* m);	// The 2-dimenson array which marks the passed way
	for (i = 0; i < m; i++)
		mark[i] = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < m; i++)							// Initialize as zero
		for (j = 0; j < n; j++)
			mark[i][j] = 0;

	mark[0][0] = 1;									// Since it starts from zero, mark 0,0 as 1
	Push(sp, 0), Push(sp, 0);						// Push the order of row, column. To go to the direction of (0,0)

	while (!IsEmpty(sp) && !found) {				// Until there is no more way or if arrives to the exit of maze

		col = Peek(sp), Pop(sp);					// Go to the location which saved at the stack
		row = Peek(sp), Pop(sp);					// Since row is firstly stored, row is secondly popped(LIFO)


		if (arr[row][col] < 0) {					// The blackhole case
			target = arr[row][col];	
			// Change the value of next_row, next_col as the exit of the black hole
			FindTarget(arr, row, col, &next_row, &next_col, target, m, n);

			if (mark[next_row][next_col] == 0) {	// If the exit of blackhole is not visited before
				mark[next_row][next_col] = 1;		// Mark as 1

				Push(sp, next_row),	Push(sp, next_col);
			}
		}

		for (dir = 0; dir < 4 && !found; dir++) {	// Check the way for 4 directions. If exit of maze is found, then stops checking.

			next_row = row + move[dir].hor;			// move[dir] means the direction
			next_col = col + move[dir].ver;

			// Ignore the case when excced the boundary
			if (next_row < 0 || next_row > m - 1 || next_col < 0 || next_col > n - 1)
				continue;

			// If exit of maze is found
			if (next_row == m - 1 && next_col == n - 1)
				found = TRUE;

			// If there is a way that is never been visited
			else if (arr[next_row][next_col] <= 0 && !mark[next_row][next_col]) {
				mark[next_row][next_col] = 1;

				Push(sp, next_row), Push(sp, next_col);
			}

		}// end of for

	}// end of while

	
	for (i = 0; i < m; i++)
		free(mark[i]);
	free(mark);

	if (found)
		return 1;									// If there is a way

	else
		return 0;									// If there is no way

}

// Function that changes the given input(next_row, next_col) as the exit of blackhole
void FindTarget(int** arr, int row, int col, int* next_row, int* next_col, int target, int m, int n) {
	for (int i = 0; i < m; i++)						// Search for every elements
		for (int j = 0; j < n; j++)

			// If target is found which is not same with the entrance
			if (arr[i][j] == target && i != row && j != col) {
				*next_row = i;	
				*next_col = j;
				return;
			}

	printf("Blackhole does not matched.\n");		// If can't find the exit of blackhole
	exit(-1);
}