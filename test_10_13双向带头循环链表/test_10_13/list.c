#include"list.h"

ListNode*BuyListNode(LTDataType x)//创建一个你要的节点
{
	ListNode*newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
}

ListNode* ListInit()//初始化
{
	ListNode*phead = BuyListNode(0);
	phead->next = phead;//地址存自己的
	phead->prev = phead;
	return phead;
}
void ListDestory(ListNode*plist);
void ListPushBack(ListNode*phead, LTDataType x)//尾插
{
	ListNode*tail = phead->prev;//找到尾结点
	ListNode*newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}

void ListPrint(ListNode*phead)
{
	ListNode*cur = phead->next;
	while (cur != phead)
	{
		printf("%d   ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void ListPushFront(ListNode*phead, LTDataType x)//头插
{
	ListNode*first = phead->next;//原本的第一个节点
	ListNode*newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

}

void ListPopFront(ListNode*phead, LTDataType x)//头删
{
	assert(phead->next != phead);//判断是不是一个节点也没有
	ListNode*first = phead->next;
	ListNode*second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

void ListPopBack(ListNode*phead)
{
	assert(phead->next != phead);//判断是不是一个节点也没有
	ListNode*tail = phead->prev;
	ListNode*prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;




}



void ListFind(ListNode*phead, LTDataType x)
{
	ListNode*cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur; 
		
		
		}
		else
		{
			cur = cur->next;
		}
		return NULL;
		ListPrint(phead);
	}


}


void ListInsert(ListNode*pos, LTDataType x)//在pos前插入一个
{
	ListNode*prev = pos->prev;
	ListNode*newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;


}

void ListErase(ListNode*pos)
{
	assert(pos);
	ListNode*prev = pos->prev;
	ListNode*next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
