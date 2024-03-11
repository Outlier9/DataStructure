#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 带头双向循环链表
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;


LTNode* CreatLTNode(LTDataType);//创建新节点
LTNode* LTInit();//初始化
void LTPrint(LTNode* phead);//打印

void LTPushBack(LTNode* phead, LTDataType x);//尾插
void LTPopBack(LTNode* phead);//尾删
void LTPushFront(LTNode* phead, LTDataType x);//头插
void LTPopFront(LTNode* phead);//头删

LTNode* LTFind(LTNode* phead, LTDataType x);// 查找

void LTInsert(LTNode* pos, LTDataType x);// 在pos前面插入
void LTErase(LTNode* pos);// 删除pos位置

void LTDestroy(LTNode* phead);//销毁链表
