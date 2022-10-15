#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode*next;
	struct ListNode*prev;
	LTDataType data;

}ListNode;


ListNode* ListInit();
void ListDestory(ListNode*plist);
void ListPushBack(ListNode*phead, LTDataType x);
void ListPrint(ListNode*phead);
void ListPushFront(ListNode*phead, LTDataType x);//ͷ��
void ListPopFront(ListNode*phead);// ͷɾ
void ListPopBack(ListNode*phead);// βɾ
void ListFind(ListNode*phead,LTDataType x);// ����
void ListInsert(ListNode*phead, LTDataType x);