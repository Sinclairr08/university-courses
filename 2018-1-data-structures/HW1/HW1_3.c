/*================================================================================
* Written date : 2018.03.15 ~ 2018.03.16
* Lastest revised date : 2018.03.16
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody


// Input the number from the user.
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();

// Problem 3. Overlapping Area of Two Rectangles
int OverlappingArea(int a1[2], int a2[2], int b1[2], int b2[2]);

inline int max(int x, int y);
inline int min(int x, int y);

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
	int a1[2], a2[2], b1[2], b2[2];

	scanf("%d %d", &a1[0], &a1[1]);
	scanf("%d %d", &a2[0], &a2[1]);
	scanf("%d %d", &b1[0], &b1[1]);
	scanf("%d %d", &b2[0], &b2[1]);

	printf("%d\n", OverlappingArea(a1, a2, b1, b2));
}

// Example 1
void P3_Test1()
{
	int a1[2] = { 0, 0 };
	int a2[2] = { 5, 5 };
	int b1[2] = { 1, 1 };
	int b2[2] = { 4, 4 };

	printf("%d\n", OverlappingArea(a1, a2, b1, b2)); // Result: 9
}

// Example 2
void P3_Test2()
{
	int a1[2] = { -3, 0 };
	int a2[2] = { 3, 5 };
	int b1[2] = { -2, -4 };
	int b2[2] = { 4, 1 };

	printf("%d\n", OverlappingArea(a1, a2, b1, b2)); // Result: 5
}
// Example 3
void P3_Test3()
{
	int a1[2] = { -1, -1 };
	int a2[2] = { 1, 1 };
	int b1[2] = { 3, 3 };
	int b2[2] = { 5, 5 };

	printf("%d\n", OverlappingArea(a1, a2, b1, b2)); // Result: 0
}
// Example 4
void P3_Test4()
{
	int a1[2] = { 4, 2 };
	int a2[2] = { 5, 8 };
	int b1[2] = { 3, 3 };
	int b2[2] = { 6, 5 };

	printf("%d\n", OverlappingArea(a1, a2, b1, b2)); // Result: 2
}

// Problem 3. Overlapping Area of Two Rectangles
int OverlappingArea(int a1[2], int a2[2], int b1[2], int b2[2])
{
	int a_width = a2[0] - a1[0];				// width of a
	int a_height = a2[1] - a1[1];				// height of a

	int b_width = b2[0] - b1[0];				// width of b
	int b_height = b2[1] - b1[1];				// height of a

	int ovlap_width, ovlap_height;				
	int max_x, min_x, max_y, min_y;

	max_x = max(a2[0], b2[0]);	
	min_x = min(a1[0], b1[0]);

	max_y = max(a2[1], b2[1]);
	min_y = min(a1[1], b1[1]);

	ovlap_width = a_width + b_width - (max_x - min_x);		// overlapped width is difference of (addition of two rectangle) and (difference of max_x, min_x)
	ovlap_height = a_height + b_height - (max_y - min_y);	// same as width

	if (ovlap_width < 0)									// In the case when rectangles are not overlapped
		return 0;

	if (ovlap_height < 0)									// Also not overlapped case
		return 0;

	return ovlap_width * ovlap_height;
}

// Function that returns the max value of two integers
inline int max(int x, int y) {
	if (x >= y)
		return x;
	return y;
}

// Function that returns the min value of two integers
inline int min(int x, int y) {
	if (x <= y)
		return x;
	return y;
}