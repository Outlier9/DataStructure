#pragma once

//˳����������Ͷ���
typedef int SLDataType;

//��̬�洢
typedef struct SeqList
{
	SLDataType* a; // ָ��̬���ٵ�����
	int size;  // ��Ч���ݸ���
	int capacity;  // �ռ�������С
}SL;

void SLInit(SL* ps); // ��ʼ��
void SLDestroy(SL* ps); // ����

void SLPushBack(SL* psl, SLDataType x); // β����
void SLPushFront(SL* psl, SLDataType x); // ͷ����

void SLPopBack(SL* psl); // βɾ��
void SLPopFront(SL* psl); // ͷɾ��

void SLPrint(SL* psl); //˳���Ĵ�ӡ

void SLCheckCapacity(SL* psl); // ����ǰ���пռ��ѯ�����Ƿ���

void SLInsert(SL* psl, int pos, SLDataType x); // ����λ�ø����±����
void SLErase(SL* psl, int pos); // ����λ�ø����±�ɾ��

int SLFind(SL* psl, SLDataType x);// ���ң��ҵ������±꣬û���ҵ�����-1