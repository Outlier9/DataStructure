#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include"SeqList.h"


void TestSL1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 6);
	SLPushBack(&sl, 7);
	SLPushBack(&sl, 8);
	SLPushBack(&sl, 9); // 尾插入
	SLPrint(&sl);

	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40); // 头插入

	SLPrint(&sl);

	SLDestroy(&sl);
}


void TestSL2()
{
	SL sl;
	SLInit(&sl);

	SLPushBack(&sl,1);
	SLPushBack(&sl,2);
	SLPushBack(&sl,3);
	SLPushBack(&sl,4);
	SLPushBack(&sl,5);
	SLPrint(&sl);

	SLPopBack(&sl); // 尾删除
	SLPrint(&sl); 
	//不能free，要释放就全部释放；若发生插入可直接覆盖，空间重复利用
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPrint(&sl);
	
	// 此时size已经是0了，执行下一步后size还会继续-1
	SLPopBack(&sl);
	SLPrint(&sl);

	// 插入数据后size应该是4，由于上一步的原因，最终size为3，使最终结果只插入了3个数。除非判断size是否为0（函数内部已做处理）
	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40);
	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSL3()
{
	SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl); // 头删除
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);	
}

void TestSL4()
{

	SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLInsert(&sl, 2, 20);// 任意位置根据下标插入
	SLPrint(&sl);

	SLDestroy(&sl);
}



void TestSL5()
{

	SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLErase(&sl, 2);// 任意位置根据下标删除
	SLPrint(&sl);

	SLDestroy(&sl);
}


 void TestSL6()
{
	SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	int pos = SLFind(&sl, 2); //找到下标为2的
	if (pos != -1)
	{
		SLErase(&sl, pos);
	}
	SLPrint(&sl);
	SLDestroy(&sl);
}

 void menu()
 {
	 printf("*****************************\n");
	 printf("****1.尾插数据 2.尾删数据****\n");
	 printf("****3.头插数据 4.头删数据****\n");
	 printf("****5.打印数据 0.退出程序****\n");
	 printf("*****************************\n");
 }


 int main()
 {
	 SL s;
	 SLInit(&s);

	 int option = 0;
	 do
	 {
		 menu();
		 printf("请输入你的选择>");
		 scanf("%d", &option);


		 if (option == 1)
		 {
			 printf("请输入你要尾插的数据个数和数据：>\n");
			 int n = 0;//个数
			 scanf("%d", &n);

			 for (int i = 0; i < n; i++)
			 {
				 int x = 0;//数据
				 scanf("%d", &x);
				 SLPushBack(&s, x);
			 }
			 printf("\n");
		 }
		 else if(option == 2)
		 {
			 SLPopBack(&s);
			 printf("删除成功\n");
			 printf("\n");
			 }
		 else if (option == 3)
		 {
			 printf("请输入你要头插的数据，以-1结束：>\n");
			 int x = 0;
			 scanf("%d", &x);
			 while (x != -1)
			 {
				 SLPushFront(&s, x);
				 scanf("%d", &x);
			 }
			 printf("\n");
		 }
		 else if (option == 4)
		 {
			 SLPopFront(&s);
			 printf("删除成功\n");
			 printf("\n");
		 }
		 else if (option == 5)
		 {
			 SLPrint(&s);
			 printf("打印成功\n");
			 printf("\n");
		 }
		 else if (option == 0)
		 {
			 printf("退出程序\n");
			 break;
		 }
		 else
		 {
			 printf("无此操作\n");
			 printf("\n");
		 }


	 } while (option != 0);

	 SLDestroy(&s);
	 return 0;
 }



 //int main()
 //{
 //	//TestSL1();
 //	//TestSL2();
 //	//TestSL3();
 //	//越界一定报错吗
 //	/*int a[10];*/
 //	//越界读基本不会报错（C语言）
 //	/*printf(a[10]);
 //	printf(a[11]);*/
 //	//越界写可能会报错
 //	/*a[10] = 1;
 //	a[11] = 1;
 //	a[15] = 1;*/
 //	//TestSL4();
 //	//TestSL5();
 //	//TestSL6();
 //
 //	return 0;
 //}



