#include"SList.h"

void test01()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	SLTPushFront(&plist, 0);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTNode* find =SLTFind(plist, 3);
	if (find)
	{
		printf("找到了！\n");
	}
	else {
		printf("没找到！\n");
	}
	SLTInsert(&plist, find, 2);
	SLTPrint(plist);
	SLTInsertAfter(find, 4);
	SLTPrint(plist);
	SLTErase(&plist, find);
	SLTPrint(plist);
	SLTDestory(&plist);
	SLTPrint(plist);
}
int main()
{
	test01();
	return 0;
}