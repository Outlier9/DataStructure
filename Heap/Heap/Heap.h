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

void HeapInit(HP* php); // 初始化
void HeapDestroy(HP* php); // 清空
void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child); // 向上传递
void AdjustDown(HPDataType* a, int size, int parent);
void HeapPush(HP* php, HPDataType x); // 插入新元素
void HeapPop(HP* php); // 删除根数据
HPDataType HeapTop(HP* php); // 获取栈顶元素
size_t HeapSize(HP* php);
bool HeapEmpty(HP* php);


// 层序遍历用到的部分
// 层序遍历实现的原理是将根节点放入队列，然后出队列，与此同时将他的左孩子和右孩子带入队列

typedef struct BinaryTreeNode* QDataType; //放入队列里的元素是节点而不是节点的值，因为数据类型应该是节点的指针
// 不能用TreeNode*，得放原生类型struct BinaryTreeNode*
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead; // 头指针
	QNode* ptail; // 尾指针
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
