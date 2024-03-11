#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"
#include<stdlib.h>
#include<assert.h>

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d-> ", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreatNode(SLNDataType x) // 新节点的创建
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

//尾部插入
void SLTPushBack(SLNode** pphead, SLNDataType x)//pphead是plist的拷贝，改变pphead不能改变plist
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);

	if (*pphead == NULL) // 链表为空
	{
		*pphead = newnode;
	}
	else 
	{
		//找尾,最后一个节点
		SLNode* tail = *pphead;
		while (tail->next != NULL)//tail->next原因：没有把链表和新节点连接起来，不指向next的话会发生内存泄漏，出了作用域tail销毁
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}



//头部插入
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	newnode->next = *pphead;
	*pphead = newnode; 
}



// 尾删
void SLTPopBack(SLNode** pphead) 
{
	//如果删完了
	if (*pphead == NULL)
		return;
	//或者用断言
	//assert(*pphead);

	//if --- 1个节点
	//else --- 多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找尾,最后一个节点
		SLNode* prev = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)//tail->next原因：没有把链表和新节点连接起来，不指向next的话会发生内存泄漏，出了作用域tail销毁
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// 头删
void SLTPopFront(SLNode** pphead)
{
	//空
	if (*pphead == NULL)
		return;
	//或者用断言
	//assert(*pphead);

	// 第一种写法
	SLNode* tail = *pphead;
	*pphead = tail->next;
	free(tail);

	// 第二种写法
	/*SLNode* tmp = (*pphead)->next;
	free(*pphead); // 在 C 语言中是安全的，但是 *pphead = tmp; 将会使头指针 pphead 指向 NULL，这在某些情况下可能是不期望的行为，比如如果链表设计为不允许为空
	*pphead = tmp;*/
}


// 查找
SLNode* SLTFind(SLNode* phead, SLNDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;//没有此节点返回空
}

// 插入，在pos的前面插入
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	//assert((!pos && !(*pphead)) || (pos && *pphead));

	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLNode* newnode = CreatNode(x);
		newnode->next = pos;
		prev->next = newnode;

	}


}

//删除指定数pos
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		//头插
		SLTPopFront(pphead);
	}
	else
	{
		//pos不是第一个
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
	
}

void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLNode* newnode = CreatNode(x);

	newnode->next = pos->next;
	pos->next = newnode;

}


void SLTEraseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);//pos->next->next;执行这句时如果pos->next为空，空指针没有next，会报错，所以先断言

	SLNode* tmp = pos->next;
	pos->next = pos->next->next;

	free(tmp);
	tmp = NULL;
}

//依次释放单链表中的每个节点，直到整个链表被销毁
void SLTDestroy(SLNode** pphead)
{
	assert(pphead);

	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}