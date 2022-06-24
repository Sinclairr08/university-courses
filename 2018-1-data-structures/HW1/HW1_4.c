/*================================================================================
* Written date : 2018.03.16
* Lastest revised date : 2018.03.16
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

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

// Problem 4. Counting Possible Stones
int PossibleStones(int R, int C, int x, int y);

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
	int R, C, x, y;
	scanf("%d %d %d %d", &R, &C, &x, &y);

	printf("%d\n", PossibleStones(R, C, x, y));
}

// Example 1
void P4_Test1()
{
	int R = 4;
	int C = 4;
	int x = 0;
	int y = 1;

	printf("%d\n", PossibleStones(R, C, x, y)); // Result: 5
}

// Example 2
void P4_Test2()
{
	int R = 7;
	int C = 7;
	int x = 5;
	int y = 4;

	printf("%d\n", PossibleStones(R, C, x, y)); // Result: 16
}
// Example 3
void P4_Test3()
{
	int R = 4;
	int C = 4;
	int x = 0;
	int y = 0;

	printf("%d\n", PossibleStones(R, C, x, y)); // Result: 6
}
// Example 4
void P4_Test4()
{
	int R = 3;
	int C = 7;
	int x = 1;
	int y = 3;

	printf("%d\n", PossibleStones(R, C, x, y)); // Result: 7
}

// Problem 4. Counting Possible Stones
int PossibleStones(int R, int C, int x, int y)
{
	int cnt = 0;											// To count the number of possible stones

	for(int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			if ((abs(row - x) + abs(col - y)) % 3 == 0)		// If the sum of difference of current (row,col) to (x,y) is multiple of 3
				cnt++;
	
	return cnt;
}