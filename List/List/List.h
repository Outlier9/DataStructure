#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ��ͷ˫��ѭ������
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;


LTNode* CreatLTNode(LTDataType);//�����½ڵ�
LTNode* LTInit();//��ʼ��
void LTPrint(LTNode* phead);//��ӡ

void LTPushBack(LTNode* phead, LTDataType x);//β��
void LTPopBack(LTNode* phead);//βɾ
void LTPushFront(LTNode* phead, LTDataType x);//ͷ��
void LTPopFront(LTNode* phead);//ͷɾ

LTNode* LTFind(LTNode* phead, LTDataType x);// ����

void LTInsert(LTNode* pos, LTDataType x);// ��posǰ�����
void LTErase(LTNode* pos);// ɾ��posλ��

void LTDestroy(LTNode* phead);//��������
