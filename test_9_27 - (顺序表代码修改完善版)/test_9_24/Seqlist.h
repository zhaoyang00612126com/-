//#pragma once
//#define N 1000
//typedef int SeqListDataType;
//
//静态顺序表，太死了 满了就插不进去了，空间太大用不完就会浪费

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

typedef struct SeqList//凡是多个数据的存储上我们之前学的结构体
{
	SeqListDataType* a;
	int size;//表示数组中已经存了多少个数据
	int capacity;//数组能存实际空间容量有多大，数据个数，单位个数，  可以方便写扩容函数
}SeqList;//固定格式 ，通过结构体建立一个顺序表

//接口函数，定义一些函数 增删查改
//命名风格跟着STL走  STL是C++的一个库
void SeqListInit(SeqList* ps);//初始化
void SeqListPushBack(struct SeqList*ps,SeqListDataType x );//尾插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPushFront(struct SeqList*ps,SeqListDataType x );//头插
void SeqListPopFront(SeqList* ps);//头删
void SeqListPrint(SeqList* ps);
void SeqListDestory(SeqList* ps); 


int SeqListFind(SeqList* ps,SeqListDataType x); //找到返回下标，没找到返回-1
void SeqListInsert(SeqList* ps,int pos,SeqListDataType x); //在pos 下标位置插入
void SeqListDelete(SeqList* ps,int pos);//在pos 下标位置删除