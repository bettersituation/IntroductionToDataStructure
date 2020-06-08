#include "stdio.h"
#include "ArrayQueue.h"
#include "ListQueue.h"
#include "Deque.h"

int main(void)
{
	ArrayQueue aq;
	ListQueue lq;
	Deque dq;

	QueueInit(&aq);
	LQueueInit(&lq);
	DQInit(&dq);

	Enqueue(&aq, 1);
	Enqueue(&aq, 2);
	Enqueue(&aq, 3);
	Enqueue(&aq, 4);
	Enqueue(&aq, 5);
	LEnqueue(&lq, 1);
	LEnqueue(&lq, 2);
	LEnqueue(&lq, 3);
	LEnqueue(&lq, 4);
	LEnqueue(&lq, 5);
	DQAddFirst(&dq, 3);
	DQAddFirst(&dq, 2);
	DQAddFirst(&dq, 1);
	DQAddLast(&dq, 4);
	DQAddLast(&dq, 5);
	DQAddLast(&dq, 6);

	while (!QIsEmpty(&aq))
		printf("%d ", Dequeue(&aq));
	printf("\n");

	while (!LQIsEmpty(&lq))
		printf("%d ", LDequeue(&lq));
	printf("\n");

	while (!DQIsEmpty(&dq))
		printf("%d ", DQRemoveFirst(&dq));
	printf("\n");

	DQAddFirst(&dq, 3);
	DQAddFirst(&dq, 2);
	DQAddFirst(&dq, 1);
	DQAddLast(&dq, 4);
	DQAddLast(&dq, 5);
	DQAddLast(&dq, 6);

	while (!DQIsEmpty(&dq))
		printf("%d ", DQRemoveLast(&dq));
	printf("\n");

	return 0;
}