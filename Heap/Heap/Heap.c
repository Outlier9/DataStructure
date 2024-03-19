#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Heap.h"
#include<assert.h>

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}


void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}





//// ���򽨴��
//void AdjustUp(HPDataType* a, int child) // ���ϵ���
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (parent - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//// ���򽨴��
//void AdjustDown(HPDataType* a, int size, int parent)  // ���µ���
//{
//	// ��������С��������ǣ����³��Һ���
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}


//����С��
void AdjustUp(HPDataType * a, int child) // ���ϵ���
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//����С��
void AdjustDown(HPDataType * a, int size, int parent)  // ���µ���
{
	// ��������С��������ǣ����³��Һ���
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	//assert(php);
	//if (php->size == php->capacity)
	//{
	//	size_t newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
	//	HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
	//	if (tmp == NULL)
	//	{
	//		perror("realloc fail");
	//		exit(-1);
	//	}

	//	php->a = tmp;
	//	php->capacity = newCapacity;
	//}

	//php->a[php->size] = x; // C28182����
	//php->size++;

	// �����������C28182�����ԭ�������ж�tmp�Ƿ�Ϊ�յ�ʱ��ʹ����exit(-1)��
	// exit(-1) �����ڴ��� realloc ʧ�ܵ�������� realloc ʧ��ʱ��
	// tmp ָ�뽫����Ϊ NULL����Ϊ realloc û�гɹ������µ��ڴ档
	// ����������£��������ִ�� php->a[php->size] = x;��
	// �ͻ᳢��ȡ������һ�� NULL ָ�룬������ C28182 ������ָ�������⡣
	// 
	// �����������У�return �����ڴ��� realloc ʧ�ܵ������
	// ����ζ�ŵ� realloc ʧ��ʱ���������������أ�����ִ�к����Ĵ��룬
	// ���� php->a[php->size] = x;����ˣ�������ȡ������ NULL ָ��ķ��գ�
	// ���Բ��ᴥ�� C28182 ���档

	assert(php);
	if (php->size == php->capacity)
	{
		size_t newcapacity = php->capacity == 0 ? 4 : php->capacity * 2; //���ջ�ĵ�ǰ����Ϊ0��������Ϊ4������������Ϊ��ǰ����������
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp; //��ԭ��ջ�����ݵ�ָ�����Ϊ�µ��ڴ�ռ��ָ��
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);


}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size]-1);
	php->size--;

	AdjustDown(php->a, php->size, 0);


}


HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}


size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}












