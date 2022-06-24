/*================================================================================
* Written date : 2018.05.03
* Lastest revised date : 2018.05.04
* ==================================================================================*/

#include "redblacktree.h"
#include <stdio.h>
#include <stdlib.h>

/* Returns the color of the node. If NIL, return BLACK */
rbt_color getcolor(rbt_node* x) {
	if (x == NIL)
		return BLACK;

	return x->color;
}

/* Sets the color of the node. If NIL, do nothing */
void setcolor(rbt_node* x, rbt_color color) {
	if (x == NIL)
		return;

	else
		x->color = color;
	
	return;
}

/* Rotates left */
void rotate_left(rbt_tree *T, rbt_node *x) {
	rbt_node* y = x->right;
	x->right = y->left;

	/* Set the left of y's parent as x */
	if (y->left != NIL)
		y->left->parent = x;

	/* Change parent of y as parent of x */
	y->parent = x->parent;

	/* Locate y as the child of original parent of x */
	if (x->parent == NIL)
		T->root = y;

	else if (x == x->parent->left)
		x->parent->left = y;

	else
		x->parent->right = y;

	/* Let x be child of y, y be parent of x */
	y->left = x;
	x->parent = y;

	return;
}

/* Rotates right */
void rotate_right(rbt_tree *T, rbt_node *x) {
	rbt_node* y = x->left;
	x->left = y->right;

	/* Set the right of y's parent as x */
	if (y->right != NIL)
		y->right->parent = x;

	/* Change parent of y as parent of x */
	y->parent = x->parent;

	/* Locate y as the child of original parent of x */
	if (x->parent == NIL)
		T->root = y;

	else if (x == x->parent->left)
		x->parent->left = y;

	else
		x->parent->right = y;

	/* Let x be child of y, y be parent of x */
	y->right = x;
	x->parent = y;

	return;
}

/* Create & Initialize the tree */
rbt_tree *rbt_create() {
	rbt_tree *T = (rbt_tree*)malloc(sizeof(rbt_tree));
	T->root = NIL;
	
	return T;
}

/* Create & Initialize the node and insert it */
rbt_node *insert(rbt_tree *T, int key) {
	rbt_node* node = (rbt_node*)malloc(sizeof(rbt_node));
	node->parent = node->left = node->right = NIL;
	node->key = key;

	insert_rbt(T, node);
	
	return node;
}

/* Insert the node in the redblack tree */
void insert_rbt(rbt_tree *T, rbt_node *z) {
	rbt_node* y = NIL;
	rbt_node* x = T->root;

	/* Find the parent of z in BST */
	while (x != NIL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;

	/* Insert y in BST */
	if (y == NIL)						// Empty tree
		T->root = z;

	else if (z->key < y->key)
		y->left = z;

	else
		y->right = z;

	/* Set the color as red and modify the tree */
	setcolor(z,RED);
	insert_rbt_fixup(T, z);
}

/* Modify the redblack tree to follow the rules */
void insert_rbt_fixup(rbt_tree *T, rbt_node *z) {
	rbt_node* sibling;					// Sibling, another child of parent parent node

	/* Modify until parent of target node is BLACK */
	while (getcolor(z->parent) == RED)
	{
		/* if parent is left of parent of parent */
		if(z->parent == z->parent->parent->left)
		{
			sibling = z->parent->parent->right;
			
			/* case 1 */
			if (getcolor(sibling) == RED)
			{
				setcolor(z->parent,BLACK);
				setcolor(sibling, BLACK);
				setcolor(z->parent->parent, RED);
				z = z->parent->parent;
			}

			else
			{
				/* case 2 */
				if (z == z->parent->right)
				{
					z = z->parent;
					rotate_left(T, z);
				}

				/* case 3 */
				setcolor(z->parent,BLACK);
				setcolor(z->parent->parent,RED);

				rotate_right(T, z->parent->parent);
			}

		} // end left case

		
		/* if parent is right of parent of parent */
		else
		{
			sibling = z->parent->parent->left;

			/* case 4 */
			if (getcolor(sibling) == RED)
			{
				setcolor(z->parent,BLACK);
				setcolor(sibling,BLACK);
				setcolor(z->parent->parent,RED);
				z = z->parent->parent;
			}

			else
			{
				/* case 5 */
				if (z == z->parent->left)
				{
					z = z->parent;
					rotate_right(T, z);
				}

				/* case 6 */
				setcolor(z->parent,BLACK);
				setcolor(z->parent->parent,RED);

				rotate_left(T, z->parent->parent);
			}

		} // end right case

	} //end of while

	/* Make the color of root as black, by the rule */
	setcolor(T->root,BLACK);
}