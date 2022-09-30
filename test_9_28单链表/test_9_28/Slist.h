#pragma once
#include<stdio.h>
#include<stdlib.h>
//一个一个按需向堆上申请内存
typedef int SListDateType;
//链式结构体的名称重定义为SListNode，这个SListNode表示一个结构体
//这个项目中使用到的这个结构体的一个全局变量是SLTNode。
typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode*phead);//phea表示指向第一个结点的头指针
void PushBack(SLTNode**phead,SListDateType x);//尾插
void PushFront(SLTNode**phead,SListDateType x);//头插
void PopBack(SLTNode**phead);
void PopFront(SLTNode**phead);

SLTNode*SListFind(SLTNode*phead,SListDateType x);//查找
void SListInsert(SLTNode**phead,SLTNode*pose,SListDateType x);//插入
void SListErase(SLTNode**phead,SLTNode*pose);//删除
void SListDestory(SLTNode**phead);//摧毁