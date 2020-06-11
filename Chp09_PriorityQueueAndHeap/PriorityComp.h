#ifndef __PRIORITY_COMP_H__
#define __PRIORITY_COMP_H__

#include "Data.h"

typedef int PriorityComp(Data d1, Data d2);

int IsLess(Data d1, Data d2);

#endif