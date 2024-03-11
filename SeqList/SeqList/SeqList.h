#pragma once

//顺序表数据类型定义
typedef int SLDataType;

//动态存储
typedef struct SeqList
{
	SLDataType* a; // 指向动态开辟的数组
	int size;  // 有效数据个数
	int capacity;  // 空间容量大小
}SL;

void SLInit(SL* ps); // 初始化
void SLDestroy(SL* ps); // 销毁

void SLPushBack(SL* psl, SLDataType x); // 尾插入
void SLPushFront(SL* psl, SLDataType x); // 头插入

void SLPopBack(SL* psl); // 尾删除
void SLPopFront(SL* psl); // 头删除

void SLPrint(SL* psl); //顺序表的打印

void SLCheckCapacity(SL* psl); // 扩容前进行空间查询，看是否够用

void SLInsert(SL* psl, int pos, SLDataType x); // 任意位置根据下标插入
void SLErase(SL* psl, int pos); // 任意位置根据下标删除

int SLFind(SL* psl, SLDataType x);// 查找，找到返回下标，没有找到返回-1