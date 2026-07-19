#include"SeqList.h"

void test01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	SLPushFront(&sl, 0);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLInsert(&sl, 1, 3);
	SLPrint(&sl);
	SLErase(&sl, 1);
	SLPrint(&sl);
	SLDestory(&sl);
	SLPrint(&sl);
}

int main()
{
	test01();
	return 0;
}