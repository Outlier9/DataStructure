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
//	// 排序，每次输出top，然后删除top，top调整为次大/次小
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
//	// 建堆，本质是模拟堆插入过程
//	// 升序建大堆
//	// 降序建小堆
//	// O(N*logN)
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//
//	//向下调整建堆
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


// 堆排序
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
//	//造数据
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
//	// 建一个k个数的小堆
//	int* minheap = (int*)malloc(sizeof(int) * k);
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	// 读取前k个，建小堆
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

// 创建树
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

// 前序遍历
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

// 中序遍历
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

// 后序遍历
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

//二叉树的节点个数
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

//二叉树叶子结点个数
int TreeLeafSize(TreeNode* root)
{
	//空返回0
	if (root == NULL)
	{
		return 0;
	}
	//不是空，是叶子，返回1
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	//不是空也不是叶子 分治=左右叶子之和
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// 二叉树的深度
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

// 第K层节点个数
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

//二叉树查找值为x的结点
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

// 通过前序遍历的数组“ABD##E#H##CF##G##”构建二叉树
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

// 层序遍历代码在最后，要在main函数之前先进行声明
void LevelOrder(TreeNode* root);
// 输出每一层的声明
void EveryLevelOrder(TreeNode* root);
//判断二又树是否是完全二又树的声明
int TreeComplete(TreeNode* root);

int main()
{
	TreeNode* root = CreateTree();
	// 前序遍历
	PrevOrder(root);
	printf("\n");
	// 中序遍历
	InOrder(root);
	printf("\n");
	// 后序遍历
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
	printf("TreeComplete:%d\n", TreeComplete(root));// 当前树不是完全二叉树，把node2指向node7就成了完全二叉树了
	// node5->right = node7;变为node2->right = node7;

	DestroyTree(root);
	root = NULL;
}



// 层序遍历用到的队列
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
	// 空节点
	assert(pq->phead);
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	// 一个节点的时候，phead向前走
	// del被free，ptail此时和del指的是一个节点，如果free，就变成了野指针
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	// 空节点
	assert(pq->phead);

	return pq->phead->val;
}


QDataType QueueBack(Queue* pq)
{
	assert(pq);
	// 空节点
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




// 层序遍历
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

// 每一行跟一个换行
void EveryLevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;// 当前层的个数

	while (!QueueEmpty(&q))
	{
		while (levelSize--) // 减到0表示这一层出完了，也就是下一层都带入了，当前队列里都是下一层的数
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
		levelSize = QueueSize(&q); //记录下一层的个数，也就是当前队列里的个数
	}
	printf("\n");
	QueueDestroy(&q);

}

//判断二又树是否是完全二又树
int TreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;// 当前层的个数

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	// 层序遍历的原理入队列，前边遇到空以后，后面还有非空就不是完全二叉树
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
