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
void P5_GeneralTest();

// Examples
void P5_Test1();
void P5_Test2();
void P5_Test3();
void P5_Test4();

// Problem 5. Least Common Ancestor
int LCA(BTreeNode * root, int depth);

inline int is_leaf(BTreeNode * node);
inline int is_left(BTreeNode * node);
inline int is_right(BTreeNode * node);

int main()
{
	P5_GeneralTest();

	/*P5_Test1();
	P5_Test2();
	P5_Test3();
	P5_Test4();*/

	return 0;
}

// Input the number from the user.
void P5_GeneralTest()
{
	int n, i;
	int* arr;
	BTreeNode* root;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	root = BuildTree(arr, n);
	printf("%d\n", LCA(root, 0));
	ClearTree(root);
	free(arr);
}

// Example 1
void P5_Test1()
{
	int n = 7;
	int sample[7] = { 1, 1, 1, 2, 2, 1, 1 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", LCA(root, 0)); // result : 1
	ClearTree(root);
	free(arr);
}

// Example 2
void P5_Test2()
{
	int n = 15;
	int sample[15] = { 2, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", LCA(root, 0)); // result : 0
	ClearTree(root);
	free(arr);
}

// Example 3
void P5_Test3()
{
	int n = 23;
	int sample[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 2 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", LCA(root, 0)); // result : 2
	ClearTree(root);
	free(arr);
}

// Example 4
void P5_Test4()
{
	int n = 31;
	int sample[31] = { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 2, 0, 0 };
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", LCA(root, 0)); // result : 1
	ClearTree(root);
	free(arr);
}

// Problem 5. Least Common Ancestor
int LCA(BTreeNode * root, int depth)
{
	/* No Tree */
	if(root == NULL)
		return -1;

	/* If item is 2, mark the place */
	if (root->item == 2)
		return depth;

	/* If item is not 2 but itself is a leaf, return 0s */
	else if (is_leaf(root))
		return 0;

	int left_dep = 0, right_dep = 0;

	/* Recursively find the depth */
	if (is_left(root))
		left_dep = LCA(root->left_child, depth + 1);

	if (is_right(root))
		right_dep = LCA(root ->right_child, depth + 1);

	/* If 2 is not found either left or right */
	if (left_dep == 0 && right_dep == 0)
		return 0;

	/* If 2 is found both of left and right, then it is the place of LCA. Mark it */
	else if (left_dep != 0 && right_dep != 0)
		return depth;

	/* If only one of left or right contains 2 */
	else if (left_dep == 0)
		return right_dep;

	else
		return left_dep;
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