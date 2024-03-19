#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php); // ��ʼ��
void HeapDestroy(HP* php); // ���
void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child); // ���ϴ���
void AdjustDown(HPDataType* a, int size, int parent);
void HeapPush(HP* php, HPDataType x); // ������Ԫ��
void HeapPop(HP* php); // ɾ��������
HPDataType HeapTop(HP* php); // ��ȡջ��Ԫ��
size_t HeapSize(HP* php);
bool HeapEmpty(HP* php);


// ��������õ��Ĳ���
// �������ʵ�ֵ�ԭ���ǽ����ڵ������У�Ȼ������У����ͬʱ���������Ӻ��Һ��Ӵ������

typedef struct BinaryTreeNode* QDataType; //����������Ԫ���ǽڵ�����ǽڵ��ֵ����Ϊ��������Ӧ���ǽڵ��ָ��
// ������TreeNode*���÷�ԭ������struct BinaryTreeNode*
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead; // ͷָ��
	QNode* ptail; // βָ��
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
