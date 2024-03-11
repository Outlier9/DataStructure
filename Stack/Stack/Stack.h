#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; //标识栈顶位置，元素数量
	int capacity; //栈的容量
}ST;



void STInit(ST* pst);
void STDestroy(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

STDataType STTop(ST* pst);
bool STEmpty(ST* pst);
int STSize(ST* pst);
