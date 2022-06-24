#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new node.
BSTNode * CreateNode(Key key)
{
	BSTNode * node = (BSTNode*)malloc(sizeof(BSTNode));
	node->key = key;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

// Destroy a node.
void DestroyNode(BSTNode * node)
{
	free(node);
}


// Connect the root to a left child node.
void CreateLeftSubtree(BSTNode* root, Key key)
{
	if (root->left_child != NULL)
		exit(1);
	else {
		BSTNode* node = CreateNode(key);
		root->left_child = node;
	}
}

// Connect the root to a right child node.
void CreateRightSubtree(BSTNode* root, Key key)
{
	if (root->right_child != NULL)
		exit(1);
	else {
		BSTNode* node = CreateNode(key);
		root->right_child = node;
	}
}

// Insert an item to BST.
void Insert(BSTNode* root, Key key)
{
	if (root->key == key) exit(1);
	else if (root->key > key) {
		if (root->left_child == NULL)
			CreateLeftSubtree(root, key);
		else
			Insert(root->left_child, key);
	}
	else {
		if (root->right_child == NULL)
			CreateRightSubtree(root, key);
		else
			Insert(root->right_child, key);
	}
}

// Remove an item from BST.
BSTNode* Remove(BSTNode* root, Key key)
{
	BSTNode *cur, *parent;

	parent = NULL;
	cur = root;
	while (cur != NULL && cur->key != key) {
		parent = cur;
		if (cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}

	if (cur == NULL) exit(1);

	if (cur->left_child == NULL && cur->right_child == NULL) {
		if (parent != NULL) {
			if (parent->left_child == cur) {
				parent->left_child = NULL;
			}
			else {
				parent->right_child = NULL;
			}
		}
		else
			root = NULL;
	}

	else if (cur->left_child == NULL || cur->right_child == NULL) {
		BSTNode* child;
		if (cur->left_child != NULL)
			child = cur->left_child;
		else
			child = cur->right_child;

		if (parent != NULL) {
			if (parent->left_child == cur)
				parent->left_child = child;
			else
				parent->right_child = child;
		}
		else
			root = child;
	}

	else {
		BSTNode* succ_parent = cur;
		BSTNode* succ = cur->right_child;

		while (succ->left_child != NULL) {
			succ_parent = succ;
			succ = succ->left_child;
		}

		if (succ_parent->left_child == succ)
			succ_parent->left_child = succ->right_child;
		else
			succ_parent->right_child = succ->right_child;

		cur->key = succ->key;
		cur = succ;
	}

	DestroyNode(cur);
	return root;
}

// Find mininum value from a tree.
BSTNode* FindMin(BSTNode* node) 
{
	BSTNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left_child != NULL)
		current = current->left_child;

	return current;
}
