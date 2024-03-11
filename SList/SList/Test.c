#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"
#include<assert.h>

void TestSLT1()
{
	SLNode* plist = NULL; // 错误，比如函数内部实现了地址交换，形参并不会影响实参，要实现地址交换，需要传二级指针

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
}

void TestSLT2()
{
	SLNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLNode* pos = SLTFind(plist, 3);
	SLTInsert(&plist, pos, 3);


}

void TestSLT3()
{
	SLNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLNode* pos = SLTFind(plist,4);
	SLTInsert(&plist, pos, 40);
	SLTPrint(plist);
	
	pos = SLTFind(plist, 2);
	SLTInsert(&plist, pos, 20);
	SLTPrint(plist);

}

void TestSLT4()
{
	SLNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLNode* pos = SLTFind(plist, 1);
	SLTErase(&plist, pos);
	SLTPrint(plist); 

	pos = SLTFind(plist, 3);
	SLTErase(&plist, pos);
	SLTPrint(plist);
}


int main()
{
	TestSLT1();
	TestSLT2();
	TestSLT3();
	TestSLT4();
	return 0;
}













