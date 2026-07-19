#include"SeqList.h"

void SLPrint(SL* ps)
{
	assert(ps);
	if (ps->arr == NULL)
	{
		printf("顺序表为空\n");
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//判断空间是否足够
void SLCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//增容
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
//销毁
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->arr != NULL)
		free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//判断空间是否足够
	SLCheckCapacity(ps);
	//如果空间足够
	ps->arr[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//判断空间是否足够
	SLCheckCapacity(ps);
	//将所有数据向后挪一个位置
	for (int i = ps->size - 1; i >= 0;i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}
//尾删
void SLPopBack(SL* ps)
{
	//注意：顺序表为空则不执行尾删
	assert(ps && ps->size );
	ps->size--;
}
//头删
void SLPopFront(SL* ps)
{
	//注意：顺序表为空则不执行尾删
	assert(ps && ps->size);
	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}

//指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//将pos及pos之后的数据向后挪一个位置
	for (int i = ps->size; i >pos ; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除POS位置的数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//将pos之后的数据向前挪一个位置
	for (int i = pos; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}


