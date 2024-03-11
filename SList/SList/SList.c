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

SLNode* CreatNode(SLNDataType x) // �½ڵ�Ĵ���
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

//β������
void SLTPushBack(SLNode** pphead, SLNDataType x)//pphead��plist�Ŀ������ı�pphead���ܸı�plist
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);

	if (*pphead == NULL) // ����Ϊ��
	{
		*pphead = newnode;
	}
	else 
	{
		//��β,���һ���ڵ�
		SLNode* tail = *pphead;
		while (tail->next != NULL)//tail->nextԭ��û�а�������½ڵ�������������ָ��next�Ļ��ᷢ���ڴ�й©������������tail����
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}



//ͷ������
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	newnode->next = *pphead;
	*pphead = newnode; 
}



// βɾ
void SLTPopBack(SLNode** pphead) 
{
	//���ɾ����
	if (*pphead == NULL)
		return;
	//�����ö���
	//assert(*pphead);

	//if --- 1���ڵ�
	//else --- ����ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��β,���һ���ڵ�
		SLNode* prev = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)//tail->nextԭ��û�а�������½ڵ�������������ָ��next�Ļ��ᷢ���ڴ�й©������������tail����
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// ͷɾ
void SLTPopFront(SLNode** pphead)
{
	//��
	if (*pphead == NULL)
		return;
	//�����ö���
	//assert(*pphead);

	// ��һ��д��
	SLNode* tail = *pphead;
	*pphead = tail->next;
	free(tail);

	// �ڶ���д��
	/*SLNode* tmp = (*pphead)->next;
	free(*pphead); // �� C �������ǰ�ȫ�ģ����� *pphead = tmp; ����ʹͷָ�� pphead ָ�� NULL������ĳЩ����¿����ǲ���������Ϊ����������������Ϊ������Ϊ��
	*pphead = tmp;*/
}


// ����
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
	return NULL;//û�д˽ڵ㷵�ؿ�
}

// ���룬��pos��ǰ�����
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

//ɾ��ָ����pos
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		//ͷ��
		SLTPopFront(pphead);
	}
	else
	{
		//pos���ǵ�һ��
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
	assert(pos->next);//pos->next->next;ִ�����ʱ���pos->nextΪ�գ���ָ��û��next���ᱨ�������ȶ���

	SLNode* tmp = pos->next;
	pos->next = pos->next->next;

	free(tmp);
	tmp = NULL;
}

//�����ͷŵ������е�ÿ���ڵ㣬ֱ��������������
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