#include"Queue.h"

void test01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	int front=QueueFront(&q);
	printf("front %d\n", front);
	int size = Queuesize(&q);
	printf("队列中数据个数为%d", size);
}
int main()
{
	test01();
	return 0;
}