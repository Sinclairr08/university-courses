/*================================================================================
* Written date : 2018.05.05
* Lastest revised date : 2018.05.05
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

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

// Problem 1. Sum of Leaves
int SumOfLeaves(BTreeNode * root);
inline int is_leaf(BTreeNode * node);
inline int is_left(BTreeNode * node);
inline int is_right(BTreeNode * node);

int main()
{
	P1_GeneralTest();

	/*P1_Test1();
	P1_Test2();
	P1_Test3();
	P1_Test4();*/

	return 0;
}

// Input the number from the user.
void P1_GeneralTest()
{
	int n, i;
	int* arr;
	BTreeNode* root;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	root = BuildTree(arr, n);
	printf("%d\n", SumOfLeaves(root));
	ClearTree(root);
	free(arr);
}

// Example 1
void P1_Test1()
{
	int n = 3;
	int sample[3] = { 1, 2, 3 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", SumOfLeaves(root)); // result : 5
	ClearTree(root);
	free(arr);
}

// Example 2
void P1_Test2()
{
	int n = 9;
	int sample[9] = { 3, 2, 8, 1, 5, 4, 9, 4, 3 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", SumOfLeaves(root)); // result : 25
	ClearTree(root);
	free(arr);
}

// Example 3
void P1_Test3()
{
	int n = 13;
	int sample[13] = { 5, 2, 13, 0, 4, 10, 9, 0, 0, 7, 0, 1, 16 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", SumOfLeaves(root)); // result : 33
	ClearTree(root);
	free(arr);
}

// Example 4
void P1_Test4()
{
	int n = 23;
	int sample[23] = { 1, 2, 2, 1, 3, 1, 1, 2, 1, 1, 3, 2, 3, 0, 2, 2, 1, 0, 0, 0, 0, 2, 2 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", SumOfLeaves(root)); // result : 16
	ClearTree(root);
	free(arr);
}

// Problem 1. Sum of Leaves
int SumOfLeaves(BTreeNode * root)
{
	if (root == NULL)
		return -1;
	
	if (is_leaf(root))
		return root->item;

	int sum = 0;

	if (is_left(root))
		sum += SumOfLeaves(root->left_child);
	
	if (is_right(root))
		sum += SumOfLeaves(root->right_child);

	return sum;
	
}

inline int is_leaf(BTreeNode * node)
{
	if (!is_left(node) && !is_right(node))
		return 1;

	return 0;
}

inline int is_left(BTreeNode * node)
{
	if (node->left_child == NULL)
		return 0;

	return 1;

}
inline int is_right(BTreeNode * node)
{
	if (node->right_child == NULL)
		return 0;

	return 1;
}