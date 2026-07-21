#include"SList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTbuyNode(SLDataType x)
{
	//创建存储x的结点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	//判断链表是否为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else {
		//找尾结点
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//判断链表是否只有一个结点
	if ((*pphead) == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) 
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos,SLDataType x)
{
	assert(pphead && *pphead);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* newnode = SLTbuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos位置的结点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos位置之后的结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//销毁链表
void SLTDestory(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}