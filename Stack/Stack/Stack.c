#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	// 1.表示top指向栈顶元素的下一个位置
	pst->top = 0;

	// 2.表示top指向栈顶元素
	//pst->top = -1; 
	// top为0的话不清楚是top为0还是空，因此空的时候给-1
	//位置(下标)   top     0     1
	//数值        -1(空)   0     1
	//top = 1指向栈顶元素的下一个位置
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;

}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2; //如果栈的当前容量为0，将其设为4，否则将其扩大为当前容量的两倍
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp; //将原来栈中数据的指针更新为新的内存空间的指针
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];

}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top;

}
