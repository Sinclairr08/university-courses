#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef enum { false, true } bool;

typedef int Key;

typedef struct _BSTNode
{
	Key key;
	struct _BSTNode * left_child;
	struct _BSTNode * right_child;
} BSTNode;

// Create a new node.
BSTNode * CreateNode(Key key);

// Destroy a node.
void DestroyNode(BSTNode * node);

// Connect the root to a left child node.
void CreateLeftSubtree(BSTNode* root, Key key);

// Connect the root to a right child node.
void CreateRightSubtree(BSTNode* root, Key key);

// Insert an item to BST.
void Insert(BSTNode* root, Key key);

BSTNode* FindMin(BSTNode* node);

// Remove an item from BST
BSTNode* Remove(BSTNode* root, Key key);

#endif