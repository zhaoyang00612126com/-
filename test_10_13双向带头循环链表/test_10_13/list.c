#include"list.h"

ListNode*BuyListNode(LTDataType x)//����һ����Ҫ�Ľڵ�
{
	ListNode*newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
}

ListNode* ListInit()//��ʼ��
{
	ListNode*phead = BuyListNode(0);
	phead->next = phead;//��ַ���Լ���
	phead->prev = phead;
	return phead;
}
void ListDestory(ListNode*plist);
void ListPushBack(ListNode*phead, LTDataType x)//β��
{
	ListNode*tail = phead->prev;//�ҵ�β���
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


void ListPushFront(ListNode*phead, LTDataType x)//ͷ��
{
	ListNode*first = phead->next;//ԭ���ĵ�һ���ڵ�
	ListNode*newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

}

void ListPopFront(ListNode*phead, LTDataType x)//ͷɾ
{
	assert(phead->next != phead);//�ж��ǲ���һ���ڵ�Ҳû��
	ListNode*first = phead->next;
	ListNode*second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

void ListPopBack(ListNode*phead)
{
	assert(phead->next != phead);//�ж��ǲ���һ���ڵ�Ҳû��
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


void ListInsert(ListNode*pos, LTDataType x)//��posǰ����һ��
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
