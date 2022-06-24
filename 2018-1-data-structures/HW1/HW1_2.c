/*================================================================================
* Written date : 2018.03.15
* Lastest revised date : 2018.03.15
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

// Problem 2. Counting Number of Possible Paths
int PossiblePath(int R, int C, int** s);

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
	int R, C;
	int** s;
	int i, j;

	scanf("%d %d", &R, &C);

	s = (int**)malloc(sizeof(int*) * R);
	for (i = 0; i < R; i++)
		s[i] = (int*)malloc(sizeof(int) * C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			scanf("%d", &s[i][j]);

	printf("%d\n", PossiblePath(R, C, s));

	for (i = 0; i < R; i++)
		free(s[i]);
	free(s);
}

// Example 1
void P2_Test1()
{
	int R = 3;
	int C = 4;
	int sample[3][4] = { {1, 1, 1, 1},
						 {1, 0, 0, 1},
						 {1, 1, 1, 1} };
	int i, j;

	int** s = (int**)malloc(sizeof(int*) * R);
	for (i = 0; i < R; i++)
		s[i] = (int*)malloc(sizeof(int) * C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			s[i][j] = sample[i][j];

	printf("%d\n", PossiblePath(R, C, s)); // Result: 2

	for (i = 0; i < R; i++)
		free(s[i]);
	free(s);
}

// Example 2
void P2_Test2()
{
	int R = 3;
	int C = 6;
	int sample[3][6] = { { 1, 1, 1, 1, 1, 1 },
					 	 { 1, 0, 0, 1, 0, 1 },
						 { 1, 1, 1, 1, 1, 1 } };
	int i, j;

	int** s = (int**)malloc(sizeof(int*) * R);
	for (i = 0; i < R; i++)
		s[i] = (int*)malloc(sizeof(int) * C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			s[i][j] = sample[i][j];

	printf("%d\n", PossiblePath(R, C, s)); // Result: 3

	for (i = 0; i < R; i++)
		free(s[i]);
	free(s);
}
// Example 3
void P2_Test3()
{
	int R = 5;
	int C = 2;
	int sample[5][2] = { { 1, 1 },
						 { 1, 1 },
						 { 1, 1 },
						 { 1, 1 },
						 { 1, 1 } };
	int i, j;

	int** s = (int**)malloc(sizeof(int*) * R);
	for (i = 0; i < R; i++)
		s[i] = (int*)malloc(sizeof(int) * C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			s[i][j] = sample[i][j];

	printf("%d\n", PossiblePath(R, C, s)); // Result: 5

	for (i = 0; i < R; i++)
		free(s[i]);
	free(s);
}
// Example 4
void P2_Test4()
{
	int R = 4;
	int C = 4;
	int sample[4][4] = { { 1, 0, 1, 1 },
						 { 0, 1, 1, 1 },
						 { 1, 1, 1, 1 },
						 { 1, 1, 1, 1 } };
	int i, j;

	int** s = (int**)malloc(sizeof(int*) * R);
	for (i = 0; i < R; i++)
		s[i] = (int*)malloc(sizeof(int) * C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			s[i][j] = sample[i][j];

	printf("%d\n", PossiblePath(R, C, s)); // Result: 0

	for (i = 0; i < R; i++)
		free(s[i]);
	free(s);
}

// Problem 2. Counting Number of Possible Paths
int PossiblePath(int R, int C, int** s)
{
	int cnt = 0;
	int i, j;

	int** mark = (int**)malloc(sizeof(int*) * R);	// Make the same size of 2D-array to mark the number of possible ways
	
	for (i = 0; i < R; i++)
		mark[i] = (int*)malloc(sizeof(int) * C);
	

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (i == 0 && j == 0) {
				mark[i][j] = 1;						// Set mark[0][0] = 1
				continue;
			}

			mark[i][j] = 0;							// Firstly save every element as 0
			if (s[i][j] != 0) {						// If element is 0, that means there are no way, so mark[i][j] will be zero
				if (i != 0 && s[i - 1][j] != 0)
					mark[i][j] += mark[i - 1][j];	// If there is the way from the left, add the number of possible ways until the left one.

				if (j != 0 && s[i][j - 1] != 0)
					mark[i][j] += mark[i][j - 1];	// If there is the way from the up, add the number of possible ways until the up one.
			}

		}
	}

	cnt = mark[R-1][C-1];							// Last element of mark should be the total possible ways

	for (i = 0; i < R; i++)							// Free the memory
		free(mark[i]);
	free(mark);

	return cnt;
}