#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include"SeqList.h"
#include <assert.h>


void SLInit(SL* psl) // ��ʼ��
{
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}


void SLDestroy(SL* psl) // �ͷ�
{
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
		}
}

void SLPrint(SL* psl) // ��ӡ
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl) // ���ռ�
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;// ���capacity�Ƿ�Ϊ0������ֵΪ4������������������
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

void SLPushBack(SL* psl, SLDataType x) // β����
{ 
	assert(psl);
	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

void SLPushFront(SL* psl, SLDataType x) // ͷ����
{
	assert(psl);
	SLCheckCapacity(psl);

	// Ų������
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}

void SLPopBack(SL* psl) // βɾ��
{
	assert(psl);
	// ��
	if (psl->size == 0)
	{
		return;
	}
	//OR ������飬����
	//assert(psl->size > 0);

	psl->size--;
}


void SLPopFront(SL* psl) // ͷɾ��
{
	assert(psl);
	//OR ������飬����
	assert(psl->size > 0);

	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}
	psl->size--;
}

//pos���±꣬Ҳ���ǲ���λ�ã�x�ǲ������ֵ
void SLInsert(SL* psl, int pos, SLDataType x)// ����λ�ø����±����
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	SLCheckCapacity(psl);

	// Ų������
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[pos] = x;
	psl->size++;
}



void SLErase(SL* psl, int pos)// ����λ�ø����±�ɾ��
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


int SLFind(SL* psl, SLDataType x)// �ҵ������±꣬û���ҵ�����-1
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







