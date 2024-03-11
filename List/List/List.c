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
	printf("哨兵卫");

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
	//tail = NULL;//tail变量会自动销毁,不需要写这行

}
//头插，也可以再创建一个指针保存phead的下一个节点，转换为三个节点的地址变换
//结构优势（C++ STL）：如果链表为空，只有一个哨兵卫头结点,first就是自己
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


//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//如果只有头结点phead，first = phead，不能free，否则出现野指针

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

// 在pos前面插入
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

// 删除pos位置
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
