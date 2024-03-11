#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include"SeqList.h"
#include <assert.h>


void SLInit(SL* psl) // 初始化
{
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}


void SLDestroy(SL* psl) // 释放
{
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
		}
}

void SLPrint(SL* psl) // 打印
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl) // 检查空间
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;// 检测capacity是否为0；是则赋值为4，不是则扩容至二倍
		SLDataType* tmp = realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x) // 尾插入
{ 
	assert(psl);
	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

void SLPushFront(SL* psl, SLDataType x) // 头插入
{
	assert(psl);
	SLCheckCapacity(psl);

	// 挪动数据
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}

void SLPopBack(SL* psl) // 尾删除
{
	assert(psl);
	// 空
	if (psl->size == 0)
	{
		return;
	}
	//OR 暴力检查，断言
	//assert(psl->size > 0);

	psl->size--;
}


void SLPopFront(SL* psl) // 头删除
{
	assert(psl);
	//OR 暴力检查，断言
	assert(psl->size > 0);

	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}
	psl->size--;
}

//pos是下标，也就是插入位置，x是插入的数值
void SLInsert(SL* psl, int pos, SLDataType x)// 任意位置根据下标插入
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	SLCheckCapacity(psl);

	// 挪动数据
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[pos] = x;
	psl->size++;
}



void SLErase(SL* psl, int pos)// 任意位置根据下标删除
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);

	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}
	psl->size--;

}


int SLFind(SL* psl, SLDataType x)// 找到返回下标，没有找到返回-1
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}







