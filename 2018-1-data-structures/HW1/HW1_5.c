/*================================================================================
* Written date : 2018.03.16
* Lastest revised date : 2018.03.16
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Do not import any libraries for sorting algorithms.

// Write your student id, name, and discusser.
// StudentID: 2014310407
// Name: JunHyuk Lee
// Discusser: Nobody

typedef struct
{
	int diameter;
	char color[11];
} frisbee;

// Input the number from the user.
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();

// Problem 5. Sorting the Frisbees
void SortFrisbee(int N, frisbee flist[]);

int compare_string(char str1[], char str2[]);
int alp_order(char c);

int main()
{
	P5_GeneralTest();
	
	/*
	P5_Test1();
	printf("\n");
	P5_Test2();
	printf("\n");
	P5_Test3();
	printf("\n");
	P5_Test4();
	printf("\n");
	*/

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
{
	int N;
	frisbee flist[10];
	int d;
	char c[10];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %s", &flist[i].diameter, flist[i].color);
	SortFrisbee(N, flist);
}

// Example 1
void P5_Test1()
{
	int N = 4;
	frisbee flist[4] = { { 6, "Blue" },{ 2, "Red" },{ 8, "Green" },{ 4, "Yellow" } };

	SortFrisbee(N, flist);
}

// Example 2
void P5_Test2()
{
	int N = 7;
	frisbee flist[7] = { { 3, "Orange" },{ 8, "Navyblue" },{ 4, "Yellow" },{ 1, "Red" },{ 6,"Blue" },{ 9, "Purple" },{ 5, "Green" } };

	SortFrisbee(N, flist);
}
// Example 3
void P5_Test3()
{
	int N = 4;
	frisbee flist[4] = { { 5, "Red" },{ 5, "Blue" },{ 5, "Blue" },{ 5, "Green" } };

	SortFrisbee(N, flist);
}
// Example 4
void P5_Test4()
{
	int N = 5;
	frisbee flist[5] = { { 11, "Skyblue" },{ 14, "Violet" },{ 12, "Ashgray" },{ 13, "Vermillion" },{ 11, "Blackpink" } };

	SortFrisbee(N, flist);
}


// Problem 5. Sorting the Frisbees
void SortFrisbee(int N, frisbee flist[])
{
	int i, j;										
	frisbee temp;									// To sort the frisbee, one temporary frisbee is required

	for (i = 1; i < N; i++) {
		temp = flist[i];

		j = i - 1;									
		while (j >= 0 && flist[j].diameter >= temp.diameter) {			// From i - 1 to 0, search them until find the smaller frisbee

			// If there are frisbees that are having same diameters
			if (flist[j].diameter == temp.diameter) {				
			
				// If the currently checked one's color is placed in front of temp, in alphabetical order, than stops the while roof.
				if (compare_string(flist[j].color, temp.color) == 1)	// compare_string returns 1 if the first element is placed in front of later one in alphabetical order
					break;
			}

			flist[j + 1] = flist[j];									// Shift the frisbees
			j--;
		}

		flist[j + 1] = temp;											// Set the lastest shifted frisbee as temp

	}

	// print
	for (i = 0; i < N; i++)
		printf("%s\n", flist[i].color);
}


/*
* This function compares the first and second string, in alphabetical order
* If the first one is in front of later one, return 1, opposite case, return -1
* If two strings are identically same, return 0
*/
int compare_string(char str1[], char str2[])
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {	// Until the end of string1 or string2
		if (alp_order(str1[i]) < alp_order(str2[i]))
			return 1;

		else if (alp_order(str1[i]) > alp_order(str2[i]))
			return -1;

		else										// If two string's ith elements are same
			i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')			// If two strings are identically same
		return 0;

	else if (str1[i] == '\0')						// When first string is shorter
		return 1;

	else											// When second string is shorter
		return -1;	
}

/*
 * The function which returns the value of alphabet 
 * which follows the order of dictionary
 * i,e, A < a < B < b < ... and so on.
 * if the input is not the alphabet, returns -1
 */

int alp_order(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 2 * (c - 'A');						// Upper case returns even

	if (c >= 'a' && c <= 'z')
		return 2 * (c - 'a') + 1;					// Lower case returns odd

	return -1;
}