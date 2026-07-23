#include"Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}
//在队尾入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	//pq->size++;
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//在队头出队
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//只有一个结点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else {
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	//pq->size--;
}

//取出队头数据
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}
//取出队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

//销毁队列
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
}
//队列有效元素的个数
int Queuesize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		size++;
		pcur = next;
	}
	return size;
	//return pq->size;
}