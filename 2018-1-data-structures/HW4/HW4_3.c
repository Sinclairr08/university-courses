/*================================================================================
* Written date : 2018.05.06
* Lastest revised date : 2018.05.06
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
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();

// Problem 3. Balancing Weights
int BalancingWeights(BTreeNode * root);

int Sum(BTreeNode * node);

inline int is_leaf(BTreeNode * node);
inline int is_left(BTreeNode * node);
inline int is_right(BTreeNode * node);

int main()
{
	P3_GeneralTest();

	/*P3_Test1();
	P3_Test2();
	P3_Test3();
	P3_Test4();*/

	return 0;
}

// Input the number from the user.
void P3_GeneralTest()
{
	int n, i;
	int* arr;
	BTreeNode* root;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	root = BuildTree(arr, n);
	printf("%d\n", BalancingWeights(root));
	ClearTree(root);
	free(arr);
}

// Example 1
void P3_Test1()
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
	printf("%d\n", BalancingWeights(root)); // result : 1
	ClearTree(root);
	free(arr);
}

// Example 2
void P3_Test2()
{
	int n = 9;
	int sample[9] = { 1, 1, 3, 2, 1, 1, 3, 2, 1 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", BalancingWeights(root)); // result : 12
	ClearTree(root);
	free(arr);
}

// Example 3
void P3_Test3()
{
	int n = 7;
	int sample[13] = { 1, 2, 2, 3, 3, 3, 3 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", BalancingWeights(root)); // result : 0
	ClearTree(root);
	free(arr);
}

// Example 4
void P3_Test4()
{
	int n = 15;
	int sample[15] = { 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", BalancingWeights(root)); // result : 8
	ClearTree(root);
	free(arr);
}

// Problem 3. Balancing Weights
int BalancingWeights(BTreeNode * root)
{
	if(root == NULL)
		return -1;

	if (is_leaf(root))
		return 0;

	int weight = 0, left = 0, right = 0;

	if (is_left(root))
	{
		weight += BalancingWeights(root->left_child);
		left = Sum(root->left_child);
	}

	if (is_right(root))
	{
		weight += BalancingWeights(root->right_child);
		right = Sum(root->right_child);
	}

	
	if (left > right)
	{
		weight += left - right;
		root->right_child->item += left - right;
	}

	else if (left < right)
	{
		weight += right - left;
		root->right_child->item += right - left;
	}

	return weight;

}

int Sum(BTreeNode * node)
{
	if (node != NULL)
	{
		int sum = 0;

		sum += Sum(node->left_child);
		sum += Sum(node->right_child);

		return sum + node->item;
	}

	return 0;
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