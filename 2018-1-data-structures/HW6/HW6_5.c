#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Write your student id, name, and discusser.
// StudentID: 20180000000
// Name: Jongwuk Lee
// Discusser: Nobody

// Input the number from the user.
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();

// Problem 5. Second Maximum Spanning Tree
int SecondMST(int** arr, int m, int n);

int main()
{
	//P5_GeneralTest();

	//P5_Test1();
	//P5_Test2();
	//P5_Test3();
	P5_Test4();

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
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

	printf("%d", SecondMST(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P5_Test1()
{
	int m = 7;
	int n = 7;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 2, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 15, arr[0][6] = 0;
	arr[1][0] = 2, arr[1][1] = 0, arr[1][2] = 0, arr[1][3] = 14, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 0;	
	arr[2][0] = 0, arr[2][1] = 0, arr[2][2] = 0, arr[2][3] = 12, arr[2][4] = 8, arr[2][5] = 5, arr[2][6] = 0;
	arr[3][0] = 0, arr[3][1] = 14, arr[3][2] = 12, arr[3][3] = 0, arr[3][4] = 10, arr[3][5] = 0, arr[3][6] = 0;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 8, arr[4][3] = 10, arr[4][4] = 0, arr[4][5] = 0, arr[4][6] = 4;
	arr[5][0] = 15, arr[5][1] = 0, arr[5][2] = 5, arr[5][3] = 0, arr[5][4] = 0, arr[5][5] = 0, arr[5][6] = 6;
	arr[6][0] = 0, arr[6][1] = 0, arr[6][2] = 0, arr[6][3] = 0, arr[6][4] = 4, arr[6][5] = 6, arr[6][6] = 0;


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	printf("%d", SecondMST(arr, m, n)); // Result: 61

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P5_Test2()
{
	int m = 7;
	int n = 7;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 0, arr[0][2] = 2, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 10, arr[0][6] = 0;
	arr[1][0] = 0, arr[1][1] = 0, arr[1][2] = 13, arr[1][3] = 4, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 0;	
	arr[2][0] = 2, arr[2][1] = 13, arr[2][2] = 0, arr[2][3] = 0, arr[2][4] = 3, arr[2][5] = 0, arr[2][6] = 0;
	arr[3][0] = 0, arr[3][1] = 4, arr[3][2] = 0, arr[3][3] = 0, arr[3][4] = 12, arr[3][5] = 0, arr[3][6] = 0;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 3, arr[4][3] = 12, arr[4][4] = 0, arr[4][5] = 14, arr[4][6] = 4;
	arr[5][0] = 10, arr[5][1] = 0, arr[5][2] = 0, arr[5][3] = 0, arr[5][4] = 14, arr[5][5] = 0, arr[5][6] = 6;
	arr[6][0] = 0, arr[6][1] = 0, arr[6][2] = 0, arr[6][3] = 0, arr[6][4] = 4, arr[6][5] = 6, arr[6][6] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	
	printf("%d", SecondMST(arr, m, n)); // Result: 58

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P5_Test3()
{
	int m = 7;
	int n = 7;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 13, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 15, arr[0][6] = 0;
	arr[1][0] = 13, arr[1][1] = 0, arr[1][2] = 12, arr[1][3] = 14, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 0;	
	arr[2][0] = 0, arr[2][1] = 12, arr[2][2] = 0, arr[2][3] = 0, arr[2][4] = 8, arr[2][5] = 5, arr[2][6] = 0;
	arr[3][0] = 0, arr[3][1] = 14, arr[3][2] = 0, arr[3][3] = 0, arr[3][4] = 10, arr[3][5] = 0, arr[3][6] = 0;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 8, arr[4][3] = 10, arr[4][4] = 0, arr[4][5] = 0, arr[4][6] = 4;
	arr[5][0] = 15, arr[5][1] = 0, arr[5][2] = 5, arr[5][3] = 0, arr[5][4] = 0, arr[5][5] = 0, arr[5][6] = 6;
	arr[6][0] = 0, arr[6][1] = 0, arr[6][2] = 0, arr[6][3] = 0, arr[6][4] = 4, arr[6][5] = 6, arr[6][6] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", SecondMST(arr, m, n)); // Result: 68

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P5_Test4()
{
	int m = 7;
	int n = 7;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* n);

	arr[0][0] = 0, arr[0][1] = 10, arr[0][2] = 0, arr[0][3] = 0, arr[0][4] = 0, arr[0][5] = 12, arr[0][6] = 0;
	arr[1][0] = 10, arr[1][1] = 0, arr[1][2] = 12, arr[1][3] = 0, arr[1][4] = 0, arr[1][5] = 0, arr[1][6] = 13;	
	arr[2][0] = 0, arr[2][1] = 12, arr[2][2] = 0, arr[2][3] = 0, arr[2][4] = 0, arr[2][5] = 7, arr[2][6] = 6;
	arr[3][0] = 0, arr[3][1] = 0, arr[3][2] = 0, arr[3][3] = 0, arr[3][4] = 10, arr[3][5] = 0, arr[3][6] = 0;
	arr[4][0] = 0, arr[4][1] = 0, arr[4][2] = 0, arr[4][3] = 10, arr[4][4] = 0, arr[4][5] = 8, arr[4][6] = 0;
	arr[5][0] = 12, arr[5][1] = 0, arr[5][2] = 7, arr[5][3] = 0, arr[5][4] = 8, arr[5][5] = 0, arr[5][6] = 0;
	arr[6][0] = 0, arr[6][1] = 13, arr[6][2] = 6, arr[6][3] = 0, arr[6][4] = 0, arr[6][5] = 0, arr[6][6] = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", SecondMST(arr, m, n)); // Result: 62

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 5. Second Maximum Spanning Tree
int SecondMST(int** arr, int m, int n)
{
	// Write your code here.

	return -1;
}