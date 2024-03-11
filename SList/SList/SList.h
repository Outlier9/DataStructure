#pragma once

typedef int SLNDataType;

// Single List
typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead); // 遍历打印
void SLTPushBack(SLNode** pphead, SLNDataType x); // 尾插
void SLTPushFront(SLNode** pphead, SLNDataType x); // 头插
SLNode* CreatNode(SLNDataType);// 新节点的创建
SLNode* SLTFind(SLNode* phead, SLNDataType x); // 查找


void SLTPopBack(SLNode** pphead); // 尾删
void SLTPopFront(SLNode** pphead);  // 头删

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x); //在pos的前面插入
void SLTErase(SLNode** pphead, SLNode* pos); //删除pos位置

void SLTInsertAfter(SLNode* pos, SLNDataType x); //在后面插入
void SLTEraseAfter(SLNode* pos); //在后面删除

void SLTDestroy(SLNode** pphead); //销毁整个单链表




