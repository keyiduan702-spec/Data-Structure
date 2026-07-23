#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//定义队列结点的结构
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//定义队列的结构
typedef struct Queue{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;
}Queue;

//初始化
void QueueInit(Queue* pq);
//在队尾入队
void QueuePush(Queue* pq, QDataType x);
//在队头出队
void QueuePop(Queue* pq);

//队列判空
bool QueueEmpty(Queue* pq);

//取出队头数据
QDataType QueueFront(Queue* pq);
//取出队尾数据
QDataType QueueBack(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);
//队列有效元素的个数
int Queuesize(Queue* pq);