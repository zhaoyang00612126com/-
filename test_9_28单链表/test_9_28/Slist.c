#include"Slist.h"
#include<stdlib.h>
//链式结构体的名称重定义为SListNode，这个SListNode表示一个结构体
//这个项目中使用到的这个结构体的一个全局变量是SLTNode。
void SListPrint(SLTNode*phead)
{
	
	SLTNode* cur=phead;//用一个表示地址的指针去指向他
	while(cur!=NULL)
	{
		printf("%d ",cur->data);//cur是一个指向地址的变量，，称为指针变量
		cur=cur->next;
	
	}
	printf("\n");
}

void PushBack(SLTNode**phead,SListDateType x)//尾插
{
	//如果链表为空，没有尾结点的话，建一个newnode
	SLTNode* newnode;
	
	newnode=(SLTNode*)malloc(sizeof(SLTNode));//这三行的意思是创立一个新的结点，这三行可以专门做成一个函数
	newnode->data=x;
	newnode->next=NULL;
	
	//如果链表为空，没有尾结点的话，建一个newnode
	if(*phead==NULL)
	{
		*phead=newnode;
	}
	else 
	{
		//找到尾节点
		SLTNode*tail=*phead;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next=newnode;
	}
	
}


void PushFront(SLTNode**phead,SListDateType x)//头插
{
	SLTNode* newnode;
	
	newnode=(SLTNode*)malloc(sizeof(SLTNode));//创立新结点
	newnode->data=x;
	newnode->next=NULL;

	newnode->next=*phead;
	*phead=newnode;
}

void PopBack(SLTNode**phead)//尾删
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

void PopFront(SLTNode**phead)//头删
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



SLTNode*SListFind(SLTNode*phead,SListDateType x)//查找
{
	SLTNode*cur=phead;
	
	
	while(cur)//遍历
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


void SListInsert(SLTNode**phead,SLTNode*pose,SListDateType x)//插入
{


}
void SListErase(SLTNode**phead,SLTNode*pose);//删除
void SListDestory(SLTNode**phead);//摧毁