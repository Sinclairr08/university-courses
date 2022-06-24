/*================================================================================
* Written date : 2018.05.20
* Lastest revised date : 2018.05.20
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

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


// Problem 4. BSTs with Same Structures
int SameStructure(BSTNode * root1, BSTNode *root2, int n);

inline bool is_left(BSTNode * node);
inline bool is_right(BSTNode * node);
inline bool is_leaf(BSTNode * node);

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
	int n, i;
	BSTNode* root1;
	BSTNode* root2;


	scanf("%d", &n);

	int* arr1 = (int *)malloc(sizeof(int)* n);
	int* arr2 = (int *)malloc(sizeof(int)* n);

	for (i = 0; i < n; i++)		scanf("%d", &arr1[i]);
	for (i = 0; i < n; i++)		scanf("%d", &arr2[i]);


	root1 = CreateNode(arr1[0]);
	for (i = 1; i < n; i++) Insert(root1, arr1[i]);

	root2 = CreateNode(arr2[0]);
	for (i = 1; i < n; i++) Insert(root2, arr2[i]);

	printf("%d\n", SameStructure(root1, root2, n));

	free(arr1);
	free(arr2);
}

// Example 1
void P4_Test1()
{
	int i;
	BSTNode* root1;
	BSTNode* root2;

	int n = 5;

	int* arr1 = (int *)malloc(sizeof(int)* n);
	int* arr2 = (int *)malloc(sizeof(int)* n);

	arr1[0] = 5, arr1[1] = 4, arr1[2] = 6, arr1[3] = 2, arr1[4] = 7;
	arr2[0] = 3, arr2[1] = 2, arr2[2] = 4, arr2[3] = 1, arr2[4] = 5;

	root1 = CreateNode(arr1[0]);
	for (i = 1; i < n; i++) Insert(root1, arr1[i]);

	root2 = CreateNode(arr2[0]);
	for (i = 1; i < n; i++) Insert(root2, arr2[i]);

	printf("%d\n", SameStructure(root1, root2, n));			// result = 1

	free(arr1);
	free(arr2);
}

// Example 2
void P4_Test2()
{
	int i;
	BSTNode* root1;
	BSTNode* root2;

	int n = 5;

	int* arr1 = (int *)malloc(sizeof(int)* n);
	int* arr2 = (int *)malloc(sizeof(int)* n);

	arr1[0] = 5, arr1[1] = 6, arr1[2] = 4, arr1[3] = 7, arr1[4] = 2;
	arr2[0] = 6, arr2[1] = 4, arr2[2] = 7, arr2[3] = 2, arr2[4] = 5;

	root1 = CreateNode(arr1[0]);
	for (i = 1; i < n; i++) Insert(root1, arr1[i]);

	root2 = CreateNode(arr2[0]);
	for (i = 1; i < n; i++) Insert(root2, arr2[i]);

	printf("%d\n", SameStructure(root1, root2, n));			// result = 0

	free(arr1);
	free(arr2);
}

// Example 3
void P4_Test3()
{
	int i;
	BSTNode* root1;
	BSTNode* root2;

	int n = 3;

	int* arr1 = (int *)malloc(sizeof(int)* n);
	int* arr2 = (int *)malloc(sizeof(int)* n);

	arr1[0] = 1, arr1[1] = 2, arr1[2] = 3;
	arr2[0] = 2, arr2[1] = 1, arr2[2] = 3;

	root1 = CreateNode(arr1[0]);
	for (i = 1; i < n; i++) Insert(root1, arr1[i]);

	root2 = CreateNode(arr2[0]);
	for (i = 1; i < n; i++) Insert(root2, arr2[i]);

	printf("%d\n", SameStructure(root1, root2, n));			// result = 0

	free(arr1);
	free(arr2);
}

// Example 4
void P4_Test4()
{
	int i;
	BSTNode* root1;
	BSTNode* root2;

	int n = 8;

	int* arr1 = (int *)malloc(sizeof(int)* n);
	int* arr2 = (int *)malloc(sizeof(int)* n);

	arr1[0] = 1, arr1[1] = 2, arr1[2] = 3, arr1[3] = 4, arr1[4] = 5, arr1[5] = 6, arr1[6] = 7, arr1[7] = 8;
	arr2[0] = 9, arr2[1] = 10, arr2[2] = 11, arr2[3] = 12, arr2[4] = 13, arr2[5] = 14, arr2[6] = 15, arr2[7] = 16;

	root1 = CreateNode(arr1[0]);
	for (i = 1; i < n; i++) Insert(root1, arr1[i]);

	root2 = CreateNode(arr2[0]);
	for (i = 1; i < n; i++) Insert(root2, arr2[i]);

	printf("%d\n", SameStructure(root1, root2, n));			// result = 1

	free(arr1);
	free(arr2);
}

// Problem 4. BSTs with Same Structures
int SameStructure(BSTNode * root1, BSTNode *root2, int n)
{
	bool left = false, right = false;
	
	if (is_leaf(root1) && is_leaf(root2))
		return true;

	if (is_left(root1) && is_left(root2))
		left = SameStructure(root1->left_child, root2->left_child, n);

	else if (!is_left(root1) && !is_left(root2))
		left = true;

	if (is_right(root1) && is_right(root2))
		right = SameStructure(root1->right_child, root2->right_child, n);

	else if (!is_right(root1) && !is_right(root2))
		right = true;

	return left && right;
}

inline bool is_left(BSTNode * node)
{
	return node->left_child == NULL ? false : true;
}

inline bool is_right(BSTNode * node)
{
	return node->right_child == NULL ? false : true;
}

inline bool is_leaf(BSTNode * node)
{
	return !is_left(node) && !is_right(node) ? true : false;
}