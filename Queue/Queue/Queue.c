#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}


void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


void QueuePop(Queue* pq)
{
	assert(pq);
	// 空节点
	assert(pq->phead);
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	// 一个节点的时候，phead向前走
	// del被free，ptail此时和del指的是一个节点，如果free，就变成了野指针
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	pq->size--;

}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	// 空节点
	assert(pq->phead);

	return pq->phead->val;

}


QDataType QueueBack(Queue* pq)
{
	assert(pq);
	// 空节点
	assert(pq->phead);

	return pq->ptail->val;

}


bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;

}


int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;

}