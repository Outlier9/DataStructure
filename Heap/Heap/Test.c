#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Heap.h"
#include<math.h>


//int main()
//{
//	int a[] = { 3,5,7,4,5,7,2,4 };
//
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp,a[i]);
//	}
//
//	/*int k = 3;
//	while (k--)
//	{
//		printf("%d\n", HeapTop(&hp));
//		HeapPop(&hp);
//	}*/
//
//	// ����ÿ�����top��Ȼ��ɾ��top��top����Ϊ�δ�/��С
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//
//	return 0;
//}


//void HeapSort(int* a, int n)
//{
//	// ���ѣ�������ģ��Ѳ������
//	// ���򽨴��
//	// ����С��
//	// O(N*logN)
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//
//	//���µ�������
//	//O(n)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}


// ������
//int main()
//{
//	int a[] = { 1,2,6,4,5,9,2,8 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//void CreateNDate()
//{
//	//������
//	int n = 10000000;
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int x = (rand() + i) % 10000000;
//		fprintf(fin, "%d\n", x);
//	}
//	fclose(fin);
//}
//
//void PrintTopK(const char* file, int k)
//{
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	// ��һ��k������С��
//	int* minheap = (int*)malloc(sizeof(int) * k);
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	// ��ȡǰk������С��
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &minheap[i]);
//		AdjustUp(minheap, i);
//	}
//
//	int x = 0;
//	while (fscanf(fout, "%d", &x)!= EOF)
//	{
//		if (x > minheap[0])
//		{
//			minheap[0] = x;
//			AdjustDown(minheap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", minheap[i]);
//	}
//	printf("\n");
//
//	free(minheap);
//
//	fclose(fout);
//}
//
//int main()
//{
//	//CreateNDate();
//	//PrintTopK("data.txt", 8);
//
//	return 0;
//}



typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// ������
TreeNode* CreateTree()
{
	TreeNode* node1 = BuyTreeNode(1);
	TreeNode* node2 = BuyTreeNode(2);
	TreeNode* node3 = BuyTreeNode(3);
	TreeNode* node4 = BuyTreeNode(4);
	TreeNode* node5 = BuyTreeNode(5);
	TreeNode* node6 = BuyTreeNode(6);
	TreeNode* node7 = BuyTreeNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

// ǰ�����
void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

// �������
void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

// �������
void AfterOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	AfterOrder(root->left);
	AfterOrder(root->right);
	printf("%d ", root->data);
}

//�������Ľڵ����
int TreeSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->left) + TreeSize(root->right);
	}

}

//������Ҷ�ӽ�����
int TreeLeafSize(TreeNode* root)
{
	//�շ���0
	if (root == NULL)
	{
		return 0;
	}
	//���ǿգ���Ҷ�ӣ�����1
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	//���ǿ�Ҳ����Ҷ�� ����=����Ҷ��֮��
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// �����������
int TreeHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + fmax(TreeHeight(root->left), TreeHeight(root->right));
	}
}

// ��K��ڵ����
int TreeLevelK(TreeNode* root, int k)
{
	assert(k > 0);
	if (root == 0)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevelK(root->left, k-1) + TreeLevelK(root->right, k-1);
}

//����������ֵΪx�Ľ��
TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	TreeNode* ret1 = TreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	TreeNode* ret2 = TreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}
}

// ͨ��ǰ����������顰ABD##E#H##CF##G##������������
TreeNode* TreeCreate(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		printf("%d", *pi);
		return NULL;
	}
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->data = a[(*pi)++];
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);
	return root;
}


void DestroyTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

// ����������������Ҫ��main����֮ǰ�Ƚ�������
void LevelOrder(TreeNode* root);
// ���ÿһ�������
void EveryLevelOrder(TreeNode* root);
//�ж϶������Ƿ�����ȫ������������
int TreeComplete(TreeNode* root);

int main()
{
	TreeNode* root = CreateTree();
	// ǰ�����
	PrevOrder(root);
	printf("\n");
	// �������
	InOrder(root);
	printf("\n");
	// �������
	AfterOrder(root);
	printf("\n");

	LevelOrder(root);
	EveryLevelOrder(root);
	
	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeLevelK:%d\n", TreeLevelK(root,3));
	printf("TreeFind:%p\n", TreeFind(root,3));

	TreeNode* ret = TreeFind(root, 5);
	printf("TreeFind:%p\n", ret);
	/*ret->data++;*/
	printf("TreeComplete:%d\n", TreeComplete(root));// ��ǰ��������ȫ����������node2ָ��node7�ͳ�����ȫ��������
	// node5->right = node7;��Ϊnode2->right = node7;

	DestroyTree(root);
	root = NULL;
}



// ��������õ��Ķ���
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}


void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


void QueuePop(Queue* pq)
{
	assert(pq);
	// �սڵ�
	assert(pq->phead);
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	// һ���ڵ��ʱ��phead��ǰ��
	// del��free��ptail��ʱ��delָ����һ���ڵ㣬���free���ͱ����Ұָ��
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	// �սڵ�
	assert(pq->phead);

	return pq->phead->val;
}


QDataType QueueBack(Queue* pq)
{
	assert(pq);
	// �սڵ�
	assert(pq->phead);

	return pq->ptail->val;
}


bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}


int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}




// �������
void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
	QueueDestroy(&q);

}

// ÿһ�и�һ������
void EveryLevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;// ��ǰ��ĸ���

	while (!QueueEmpty(&q))
	{
		while (levelSize--) // ����0��ʾ��һ������ˣ�Ҳ������һ�㶼�����ˣ���ǰ�����ﶼ����һ�����
		{
			TreeNode* front = QueueFront(&q);
			QueuePop(&q);
			printf("%d ", front->data);

			if (front->left)
				QueuePush(&q, front->left);
			if (front->right)
				QueuePush(&q, front->right);
		}
		printf("\n");
		levelSize = QueueSize(&q); //��¼��һ��ĸ�����Ҳ���ǵ�ǰ������ĸ���
	}
	printf("\n");
	QueueDestroy(&q);

}

//�ж϶������Ƿ�����ȫ������
int TreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;// ��ǰ��ĸ���

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	// ���������ԭ������У�ǰ���������Ժ󣬺��滹�зǿվͲ�����ȫ������
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}
