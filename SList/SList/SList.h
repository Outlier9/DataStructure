#pragma once

typedef int SLNDataType;

// Single List
typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead); // ������ӡ
void SLTPushBack(SLNode** pphead, SLNDataType x); // β��
void SLTPushFront(SLNode** pphead, SLNDataType x); // ͷ��
SLNode* CreatNode(SLNDataType);// �½ڵ�Ĵ���
SLNode* SLTFind(SLNode* phead, SLNDataType x); // ����


void SLTPopBack(SLNode** pphead); // βɾ
void SLTPopFront(SLNode** pphead);  // ͷɾ

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x); //��pos��ǰ�����
void SLTErase(SLNode** pphead, SLNode* pos); //ɾ��posλ��

void SLTInsertAfter(SLNode* pos, SLNDataType x); //�ں������
void SLTEraseAfter(SLNode* pos); //�ں���ɾ��

void SLTDestroy(SLNode** pphead); //��������������




