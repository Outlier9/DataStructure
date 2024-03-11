#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
	return 0;
}