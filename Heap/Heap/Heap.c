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





//// 升序建大堆
//void AdjustUp(HPDataType* a, int child) // 向上调整
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
//// 升序建大堆
//void AdjustDown(HPDataType* a, int size, int parent)  // 向下调整
//{
//	// 假设左孩子小，如果不是，更新成右孩子
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


//降序建小堆
void AdjustUp(HPDataType * a, int child) // 向上调整
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

//降序建小堆
void AdjustDown(HPDataType * a, int size, int parent)  // 向下调整
{
	// 假设左孩子小，如果不是，更新成右孩子
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

	//php->a[php->size] = x; // C28182警告
	//php->size++;

	// 上述代码会有C28182警告的原因在于判断tmp是否为空的时候，使用了exit(-1)，
	// exit(-1) 被用于处理 realloc 失败的情况。当 realloc 失败时，
	// tmp 指针将保持为 NULL，因为 realloc 没有成功分配新的内存。
	// 在这种情况下，如果继续执行 php->a[php->size] = x;，
	// 就会尝试取消引用一个 NULL 指针，这正是 C28182 警告所指出的问题。
	// 
	// 在下述代码中，return 被用于处理 realloc 失败的情况。
	// 这意味着当 realloc 失败时，函数会立即返回，不会执行后续的代码，
	// 包括 php->a[php->size] = x;。因此，不会有取消引用 NULL 指针的风险，
	// 所以不会触发 C28182 警告。

	assert(php);
	if (php->size == php->capacity)
	{
		size_t newcapacity = php->capacity == 0 ? 4 : php->capacity * 2; //如果栈的当前容量为0，将其设为4，否则将其扩大为当前容量的两倍
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp; //将原来栈中数据的指针更新为新的内存空间的指针
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












