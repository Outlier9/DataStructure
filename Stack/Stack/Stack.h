#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; //��ʶջ��λ�ã�Ԫ������
	int capacity; //ջ������
}ST;



void STInit(ST* pst);
void STDestroy(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

STDataType STTop(ST* pst);
bool STEmpty(ST* pst);
int STSize(ST* pst);
