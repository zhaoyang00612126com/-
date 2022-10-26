//#pragma once
//
//#include<stdio.h>
//typedef int STDataType;
//#define MAX 100
//typedef struct Stack
//{
//	STDataType a[MAX];
//	int top;
//
//}Stack;
//�����Ǿ�̬����̫�ÿ���MAX�Ĵ�С�����ܻ�����˷ѻ��߲����������ݣ���������д�ɶ�̬
//������Ƕ�̬��
#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>//һ������Ϊ�յĶ��������Կ����ö���������
#include<stdlib.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPushBack(Stack* ps, STDataType x);//��ջ
void  StackPop(Stack* ps);//��ջ
 STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);//�վͷ���1���ǿվͷ���0



