#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"List.h"


LTNode* CreatLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL; 

	return newnode;
}


LTNode* LTInit()
{
	LTNode* phead = CreatLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("�ڱ���");

	LTNode* cur = phead->next;
	while (cur != phead) 
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = CreatLTNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;

	free(tail);
	//tail = NULL;//tail�������Զ�����,����Ҫд����

}
//ͷ�壬Ҳ�����ٴ���һ��ָ�뱣��phead����һ���ڵ㣬ת��Ϊ�����ڵ�ĵ�ַ�任
//�ṹ���ƣ�C++ STL�����������Ϊ�գ�ֻ��һ���ڱ���ͷ���,first�����Լ�
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = CreatLTNode(x);
	LTNode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}


//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//���ֻ��ͷ���phead��first = phead������free���������Ұָ��

	LTNode* first = phead->next;
	LTNode* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��posǰ�����
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = CreatLTNode(x);
	LTNode* posPrev = pos->prev;

	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = posPrev;
	posPrev->next = newnode;
}

// ɾ��posλ��
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* posNext = pos->next;
	LTNode* posPrev = pos->prev;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}


void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
