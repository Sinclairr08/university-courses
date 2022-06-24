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
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();


// Problem 5. Number of Identical Trees
int NumOfTree(BSTNode * root, int *arr, int n);

int Nums(BSTNode * root);

inline bool is_left(BSTNode * node);
inline bool is_right(BSTNode * node);
inline bool is_leaf(BSTNode * node);

int factorial(int num);

int main()
{
	P5_GeneralTest();

	//P5_Test1();
	//P5_Test2();
	//P5_Test3();
	//P5_Test4();

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
{
	int n, i;
	BSTNode* root;

	scanf("%d", &n);

	int* arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)		scanf("%d", &arr[i]);

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", NumOfTree(root, arr, n));
	free(arr);
}

// Example 1
void P5_Test1()
{
	int n, i;
	BSTNode* root;

	n = 4;

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 3, arr[1] = 1, arr[2] = 2, arr[3] = 4;

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", NumOfTree(root, arr, n));			// result = 3
	free(arr);
}

// Example 2
void P5_Test2()
{
	int n, i;
	BSTNode* root;

	n = 5;

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 4, arr[1] = 5, arr[2] = 1, arr[3] = 2, arr[4] = 3;

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", NumOfTree(root, arr, n));			// result = 4
	free(arr);
}

// Example 3
void P5_Test3()
{
	int n, i;
	BSTNode* root;

	n = 5;

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4, arr[4] = 5;

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", NumOfTree(root, arr, n));		// result = 1
	free(arr);
}

// Example 4
void P5_Test4()
{
	int n, i;
	BSTNode* root;

	n = 7;

	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 4, arr[1] = 2, arr[2] = 6, arr[3] = 1, arr[4] = 3, arr[5] = 5, arr[6] = 7;

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", NumOfTree(root, arr, n));		// result = 80
	free(arr);
}

// Problem 5. Number of Identical Trees
int NumOfTree(BSTNode * root, int *arr, int n)
{
	if (is_leaf(root))
		return 1;

	int left = 1, right = 1;
	int left_num, right_num;

	if (is_left(root))
		left = NumOfTree(root->left_child, arr, n);

	left_num = Nums(root->left_child);

	if (is_right(root))
		right = NumOfTree(root->right_child, arr, n);
	
	right_num = Nums(root->right_child);

	int num_root = left_num + right_num;

	num_root = factorial(num_root) / (factorial(left_num) * factorial(right_num));

	return num_root * left * right;

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

int factorial(int num)
{
	int ret = 1;
	for (int i = 1; i <= num; i++)
		ret *= i;

	return ret;
}

int Nums(BSTNode * root)
{
	if (root != NULL)
	{
		int left = Nums(root->left_child);
		int right = Nums(root->right_child);

		return left + right + 1;
	}

	else
		return 0;
}