#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//定义链表的结构---结点
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;//存储的数据
	struct SListNode* next;//指向下一个结点
}SLTNode;

void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);

//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x);

//删除pos位置的结点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos位置之后的结点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SLTDestory(SLTNode** pphead);