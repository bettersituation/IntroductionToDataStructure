#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Edge.h"
#include "Graph.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityComp.h"
#include "PriorityQueue.h"
#include "Heap.h"

void GraphInit(Graph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	PriQInit(&(pg->pqueue), Is);

	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(Graph* pg)
{
	if (pg->adjList != NULL)
	{
		free(pg->adjList);
	}
}

void AddEdge(Graph* pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	PEnqueue(&(pg->pqueue), edge);

	pg->numE++;
}

void ShowEdgeInfo(Graph* pg)
{
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
			{
				printf("%c ", vx + 65);
			}
		}
		printf("\n");
	}
}

int Visit(int* visits, int visitV)
{
	if (visits[visitV] == 0)
	{
		visits[visitV] = 1;
		printf("%c ", visitV + 65);

		return TRUE;
	}

	return FALSE;
}

void DFSShowVertex(Graph* pg, int startV)
{
	int visitV = startV;
	int candiV;
	int allviSit;

	Stack stack;
	int* visits = (int*)malloc(sizeof(int) * (pg->numV));

	StackInit(&stack);

	for (int i = 0; i < pg->numV; i++)
	{
		visits[i] = 0;
	}

	Visit(visits, visitV);
	SPush(&stack, visitV);

	while (!SIsEmpty(&stack))
	{
		allviSit = 1;
		visitV = SPeek(&stack);

		if (LFirst(&(pg->adjList[visitV]), &candiV))
		{
			if (visits[candiV] == 0)
			{
				allviSit *= 0;
			}
			else
			{
				while (LNext(&(pg->adjList[visitV]), &candiV))
				{
					if (visits[candiV] == 0)
					{
						allviSit *= 0;
					}
				}
			}
		}

		if (allviSit)
		{
			SPop(&stack);
		}

		if (!SIsEmpty(&stack))
		{
			visitV = SPeek(&stack);

			if (LFirst(&(pg->adjList[visitV]), &candiV))
			{
				if (Visit(visits, candiV))
				{
					SPush(&stack, candiV);
				}
				else
				{
					while (LNext(&(pg->adjList[visitV]), &candiV))
					{
						if (Visit(visits, candiV))
						{
							SPush(&stack, candiV);
							break;
						}
					}
				}
			}
		}
	}

	free(visits);
}

void BFSShowVertex(Graph* pg, int startV)
{
	int visitV = startV;
	int candiV;

	Queue q;
	int* visits = (int*)malloc(sizeof(int) * (pg->numV));

	QueueInit(&q);
	memset(visits, 0, sizeof(int) * pg->numV);

	Visit(visits, visitV);
	Enqueue(&q, visitV);

	while (!QIsEmpty(&q))
	{
		visitV = Dequeue(&q);

		if (LFirst(&(pg->adjList[visitV]), &candiV))
		{
			if (Visit(visits, candiV))
			{
				Enqueue(&q, candiV);
			}
			while (LNext(&(pg->adjList[visitV]), &candiV))
			{
				if (Visit(visits, candiV))
				{
					Enqueue(&q, candiV);
				}
			}
		}
	}

	free(visits);
}

void RemoveEdge(Graph* pg, int v1, int v2)
{
	int targetV;
	int isDel = FALSE;

	if (LFirst(&(pg->adjList[v1]), &targetV))
	{
		if (targetV == v2)
		{
			LRemove(&(pg->adjList[v1]));
			isDel = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[v1]), &targetV))
			{
				if (targetV == v2)
				{
					LRemove(&(pg->adjList[v1]));
					isDel = TRUE;
					break;
				}
			}
		}
	}

	if (isDel)
	{
		pg->numE--;

		if (LFirst(&(pg->adjList[v2]), &targetV))
		{
			if (targetV == v1)
			{
				LRemove(&(pg->adjList[v2]));
			}
			else
			{
				while (LNext(&(pg->adjList[v2]), &targetV))
				{
					if (targetV == v1)
					{
						LRemove(&(pg->adjList[v2]));
						break;
					}
				}
			}
		}
	}
}

void RecoverEdge(Graph* pg, int v1, int v2, int weight)
{
	Edge edge = { v1, v2, weight };

	LInsert(&(pg->adjList[v1]), v2);
	LInsert(&(pg->adjList[v1]), v2);

	pg->numE++;
}

int recurTo(Graph* pg, int v, int target, int* visits)
{
	int met = FALSE;
	int dest;

	if (LFirst(&(pg->adjList[v]), &dest))
	{
		if (!visits[dest] && dest == target)
		{
			visits[dest] = TRUE;
			return TRUE;
		}
		else if (!visits[dest])
		{
			visits[dest] = TRUE;
			met |= recurTo(pg, dest, target, visits);

			if (met)
			{
				return TRUE;
			}
		}

		while (LNext(&(pg->adjList[v]), &dest))
		{
			if (!visits[dest] && dest == target)
			{
				visits[dest] = TRUE;
				return TRUE;
			}
			else if (!visits[dest])
			{
				visits[dest] = TRUE;
				met |= recurTo(pg, dest, target, visits);

				if (met)
				{
					return TRUE;
				}
			}
		}
	}

	return FALSE;
}

int IsConnected(Graph* pg, int v1, int v2)
{
	int* visits = (int*)malloc(sizeof(int) * pg->numE);
	int conn;

	memset(visits, 0, sizeof(int) * pg->numE);
	visits[v1] = TRUE;

	conn = recurTo(pg, v1, v2, visits);
	
	free(visits);

	return conn;
}

void ConKruskalMST(Graph* pg)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;

	while (pg->numE > pg->numV - 1)
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnected(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	for (int i = 0; i < eidx; i++)
	{
		PEnqueue(&(pg->pqueue), recvEdge[i]);
	}
}

void ShowGraphEdgeWeight(Graph* pg)
{
	PriQ backupPQ;
	Edge edge;

	PriQInit(&backupPQ, (pg->pqueue).ph->comp);

	while (!PriQIsEmpty(&(pg->pqueue)))
	{
		edge = PDequeue(&(pg->pqueue));
		PEnqueue(&backupPQ, edge);

		printf("(%c - %c) weight: %d\n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}

	while (!PriQIsEmpty(&backupPQ))
	{
		edge = PDequeue(&backupPQ);
		PEnqueue(&(pg->pqueue), edge);
	}
}
