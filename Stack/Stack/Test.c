#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Stack.h"

int main()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	printf("%d ", STTop(&s));
	STPop(&s);
	STPush(&s, 4);
	STPush(&s, 5);

	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	printf("\n");
	return 0;
}