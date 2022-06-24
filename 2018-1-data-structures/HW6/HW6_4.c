/*================================================================================
* Written date : 2018.06.12
* Lastest revised date : 2018.06.12
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

// Input the number from the user.
void P4_GeneralTest();

// Examples
void P4_Test1();
void P4_Test2();
void P4_Test3();
void P4_Test4();

// Problem 4. Finding The Number Of Friends To Invite
int FindTheNumberOfFriends(int** arr, int m, int n);

void Fillfriends(int* friends, int** arr, int name, int m);

int main()
{
	P4_GeneralTest();

	//P4_Test1();
	//P4_Test2();
	//P4_Test3();
	//P4_Test4();

	return 0;
}

// Input the number from the user.
void P4_GeneralTest()
{
	int m;
	int n;
	int i, j;

	scanf("%d", &n);

	scanf("%d", &m);

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int **)malloc(sizeof(int*)* 2);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("%d", FindTheNumberOfFriends(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 1
void P4_Test1()
{
	int m = 5;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int)* 2);

	arr[0][0] = 1, arr[0][1] = 3;
	arr[1][0] = 3, arr[1][1] = 4;	
	arr[2][0] = 2, arr[2][1] = 4;
	arr[3][0] = 4, arr[3][1] = 5;
	arr[4][0] = 5, arr[4][1] = 6;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindTheNumberOfFriends(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 2
void P4_Test2()
{
	int m = 12;
	int n = 10;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int) * 2);

	arr[0][0] = 1, arr[0][1] = 3;
	arr[1][0] = 1, arr[1][1] = 4;
	arr[2][0] = 2, arr[2][1] = 4;
	arr[3][0] = 5, arr[3][1] = 7;
	arr[4][0] = 6, arr[4][1] = 10;
	arr[5][0] = 4, arr[5][1] = 6;
	arr[6][0] = 4, arr[6][1] = 9;
	arr[7][0] = 3, arr[7][1] = 5;
	arr[8][0] = 2, arr[8][1] = 9;
	arr[9][0] = 3, arr[9][1] = 9;
	arr[10][0] = 5, arr[10][1] = 6;
	arr[11][0] = 3, arr[11][1] = 10;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindTheNumberOfFriends(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Example 3
void P4_Test3()
{
	int m = 6;
	int n = 6;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int) * 2);

	arr[0][0] = 1, arr[0][1] = 3;
	arr[1][0] = 1, arr[1][1] = 4;
	arr[2][0] = 2, arr[2][1] = 5;
	arr[3][0] = 5, arr[3][1] = 6;
	arr[4][0] = 3, arr[4][1] = 4;
	arr[5][0] = 3, arr[5][1] = 5;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindTheNumberOfFriends(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}


// Example 4
void P4_Test4()
{
	int m = 12;
	int n = 18;
	int i, j;

	int** arr = (int **)malloc(sizeof(int*)* m);
	for (i = 0; i < m; i++)
		arr[i] = (int *)malloc(sizeof(int) * 2);

	arr[0][0] = 1, arr[0][1] = 3;
	arr[1][0] = 1, arr[1][1] = 4;
	arr[2][0] = 2, arr[2][1] = 4;
	arr[3][0] = 5, arr[3][1] = 7;
	arr[4][0] = 5, arr[4][1] = 10;
	arr[5][0] = 7, arr[5][1] = 8;
	arr[6][0] = 7, arr[6][1] = 9;
	arr[7][0] = 10, arr[7][1] = 11;
	arr[8][0] = 10, arr[8][1] = 18;
	arr[9][0] = 11, arr[9][1] = 12;
	arr[10][0] = 12, arr[10][1] = 13;
	arr[11][0] = 13, arr[11][1] = 14;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}

	printf("%d", FindTheNumberOfFriends(arr, m, n));

	for (i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

// Problem 4. Finding The Number Of Friends To Invite
int FindTheNumberOfFriends(int** arr, int m, int n)
{
	int i;
	int* friends = (int*)malloc(sizeof(int) * (n + 1));
	
	for (i = 0; i <= n; i++)
		friends[i] = 0;

	Fillfriends(friends, arr, 1, m);
	Fillfriends(friends, arr, 2, m);

	friends[1] = friends[2] = 0;

	for (i = 1; i <= n; i++)
		if (friends[i] == -1)
			friends[i] += 2;

	for (i = 1; i <= n; i++)
	{
		if (friends[i] == 1)
			Fillfriends(friends, arr, i, m);
	}

	friends[1] = friends[2] = 0;

	for (i = 1; i <= n; i++)
		if (friends[i] == -1)
			friends[i] += 2;

	int sum = 0;

	for (i = 1; i <= n; i++)
		sum += friends[i];

	free(friends);

	return sum;
}

void Fillfriends(int* friends, int** arr, int name, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (arr[i][0] == name && !friends[arr[i][1]])
			friends[arr[i][1]] = -1;

		else if (arr[i][1] == name && !friends[arr[i][0]])
			friends[arr[i][0]] = -1;

	}
}