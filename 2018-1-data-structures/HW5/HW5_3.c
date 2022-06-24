/*================================================================================
* Written date : 2018.05.19
* Lastest revised date : 2018.05.19
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
void P3_GeneralTest();

// Examples
void P3_Test1();
void P3_Test2();
void P3_Test3();
void P3_Test4();


// Problm 3. Find Median In BST
int MedianInBST(BSTNode * root);

int Nums(BSTNode * root);
void Inorder_save(BSTNode * root, int* arr, int* index);

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
	int n, i;
	BSTNode* root;

	scanf("%d", &n);
	int* arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)		scanf("%d", &arr[i]);

	root = CreateNode(arr[0]);
	for (i = 1; i < n; i++) Insert(root, arr[i]);

	printf("%d\n", MedianInBST(root));
	free(arr);
}

// Example 1
void P3_Test1()
{
	BSTNode* root;

	int n = 2;
	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 1, arr[1] = 2;

	root = CreateNode(arr[0]);
	Insert(root, arr[1]);

	printf("%d\n", MedianInBST(root));	// result = 3
	free(arr);
}

// Example 2
void P3_Test2()
{
	BSTNode* root;

	int n = 3;
	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 1, arr[1] = 2, arr[2] = 3;

	root = CreateNode(arr[0]);
	Insert(root, arr[1]);
	Insert(root, arr[2]);

	printf("%d\n", MedianInBST(root));
	free(arr);
}

// Example 3
void P3_Test3()
{
	BSTNode* root;

	int n = 8;
	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 5, arr[1] = 2, arr[2] = 7, arr[3] = 1, arr[4] = 4, arr[5] = 6, arr[6] = 8, arr[7] = 3;

	root = CreateNode(arr[0]);
	Insert(root, arr[1]);
	Insert(root, arr[2]);
	Insert(root, arr[3]);
	Insert(root, arr[4]);
	Insert(root, arr[5]);
	Insert(root, arr[6]);
	Insert(root, arr[7]);

	printf("%d\n", MedianInBST(root));
	free(arr);
}

// Example 4
void P3_Test4()
{
	BSTNode* root;

	int n = 9;
	int* arr = (int *)malloc(sizeof(int)* n);
	arr[0] = 8, arr[1] = 3, arr[2] = 10, arr[3] = 2, arr[4] = 5, arr[5] = 14, arr[6] = 4, arr[7] = 11, arr[8] = 16;

	root = CreateNode(arr[0]);
	Insert(root, arr[1]);
	Insert(root, arr[2]);
	Insert(root, arr[3]);
	Insert(root, arr[4]);
	Insert(root, arr[5]);
	Insert(root, arr[6]);
	Insert(root, arr[7]);
	Insert(root, arr[8]);

	printf("%d\n", MedianInBST(root));
	free(arr);
}

// Problm 3. Find Median In BST
int MedianInBST(BSTNode * root)
{
	int tree_size = Nums(root), median_sum;
	int* arr = (int*)malloc(sizeof(int) * tree_size);
	int index = 0;

	Inorder_save(root, arr, &index);

	if (tree_size % 2 == 0)
		median_sum = arr[tree_size / 2 - 1] + arr[tree_size / 2];

	else
		median_sum = arr[tree_size / 2];
	
	free(arr);
	return median_sum;
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

void Inorder_save(BSTNode * root, int* arr, int* index)
{
	if (root != NULL)
	{
		Inorder_save(root->left_child, arr, index);
		arr[(*index)++] = root->key;
		Inorder_save(root->right_child, arr, index);
	}
}
