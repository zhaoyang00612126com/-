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
void ListPushFront(ListNode*phead, LTDataType x);//Õ∑≤Â
void ListPopFront(ListNode*phead);// Õ∑…æ
void ListPopBack(ListNode*phead);// Œ≤…æ
void ListFind(ListNode*phead,LTDataType x);// ≤È’“
void ListInsert(ListNode*phead, LTDataType x);