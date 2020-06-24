#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table Tbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&Tbl, MyHashFunc);

	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&Tbl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&Tbl, GetSSN(np), np);

	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&Tbl, GetSSN(np), np);

	np = MakePersonData(901827, "PARK", "Incheon");
	TBLInsert(&Tbl, GetSSN(np), np);

	sp = TBLSearch(&Tbl, 900254);
	if (sp != NULL)
	{
		ShowPersonInfo(sp);
	}

	sp = TBLSearch(&Tbl, 900139);
	if (sp != NULL)
	{
		ShowPersonInfo(sp);
	}

	sp = TBLSearch(&Tbl, 900827);
	if (sp != NULL)
	{
		ShowPersonInfo(sp);
	}

	sp = TBLSearch(&Tbl, 901827);
	if (sp != NULL)
	{
		ShowPersonInfo(sp);
	}

	sp = TBLSearch(&Tbl, 902027);
	if (sp != NULL)
	{
		ShowPersonInfo(sp);
	}

	rp = TBLDelete(&Tbl, 900827);
	if (rp != NULL)
	{
		free(rp);
	}

	rp = TBLDelete(&Tbl, 900139);
	if (rp != NULL)
	{
		free(rp);
	}

	rp = TBLDelete(&Tbl, 900827);
	if (rp != NULL)
	{
		free(rp);
	}

	return 0;
}