/*================================================================================
* Written date : 2018.06.01
* Lastest revised date : 2018.06.01
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

// Input the number from the user.
void P2_GeneralTest();

// Examples
void P2_Test1();
void P2_Test2();
void P2_Test3();
void P2_Test4();

// Problem 2. Finding Shortest Path in Maze
int FindingShortestPath(int** arr, int m, int n);

int main()
{
	P2_GeneralTest();

	//P2_Test1();
	//P2_Test2();
	//P2_Test3();
	//P2_Test4();

	return 0;
}

// Input the number from the user.
void P2_GeneralTest()
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

	printf("%d", FindingShortestPath(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P2_Test1()
{
	int m = 6;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 1, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0;
	arr[1][0] = 1, arr[1][1] = 1, arr[1][2] = 1, arr[1][3] = 1, arr[1][4] = 1, arr[1][5] = 0;
	arr[2][0] = 0, arr[2][1] = 1, arr[2][2] = 0, arr[2][3] = 1, arr[2][4] = 0, arr[2][5] = 8;
	arr[3][0] = 0, arr[3][1] = 1, arr[3][2] = 0, arr[3][3] = 1, arr[3][4] = 1, arr[3][5] = 1;
	arr[4][0] = 0, arr[4][1] = 8, arr[4][2] = 0, arr[4][3] = 1, arr[4][4] = 0, arr[4][5] = 1;
	arr[5][0] = 0, arr[5][1] = 0, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 0, arr[5][5] = 1;


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	printf("%d", FindingShortestPath(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P2_Test2()
{
	int m = 6;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 1, arr[0][1] = 0, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 0;
	arr[1][0] = 1, arr[1][1] = 1, arr[1][2] = 1, arr[1][3] = 8, arr[1][4] = 1, arr[1][5] = 0;
	arr[2][0] = 0, arr[2][1] = 1, arr[2][2] = 0, arr[2][3] = 1, arr[2][4] = 0, arr[2][5] = 0;
	arr[3][0] = 0, arr[3][1] = 1, arr[3][2] = 0, arr[3][3] = 1, arr[3][4] = 0, arr[3][5] = 1;
	arr[4][0] = 0, arr[4][1] = 8, arr[4][2] = 1, arr[4][3] = 1, arr[4][4] = 0, arr[4][5] = 1;
	arr[5][0] = 0, arr[5][1] = 0, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 0, arr[5][5] = 1;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	printf("%d", FindingShortestPath(arr, m, n)); // Result: -1

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P2_Test3()
{
	int m = 8;
	int n = 8;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 1, arr[0][1] = 1, arr[0][2] = 0, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 8, arr[0][6] = 0, arr[0][7] = 0;
	arr[1][0] = 0, arr[1][1] = 1, arr[1][2] = 0, arr[1][3] = 1, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 0, arr[1][7] = 0;	
	arr[2][0] = 1, arr[2][1] = 1, arr[2][2] = 1, arr[2][3] = 1, arr[2][4] = 1, arr[2][5] = 1, arr[2][6] = 1, arr[2][7] = 0;
	arr[3][0] = 0, arr[3][1] = 0, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 0, arr[3][5] = 1, arr[3][6] = 0, arr[3][7] = 0;
	arr[4][0] = 0, arr[4][1] = 1, arr[4][2] = 1, arr[4][3] = 0, arr[4][4] = 0, arr[4][5] = 1, arr[4][6] = 0, arr[4][7] = 0;
	arr[5][0] = 0, arr[5][1] = 1, arr[5][2] = 0, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 1, arr[5][6] = 0, arr[5][7] = 0;
	arr[6][0] = 1, arr[6][1] = 8, arr[6][2] = 0, arr[6][3] = 1, arr[6][4] = 0, arr[6][5] = 0, arr[6][6] = 0, arr[6][7] = 0;
	arr[7][0] = 0, arr[7][1] = 0, arr[7][2] = 0, arr[7][3] = 1, arr[7][4] = 1, arr[7][5] = 1, arr[7][6] = 1, arr[7][7] = 1;


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindingShortestPath(arr, m, n)); // Result: 18

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P2_Test4()
{
	int m = 8;
	int n = 8;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 1, arr[0][1] = 1, arr[0][2] = 0, arr[0][3] = 1, arr[0][4] = 1, arr[0][5] = 1, arr[0][6] = 0, arr[0][7] = 0;
	arr[1][0] = 0, arr[1][1] = 1, arr[1][2] = 0, arr[1][3] = 1, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 0, arr[1][7] = 0;	
	arr[2][0] = 8, arr[2][1] = 1, arr[2][2] = 1, arr[2][3] = 0, arr[2][4] = 1, arr[2][5] = 1, arr[2][6] = 1, arr[2][7] = 0;
	arr[3][0] = 0, arr[3][1] = 1, arr[3][2] = 1, arr[3][3] = 0, arr[3][4] = 0, arr[3][5] = 1, arr[3][6] = 0, arr[3][7] = 0;
	arr[4][0] = 0, arr[4][1] = 1, arr[4][2] = 1, arr[4][3] = 0, arr[4][4] = 0, arr[4][5] = 1, arr[4][6] = 0, arr[4][7] = 0;
	arr[5][0] = 0, arr[5][1] = 1, arr[5][2] = 0, arr[5][3] = 1, arr[5][4] = 1, arr[5][5] = 1, arr[5][6] = 0, arr[5][7] = 0;
	arr[6][0] = 1, arr[6][1] = 1, arr[6][2] = 0, arr[6][3] = 8, arr[6][4] = 0, arr[6][5] = 0, arr[6][6] = 0, arr[6][7] = 0;
	arr[7][0] = 0, arr[7][1] = 1, arr[7][2] = 1, arr[7][3] = 1, arr[7][4] = 1, arr[7][5] = 1, arr[7][6] = 1, arr[7][7] = 1;


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindingShortestPath(arr, m, n)); // Result: 9

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 2. Finding Shortest Path in Maze
int FindingShortestPath(int** arr, int m, int n)
{
	// Write your code here.

	return -1;
}