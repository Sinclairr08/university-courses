/*================================================================================
* Written date : 2018.03.15
* Lastest revised date : 2018.03.17
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P1_GeneralTest();

// Examples
void P1_Test1();
void P1_Test2();
void P1_Test3();
void P1_Test4();

// Problem 1. Finding the Highest Slope
int HighestSlope(int n, int h[]);

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
	int n;
	int h[20];
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &h[i]);

	printf("%d\n", HighestSlope(n, h));
}

// Example 1
void P1_Test1()
{
	int n = 12;
	int h[12] = { 0, 6, 10, 8, 14, 7, 11, 12, 17, 5, 9, 0 };

	printf("%d\n", HighestSlope(n, h)); // Result: 12
}

// Example 2
void P1_Test2()
{
	int n = 6;
	int h[6] = { 0, 10, 20, 30, 5, 0 };

	printf("%d\n", HighestSlope(n, h)); // Result: 30
}
// Example 3
void P1_Test3()
{
	int n = 10;
	int h[10] = { 0, 1, 2, 3, 5, 7, 10, 11, 13, 0 };

	printf("%d\n", HighestSlope(n, h)); // Result: 13
}
// Example 4
void P1_Test4()
{
	int n = 13;
	int h[13] = { 0, 2, 6, 4, 8, 2, 1, 3, 3, 3, 8, 5, 0 };

	printf("%d\n", HighestSlope(n, h)); // Result: 6
}

// Problem 1. Finding the Highest Slope
int HighestSlope(int n, int h[])
{
	int max = 0;
	int accmul = 1;									// For the case when adjacent slopes are same
	int slop_now, slop_prev = 0;					// To check whether the previous and current slope is sameor not

	for (int i = 0; i < n - 1; i++) {
		slop_now = h[i + 1] - h[i];					// Contains sign

		if (slop_now == slop_prev)					// When previous and current slopes are same, increase accmul
			accmul++;								

		else
			accmul = 1;								// If slope is changed, initialize accmul to 1


		if (accmul * abs(slop_now) > max)			// Abs function is needed to remove the sign
			max = accmul * abs(slop_now);

		slop_prev = slop_now;						// Save the current slope at the previous slope
	}

	return max;
}
