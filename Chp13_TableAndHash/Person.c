#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPersonInfo(Person* p)
{
	printf("�ֹε�Ϲ�ȣ: %d\n", p->ssn);
	printf("�̸�: %s\n", p->name);
	printf("�ּ�: %s\n", p->addr);
}

Person* MakePersonData(int ssn, char* name, char* addr)
{
	Person* newP = (Person*)malloc(sizeof(Person));
	
	newP->ssn = ssn;
	strcpy_s(newP->name, STR_LEN, name);
	strcpy_s(newP->addr, STR_LEN, addr);

	return newP;
}