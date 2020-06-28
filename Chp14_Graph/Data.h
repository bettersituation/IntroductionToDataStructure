#ifndef __DATA__
#define __DATA__

#define TRUE	1
#define FALSE	0

typedef int Data;
typedef Data LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

#endif