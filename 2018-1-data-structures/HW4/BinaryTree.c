#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"

// Create a new node.
BTreeNode * CreateNode(BData item)
{
	BTreeNode * node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

// Destroy a node.
void DestroyNode(BTreeNode * node)
{
	free(node);
}

// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode * left)
{
	if (root->left_child != NULL)
		exit(1);

	root->left_child = left;
}

// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode * right)
{
	if (root->right_child != NULL)
		exit(1);

	root->right_child = right;
}

// Traverse a tree.
void Inorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Inorder(root->left_child);
		printf("%d ", root->item);
		Inorder(root->right_child);
	}
}

void Preorder(BTreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->item);
		Preorder(root->left_child);
		Preorder(root->right_child);
	}
}

void Postorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Postorder(root->left_child);
		Postorder(root->right_child);
		printf("%d ", root->item);
	}
}

void Levelorder(BTreeNode* root)
{
	Queue queue;
	if (root == NULL) return;

	InitQueue(&queue);
	EnQueue(&queue, root);
	while (!IsEmpty(&queue))
	{
		root = Peek(&queue);
		DeQueue(&queue);

		printf("%d ", root->item);
		if (root->left_child != NULL)
			EnQueue(&queue, root->left_child);
		if (root->right_child != NULL)
			EnQueue(&queue, root->right_child);
	}
}

// Build a tree from an array list.
BTreeNode* BuildTree(BData* arr, int n)
{
	int i;
	BTreeNode* root;
	BTreeNode ** tree = (BTreeNode **)malloc(sizeof(BTreeNode*)* n);

	for (i = 0; i < n; i++) {
		if (arr[i] == 0)	// Avoid generating a node.
			continue;

		if (i == 0)
			tree[0] = CreateNode(arr[i]);
		else if (i % 2 == 0) {
			tree[i] = CreateNode(arr[i]);
			CreateRightSubtree(tree[(i - 1) / 2], tree[i]);
		}
		else {
			tree[i] = CreateNode(arr[i]);
			CreateLeftSubtree(tree[(i - 1) / 2], tree[i]);
		}
	}

	root = tree[0];
	free(tree);

	return root;
}

// Clear a tree.
void ClearTree(BTreeNode* root)
{
	if (root != NULL)
	{
		ClearTree(root->left_child);
		ClearTree(root->right_child);
		DestroyNode(root);
	}
}