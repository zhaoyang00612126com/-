#pragma once
#include<stdio.h>
#include<stdlib.h>
//һ��һ����������������ڴ�
typedef int SListDateType;
//��ʽ�ṹ��������ض���ΪSListNode�����SListNode��ʾһ���ṹ��
//�����Ŀ��ʹ�õ�������ṹ���һ��ȫ�ֱ�����SLTNode��
typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode*phead);//phea��ʾָ���һ������ͷָ��
void PushBack(SLTNode**phead,SListDateType x);//β��
void PushFront(SLTNode**phead,SListDateType x);//ͷ��
void PopBack(SLTNode**phead);
void PopFront(SLTNode**phead);

SLTNode*SListFind(SLTNode*phead,SListDateType x);//����
void SListInsert(SLTNode**phead,SLTNode*pose,SListDateType x);//����
void SListErase(SLTNode**phead,SLTNode*pose);//ɾ��
void SListDestory(SLTNode**phead);//�ݻ�