/*================================================================================
* Written date : 2018.05.06
* Lastest revised date : 2018.05.06
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

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

// Problem 4. Invisible Nodes
int InvisibleNodes(BTreeNode * root, int view);

int Sum(BTreeNode * node);
int Log2(int num, int tail);

inline int is_left(BTreeNode * node);
inline int is_right(BTreeNode * node);

int main()
{
	P4_GeneralTest();
	
	/*P4_Test1();
	P4_Test2();
	P4_Test3();
	P4_Test4();*/

	return 0;
}

// Input the number from the user.
void P4_GeneralTest()
{
	int n, i;
	int* arr;
	BTreeNode* root;
	int view;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &view);

	root = BuildTree(arr, n);
	printf("%d\n", InvisibleNodes(root, view));
	ClearTree(root);
	free(arr);
}

// Example 1
void P4_Test1()
{
	int n = 3;
	int sample[3] = { 1, 2, 3 };
	int view = 0;
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", InvisibleNodes(root, view)); // result : 3
	ClearTree(root);
	free(arr);
}

// Example 2
void P4_Test2()
{
	int n = 7;
	int sample[7] = { 1, 1, 0, 1, 0, 0, 0 };
	int view = 1;
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", InvisibleNodes(root, view)); // result : 0
	ClearTree(root);
	free(arr);
}

// Example 3
void P4_Test3()
{
	int n = 23;
	int sample[23] = { 5, 2, 3, 1, 3, 0, 6, 2, 4, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };
	int view = 0;
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", InvisibleNodes(root, view)); // result : 26
	ClearTree(root);
	free(arr);
}

// Example 4
void P4_Test4()
{
	int n = 23;
	int sample[23] = { 5, 2, 3, 1, 3, 0, 6, 2, 4, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };
	int view = 1;
	int* arr;
	int i;
	BTreeNode* root;

	arr = (int *)malloc(sizeof(int)* n);
	for (i = 0; i < n; i++)
		arr[i] = sample[i];

	root = BuildTree(arr, n);
	printf("%d\n", InvisibleNodes(root, view)); // result : 13
	ClearTree(root);
	free(arr);
}

// Problem 4. Invisible Nodes
int InvisibleNodes(BTreeNode * root, int view)
{
	if(root == NULL)
		return -1;
		
	int level = 0, que_cnt = 0;
	int level_cnt[5] = {0};
	BTreeNode* node;

	Queue que;
	InitQueue(&que);

	EnQueue(&que, root);

	while (!IsEmpty(&que) && que_cnt < 31)
	{
		node = Peek(&que), DeQueue(&que);
		que_cnt++;

		if (node == NULL)
		{
			EnQueue(&que, NULL);
			EnQueue(&que, NULL);
			continue;
		}

		else
		{
			if(is_left(node))
				EnQueue(&que, node->left_child);

			else
				EnQueue(&que, NULL);

			if (is_right(node))
				EnQueue(&que, node->right_child);

			else
				EnQueue(&que, NULL);

			level = Log2(que_cnt, 0);

			if (view == 0)
			{
				if (level_cnt[level] == 0)
					level_cnt[level] = node->item;
			}

			else
				level_cnt[level] = node->item;
		}


	} //end of while
		
	int sum = Sum(root);

	for (int i = 0; i < 5; i++)
		sum -= level_cnt[i];
	
	return sum;

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


int Log2(int num, int tail) {
	if (num == 1)
		return tail;

	else
		return Log2(num / 2, tail + 1);
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