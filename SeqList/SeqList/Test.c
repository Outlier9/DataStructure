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
	SLPushBack(&sl, 9); // β����
	SLPrint(&sl);

	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40); // ͷ����

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

	SLPopBack(&sl); // βɾ��
	SLPrint(&sl); 
	//����free��Ҫ�ͷž�ȫ���ͷţ������������ֱ�Ӹ��ǣ��ռ��ظ�����
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPopBack(&sl); 
	SLPrint(&sl);
	
	// ��ʱsize�Ѿ���0�ˣ�ִ����һ����size�������-1
	SLPopBack(&sl);
	SLPrint(&sl);

	// �������ݺ�sizeӦ����4��������һ����ԭ������sizeΪ3��ʹ���ս��ֻ������3�����������ж�size�Ƿ�Ϊ0�������ڲ���������
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

	SLPopFront(&sl); // ͷɾ��
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

	SLInsert(&sl, 2, 20);// ����λ�ø����±����
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

	SLErase(&sl, 2);// ����λ�ø����±�ɾ��
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

	int pos = SLFind(&sl, 2); //�ҵ��±�Ϊ2��
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
	 printf("****1.β������ 2.βɾ����****\n");
	 printf("****3.ͷ������ 4.ͷɾ����****\n");
	 printf("****5.��ӡ���� 0.�˳�����****\n");
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
		 printf("���������ѡ��>");
		 scanf("%d", &option);


		 if (option == 1)
		 {
			 printf("��������Ҫβ������ݸ��������ݣ�>\n");
			 int n = 0;//����
			 scanf("%d", &n);

			 for (int i = 0; i < n; i++)
			 {
				 int x = 0;//����
				 scanf("%d", &x);
				 SLPushBack(&s, x);
			 }
			 printf("\n");
		 }
		 else if(option == 2)
		 {
			 SLPopBack(&s);
			 printf("ɾ���ɹ�\n");
			 printf("\n");
			 }
		 else if (option == 3)
		 {
			 printf("��������Ҫͷ������ݣ���-1������>\n");
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
			 printf("ɾ���ɹ�\n");
			 printf("\n");
		 }
		 else if (option == 5)
		 {
			 SLPrint(&s);
			 printf("��ӡ�ɹ�\n");
			 printf("\n");
		 }
		 else if (option == 0)
		 {
			 printf("�˳�����\n");
			 break;
		 }
		 else
		 {
			 printf("�޴˲���\n");
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
 //	//Խ��һ��������
 //	/*int a[10];*/
 //	//Խ����������ᱨ��C���ԣ�
 //	/*printf(a[10]);
 //	printf(a[11]);*/
 //	//Խ��д���ܻᱨ��
 //	/*a[10] = 1;
 //	a[11] = 1;
 //	a[15] = 1;*/
 //	//TestSL4();
 //	//TestSL5();
 //	//TestSL6();
 //
 //	return 0;
 //}



