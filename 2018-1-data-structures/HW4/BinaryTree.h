#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef int BData;

typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode * left_child;
	struct _bTreeNode * right_child;
} BTreeNode;

// Create a new node.
BTreeNode * CreateNode(BData item);
// Destroy a node.
void DestroyNode(BTreeNode * node);

// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode * left);
// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode * right);

// Traverse a tree.
void Inorder(BTreeNode* root);
void Preorder(BTreeNode* root);
void Postorder(BTreeNode* root);
void Levelorder(BTreeNode* root);

// Build a tree from an array list.
BTreeNode * BuildTree(BData* arrays, int n);
// Clear a tree.
void ClearTree(BTreeNode* root);


#endif _BINARY_TREE_H_