#include "stdio.h"
#include "stdlib.h"
#include "Deque.h"

void DQInit(Deque* pdq)
{
	pdq->front = NULL;
	pdq->rear = NULL;
}

int DQIsEmpty(Deque* pdq)
{
	if (pdq->front == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

void DQAddFirst(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pdq->front;

	pdq->front = newNode;

	if (pdq->rear == NULL)
	{
		pdq->rear = newNode;
	}
}

void DQAddLast(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	if (DQIsEmpty(pdq))
	{
		pdq->front = newNode;
		pdq->rear = newNode;
	}
	else
	{
		pdq->rear->next = newNode;
		pdq->rear = newNode;
	}
}

Data DQRemoveFirst(Deque* pdq)
{
	Data rData;
	Node* fNode;

	if (DQIsEmpty(pdq))
	{
		printf("MEMO ERROR\n");
		exit(-1);
	}

	fNode = pdq->front;
	rData = fNode->data;

	pdq->front = pdq->front->next;
	if (pdq->front == NULL)
	{
		pdq->rear = NULL;
	}

	free(fNode);

	return rData;
}

Data DQRemoveLast(Deque* pdq)
{
	Data rData;
	Node* rNode;
	Node* fNode;

	if (DQIsEmpty(pdq))
	{
		printf("MEMO ERROR\n");
		exit(-1);
	}

	if (pdq->rear == pdq->front)
	{
		rNode = pdq->rear;
		rData = rNode->data;
		
		pdq->rear = NULL;
		pdq->front = NULL;
	}
	else
	{
		fNode = pdq->front;
		rNode = pdq->rear;
		rData = rNode->data;

		while (fNode->next != rNode)
		{
			fNode = fNode->next;
		}
		pdq->rear = fNode;
	}
	
	free(rNode);

	return rData;
}

Data DQGetFirst(Deque* pdq)
{
	if (DQIsEmpty(pdq))
	{
		printf("MEMO ERROR\n");
		exit(-1);
	}

	return pdq->front->data;
}


Data DQGetLast(Deque* pdq)
{
	if (DQIsEmpty(pdq))
	{
		printf("MEMO ERROR\n");
		exit(-1);
	}

	return pdq->rear->data;
}
