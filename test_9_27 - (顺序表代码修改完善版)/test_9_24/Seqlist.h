//#pragma once
//#define N 1000
//typedef int SeqListDataType;
//
//��̬˳���̫���� ���˾Ͳ岻��ȥ�ˣ��ռ�̫���ò���ͻ��˷�

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

typedef struct SeqList//���Ƕ�����ݵĴ洢������֮ǰѧ�Ľṹ��
{
	SeqListDataType* a;
	int size;//��ʾ�������Ѿ����˶��ٸ�����
	int capacity;//�����ܴ�ʵ�ʿռ������ж�����ݸ�������λ������  ���Է���д���ݺ���
}SeqList;//�̶���ʽ ��ͨ���ṹ�彨��һ��˳���

//�ӿں���������һЩ���� ��ɾ���
//����������STL��  STL��C++��һ����
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListPushBack(struct SeqList*ps,SeqListDataType x );//β��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPushFront(struct SeqList*ps,SeqListDataType x );//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListPrint(SeqList* ps);
void SeqListDestory(SeqList* ps); 


int SeqListFind(SeqList* ps,SeqListDataType x); //�ҵ������±꣬û�ҵ�����-1
void SeqListInsert(SeqList* ps,int pos,SeqListDataType x); //��pos �±�λ�ò���
void SeqListDelete(SeqList* ps,int pos);//��pos �±�λ��ɾ��