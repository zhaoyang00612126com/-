//#pragma once
//#define N 1000
//typedef int SeqListDataType;
//
//静态顺序表
//typedef struct SeqList
//{
//	SeqListDataType a[N];
//	int size;//表示数组中存了多少个数据
//}SeqList;
//
//void SeqListInit(SeqList* ps);
//void SeqListPushBack(struct SeqList*pc,SeqListDataType x );
//void SeqListPopBack(SeqList* ps);
//void SeqListPushFront(struct SeqList*pc,SeqListDataType x );
//void SeqListPopFront(SeqList* ps);


//动态顺序表
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SeqListDataType;

typedef struct SeqList
{
	SeqListDataType* a;
	int size;//表示数组中存了多少个数据
	int capacity;//数组能存实际空间容量有多大，数个据数，单位个数
}SeqList;//固定格式 ，通过结构体建立一个顺序表

//定义一些函数
void SeqListInit(SeqList* ps);//初始化
void SeqListPushBack(struct SeqList*ps,SeqListDataType x );//尾插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPushFront(struct SeqList*ps,SeqListDataType x );//头插
void SeqListPopFront(SeqList* ps);//头删
void SeqListPrint(SeqList* ps);
void SeqListDestory(SeqList* ps);