#ifndef __GRAPH__
#define __GRAPH__

#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Edge.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
	PriQ pqueue;
} Graph;

void GraphInit(Graph* pg, int nv);

void GraphDestroy(Graph* pg);

void AddEdge(Graph* pg, int fromV, int toV, int weight);

void ShowEdgeInfo(Graph* pg);

void DFSShowVertex(Graph* pg, int startV);

void BFSShowVertex(Graph* pg, int startV);

void RemoveEdge(Graph* pg, int v1, int v2);

void RecoverEdge(Graph* pg, int fromV, int toV, int weight);

int IsConnected(Graph* pg, int v, int target);

void ConKruskalMST(Graph* pg);

void ShowGraphEdgeWeight(Graph* pg);

#endif