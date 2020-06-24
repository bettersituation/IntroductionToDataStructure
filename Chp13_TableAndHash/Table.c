#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "LinkedList.h"

void TBLInit(Table* pt, HashFunc* f)
{
	for (int i = 0; i < MAX_TBL; i++)
	{
		ListInit(&(pt->tbl[i]));
	}

	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k, v };

	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 발생\n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return cSlot.value;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.value;
				}
			}
		}
	}

	return NULL;
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			return cSlot.value;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					return cSlot.value;
				}
			}
		}
	}

	return NULL;
}
