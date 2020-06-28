#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Edge.h"
#include "Heap.h"

void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HeapIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return 2 * idx;
}

int GetRChildIDX(int idx)
{
	return 2 * idx + 1;
}

int GetHighPriChildIdx(Heap* ph, int idx)
{
	int lIDX = GetLChildIDX(idx);
	int rIDX = lIDX + 1;

	if (lIDX > ph->numOfData)
	{
		return 0;
	}
	else if (lIDX == ph->numOfData)
	{
		return lIDX;
	}
	else if (ph->comp(ph->heapArr[rIDX], ph->heapArr[lIDX]) > 0)
	{
		return rIDX;
	}
	else
	{
		return lIDX;
	}
}

void PositioningUp(Heap* ph, int idx)
{
	int pIDX = GetParentIDX(idx);

	if (pIDX == 0)
	{
		return;
	}

	if (ph->comp(ph->heapArr[idx], ph->heapArr[pIDX]) >= 0)
	{
		ph->heapArr[0] = ph->heapArr[idx];
		ph->heapArr[idx] = ph->heapArr[pIDX];
		ph->heapArr[pIDX] = ph->heapArr[0];
		PositioningUp(ph, pIDX);
	}
}

void PositioningDown(Heap* ph, int idx)
{
	int cIDX = GetHighPriChildIdx(ph, idx);

	if (cIDX == 0)
	{
		return;
	}

	if (ph->comp(ph->heapArr[cIDX], ph->heapArr[idx]) >= 0)
	{
		ph->heapArr[0] = ph->heapArr[idx];
		ph->heapArr[idx] = ph->heapArr[cIDX];
		ph->heapArr[cIDX] = ph->heapArr[0];
		PositioningDown(ph, cIDX);
	}
}

void HeapInsert(Heap* ph, Edge data)
{
	if (ph->numOfData == HEAP_LEN - 1)
	{
		printf("MEM ERROR\n");
		exit(-1);
	}

	ph->heapArr[++(ph->numOfData)] = data;
	PositioningUp(ph, ph->numOfData);
}

Edge HeapDelete(Heap* ph)
{
	Edge rData;

	if (ph->numOfData == 0)
	{
		printf("MEM ERROR\n");
		exit(-1);
	}

	rData = ph->heapArr[1];

	ph->heapArr[1] = ph->heapArr[ph->numOfData];
	ph->numOfData--;

	PositioningDown(ph, 1);

	return rData;
}

void PrintHeap(Heap* ph)
{
	int N = 1;

	while (N <= ph->numOfData)
	{
		for (int i = N; i < 2 * N; i++)
		{
			if (i > ph->numOfData)
			{
				break;
			}
			printf("%d ", ph->heapArr[i].weight);
		}
		printf("\n");

		N *= 2;
	}
}