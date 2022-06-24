#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTREE.h"

int main(void) {

	printf("max degree : 3, After Insertion\n");
	BTreeInit(3); // Max degree 3
	insertElement(1); insertElement(3); insertElement(7); insertElement(10); insertElement(11); insertElement(13);	insertElement(14);
	insertElement(15); insertElement(18); insertElement(16); insertElement(19); insertElement(24); insertElement(25); insertElement(26);
	printTree();
	printf("\n");

	printf("max degree : 3, After Deletion\n");
	removeElement(13);
	printTree();
	printf("\n");

	printf("max degree : 4, After Insertion\n");
	BTreeInit(4); // Max degree 4
	insertElement(1); insertElement(3); insertElement(7); insertElement(10); insertElement(11); insertElement(13);	insertElement(14);
	insertElement(15); insertElement(18); insertElement(16); insertElement(19); insertElement(24); insertElement(25); insertElement(26);
	printTree();
	printf("\n");

	printf("max degree : 4, After Deletion\n");
	removeElement(13);
	printTree();
	printf("\n");

	system("pause");

	return 0;
}