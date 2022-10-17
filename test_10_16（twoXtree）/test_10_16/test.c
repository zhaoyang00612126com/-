#include<stdio.h>
#include<stdlib.h>

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
		return;
	}
	printf("%c  ",root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode*root)//�������������һ����
{


}
void PostOrder(BTNode*root)//�������������һ����
{


}

int main()
{
	BTNode*A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	
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


	return 0;
}