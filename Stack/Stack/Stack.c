#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	// 1.��ʾtopָ��ջ��Ԫ�ص���һ��λ��
	pst->top = 0;

	// 2.��ʾtopָ��ջ��Ԫ��
	//pst->top = -1; 
	// topΪ0�Ļ��������topΪ0���ǿգ���˿յ�ʱ���-1
	//λ��(�±�)   top     0     1
	//��ֵ        -1(��)   0     1
	//top = 1ָ��ջ��Ԫ�ص���һ��λ��
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
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2; //���ջ�ĵ�ǰ����Ϊ0��������Ϊ4������������Ϊ��ǰ����������
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp; //��ԭ��ջ�����ݵ�ָ�����Ϊ�µ��ڴ�ռ��ָ��
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
