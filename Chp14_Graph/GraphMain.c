#include <stdio.h>
#include "Graph.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B, 1);
	AddEdge(&graph, A, D, 2);
	AddEdge(&graph, A, E, 3);
	AddEdge(&graph, A, G, 6);
	AddEdge(&graph, B, C, 3);
	AddEdge(&graph, B, D, 3);
	AddEdge(&graph, B, F, 8);
	AddEdge(&graph, C, D, 4);
	AddEdge(&graph, C, G, 4);
	AddEdge(&graph, C, F, 1);
	AddEdge(&graph, D, E, 5);
	AddEdge(&graph, E, F, 6);
	AddEdge(&graph, E, G, 7);


	ShowEdgeInfo(&graph);

	printf("DFS A ���� ��ȸ: ");
	DFSShowVertex(&graph, A);
	printf("\n");

	printf("DFS C ���� ��ȸ: ");
	DFSShowVertex(&graph, C);
	printf("\n");

	printf("DFS E ���� ��ȸ: ");
	DFSShowVertex(&graph, E);
	printf("\n");

	printf("DFS G ���� ��ȸ: ");
	DFSShowVertex(&graph, G);
	printf("\n");

	printf("BFS A ���� ��ȸ: ");
	BFSShowVertex(&graph, A);
	printf("\n");

	printf("BFS C ���� ��ȸ: ");
	BFSShowVertex(&graph, C);
	printf("\n");

	printf("BFS E ���� ��ȸ: ");
	BFSShowVertex(&graph, E);
	printf("\n");

	printf("BFS G ���� ��ȸ: ");
	BFSShowVertex(&graph, G);
	printf("\n");

	ShowGraphEdgeWeight(&graph);

	ConKruskalMST(&graph);
	printf("\nAfter Kruskal\n");

	ShowGraphEdgeWeight(&graph);

	return 0;
}