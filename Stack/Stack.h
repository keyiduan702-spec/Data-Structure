#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//
typedef int STDataType;
typedef struct Stack {
	STDataType* arr;
	int top;//指向栈顶
	int capacity;//栈的容量
}ST;

