#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "QueueData.h"

typedef struct _deque
{
	Node* front;
	Node* rear;
} Deque;

void DQInit(Deque* pdq);
int DQIsEmpty(Deque* pdq);

void DQAddFirst(Deque* pdq, Data data);
void DQAddLast(Deque* pdq, Data data);

Data DQRemoveFirst(Deque* pdq);
Data DQRemoveLast(Deque* pdq);

Data DQGetFirst(Deque* pdq);
Data DQGetLast(Deque* pdq);

#endif