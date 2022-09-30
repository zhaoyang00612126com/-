#include"Slist.h"
#include<stdlib.h>
//��ʽ�ṹ��������ض���ΪSListNode�����SListNode��ʾһ���ṹ��
//�����Ŀ��ʹ�õ�������ṹ���һ��ȫ�ֱ�����SLTNode��
void SListPrint(SLTNode*phead)
{
	
	SLTNode* cur=phead;//��һ����ʾ��ַ��ָ��ȥָ����
	while(cur!=NULL)
	{
		printf("%d ",cur->data);//cur��һ��ָ���ַ�ı���������Ϊָ�����
		cur=cur->next;
	
	}
	printf("\n");
}

void PushBack(SLTNode**phead,SListDateType x)//β��
{
	//�������Ϊ�գ�û��β���Ļ�����һ��newnode
	SLTNode* newnode;
	
	newnode=(SLTNode*)malloc(sizeof(SLTNode));//�����е���˼�Ǵ���һ���µĽ�㣬�����п���ר������һ������
	newnode->data=x;
	newnode->next=NULL;
	
	//�������Ϊ�գ�û��β���Ļ�����һ��newnode
	if(*phead==NULL)
	{
		*phead=newnode;
	}
	else 
	{
		//�ҵ�β�ڵ�
		SLTNode*tail=*phead;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next=newnode;
	}
	
}


void PushFront(SLTNode**phead,SListDateType x)//ͷ��
{
	SLTNode* newnode;
	
	newnode=(SLTNode*)malloc(sizeof(SLTNode));//�����½��
	newnode->data=x;
	newnode->next=NULL;

	newnode->next=*phead;
	*phead=newnode;
}

void PopBack(SLTNode**phead)//βɾ
{
	SLTNode*tail;
	SLTNode*prev;
	tail=*phead;
	prev=NULL;
	if(*phead==NULL)
	{
		return;
	}

	while(tail->next!=NULL)
	{
		prev=tail;
		tail=tail->next;
	}
	free(tail);
	tail=NULL;
	prev->next=NULL;

}

void PopFront(SLTNode**phead)//ͷɾ
{
	
	if(!(*phead))
	{
		return ;
	}
	
	
	else{
	SLTNode*next=(*phead)->next;
	free(*phead);
	*phead=next;
	}
	//else
	//{
	//	tail=*phead;//plist
	//	tail=tail->next;
	//	*phead=tail;
	//	free(tail);
	//}	
}



SLTNode*SListFind(SLTNode*phead,SListDateType x)//����
{
	SLTNode*cur=phead;
	
	
	while(cur)//����
	{
		if(cur->data==x)
		{
			return cur;
		}
		else
		{
			cur=cur->next;
		}
	}
	return NULL;
}


void SListInsert(SLTNode**phead,SLTNode*pose,SListDateType x)//����
{


}
void SListErase(SLTNode**phead,SLTNode*pose);//ɾ��
void SListDestory(SLTNode**phead);//�ݻ�