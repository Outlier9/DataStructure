#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"List.h"
void Test1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);
}

void Test2()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 10);
	LTPushFront(plist, 20);
	LTPushFront(plist, 30);
	LTPushFront(plist, 40);

	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
}

void Test3()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		pos->val *= 10;
	}
	LTPrint(plist);
	LTInsert(pos, 400);
	LTPrint(plist);

}

void Test4()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		LTErase(pos);
	}
	LTPrint(plist);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}