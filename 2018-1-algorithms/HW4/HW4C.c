/*================================================================================
* Written date : 2018.06.06
* Lastest revised date : 2018.06.11
* ==================================================================================*/

#include "header.h"
#define Parent(n) (((n) - (1))/(2))
#define L_Child(n) ((2)*(n) + (1))
#define R_Child(n) ((2)*(n) + (2))

/* Swap the position at the min heap */
void swapPosition(MinHeap* M, int idx1, int idx2)
{
	M->position[M->vertexList[idx1]->name] = idx2;
	M->position[M->vertexList[idx2]->name] = idx1;

	return;
}

/* Do min heapify */
void minHeapify(MinHeap *M, int Index)
{
	/* If no child */
 	if (L_Child(Index) > M->remainVertexNumber - 1)
		return;

	/* Only left child */
	else if (L_Child(Index) == M->remainVertexNumber - 1)
	{
		/* If left < parent, swap it */
		if (M->vertexList[L_Child(Index)]->key < M->vertexList[Index]->key)
		{
			swapPosition(M, Index, L_Child(Index));
			swapVertex(&M->vertexList[L_Child(Index)], &M->vertexList[Index]);
		}

		return;
	}

	else
	{
		/* If Left < Right */
		if (M->vertexList[L_Child(Index)]->key < M->vertexList[R_Child(Index)]->key)
		{
			/* If left < parent, swap it */
			if (M->vertexList[L_Child(Index)]->key < M->vertexList[Index]->key)
			{
				swapPosition(M, Index, L_Child(Index));
				swapVertex(&M->vertexList[L_Child(Index)], &M->vertexList[Index]);

				/* Recursively call to the left child */
				minHeapify(M, L_Child(Index));
			}

			return;

		}

		/* If Right <= Left */
		else
		{
			/* If right < parent, swap it */
			if (M->vertexList[R_Child(Index)]->key < M->vertexList[Index]->key)
			{
				swapPosition(M, Index, R_Child(Index));
				swapVertex(&M->vertexList[R_Child(Index)], &M->vertexList[Index]);

				/* Recursively call to the right child */
				minHeapify(M, R_Child(Index));
			}

			return;
		}
			
	}
	return;
}

/* Extract minimum vertex and swap the place of first and last element */
Vertex *extractMin(MinHeap *M)
{
	Vertex* temp = M->vertexList[0];

	/* Reduce the number of remain vertexes */
	(M->remainVertexNumber)--;
	
	swapPosition(M, 0, M->remainVertexNumber);
	swapVertex(&M->vertexList[0], &M->vertexList[M->remainVertexNumber]);

	return temp;
}

/* Decrease the key of node if the input key is smaller */
void decreaseKey(MinHeap *M, int V, int Key)
{
	if(Key < M->vertexList[M->position[V]]->key)
		M->vertexList[M->position[V]]->key = Key;

	return;
}

/* Add the vertex of the graph to the heap */
void addVertexToHeap(MinHeap *M, Graph *G, int V)
{
	M->vertexList[M->remainVertexNumber] = G->vertexList[V];
	M->position[M->vertexList[M->remainVertexNumber]->name] = M->remainVertexNumber;

	(M->remainVertexNumber)++;

	return;
}

/* Apply the prim algorithm to graph. return the value of mst */
int primAlgorithm(Graph *G)
{
	MinHeap* heap = initMinHeap(G->totalVertexNumber);
	int i;

	/* Initialize the postion of the heap as infinity */
	for (i = 0; i < G->totalVertexNumber; i++)
		heap->position[i] = INT_MAX;

	/* Add all the vertex of graph to the heap */
	for (i = 0; i < G->totalVertexNumber; i++)
		addVertexToHeap(heap, G, i);

	/* Initialize first node as 0 */
	decreaseKey(heap, 0, 0);

	Vertex* temp;
	int selec;									// name of extracted node

	while (!isEmptyHeap(heap))
	{
		temp = extractMin(heap);
		selec = temp->name;

		/* For every vertexes*/
		for (i = 0; i < heap->totalVertexNumber; i++)

			/* If vertex is connected to temp and is in the heap */
			if (temp->connectedVertexWeights[i] != INT_MAX && isInMinHeap(heap, i))

				/* Decrease the key value as weight */
				decreaseKey(heap, i, temp->connectedVertexWeights[i]);

		/* After decrease, it is no more heap. So build a heap again */
		for (i = Parent(heap->remainVertexNumber); i >= 0; i--)
			minHeapify(heap, i);
	}

	int sum = 0;

	/* Sum all the edge value of mst */
	for (i = 0; i < G->totalVertexNumber; i++)
		sum += G->vertexList[i]->key;

	return sum;
}