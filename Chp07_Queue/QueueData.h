#ifndef __ARRAY_DATA_H__
#define __ARRAY_DATA_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

#endif