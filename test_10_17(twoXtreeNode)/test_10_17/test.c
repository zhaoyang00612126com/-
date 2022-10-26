#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode*left;//����
	struct BinaryTreeNode*right;//�Һ���
	BTDataType data;
}BTNode;

void PrevOrder(BTNode*root)//ǰ�����������һ����
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	printf("%c     ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode*root)//�������������һ����
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	
	InOrder(root->left);
	printf("%c     ", root->data);
	InOrder(root->right);

}
void PostOrder(BTNode*root)//�������������һ����
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c      ", root->data);

}

//int size = 0;
//void TreeSize(BTNode*root)//�����������ڵ�ĸ���
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		size++;
//	}
//	TreeSize(root->left);
//	TreeSize(root->right);
//}


int TreeSize(BTNode* root)
{
	return root == NULL ? 0:TreeSize(root->left) + TreeSize(root->right)+1;

}


int TreeLeafSize(BTNode* root)//��Ҷ�ӽ��ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeafSize(root->left)+ TreeLeafSize(root->right);
	}
}


void levelOrder(BTNode* root)//�������Ĳ������
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q,root);
	}

	while (!QueueEmpty(&q))
	{
		
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//�Ѷ���ͷ���Ǹ����ó���
		printf("%c  ",front->data);

		if (front->left)
		{
			QueuePush(&q,front->left);
			
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}

	}
	printf("\n");
	QueueDestory(&q);
}

void DestoryTree(struct BinaryTreeNode* root)//��������
{
	if (root == NULL)
	{
		return;
	
	}
	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
	
}


int main()
{
	BTNode*A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left =NULL;
	A->right =NULL;

	BTNode*B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode*C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode*D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode*E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;


	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");
	
	PostOrder(A);
	printf("\n");
	
	InOrder(A);
	printf("\n");
	

	//TreeSize(A);
	//printf("TreeSize: %d\n",size);

	//size = 0;//��һ���������٣���Ȼsize�����
	//TreeSize(B);
	//printf("TreeSize: %d\n", size);
	/*int Asize = 0;
	TreeSize(A,&Asize);
	printf("TreeSize��%d\n", Asize);

	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize��%d\n", Bsize);*/

	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeSize:%d\n", TreeSize(B));


	levelOrder(A);
	return 0;
}


