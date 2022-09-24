//#pragma once
//#define N 1000
//typedef int SeqListDataType;
//
//��̬˳���
//typedef struct SeqList
//{
//	SeqListDataType a[N];
//	int size;//��ʾ�����д��˶��ٸ�����
//}SeqList;
//
//void SeqListInit(SeqList* ps);
//void SeqListPushBack(struct SeqList*pc,SeqListDataType x );
//void SeqListPopBack(SeqList* ps);
//void SeqListPushFront(struct SeqList*pc,SeqListDataType x );
//void SeqListPopFront(SeqList* ps);


//��̬˳���
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SeqListDataType;

typedef struct SeqList
{
	SeqListDataType* a;
	int size;//��ʾ�����д��˶��ٸ�����
	int capacity;//�����ܴ�ʵ�ʿռ������ж��������������λ����
}SeqList;//�̶���ʽ ��ͨ���ṹ�彨��һ��˳���

//����һЩ����
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListPushBack(struct SeqList*ps,SeqListDataType x );//β��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPushFront(struct SeqList*ps,SeqListDataType x );//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListPrint(SeqList* ps);
void SeqListDestory(SeqList* ps);