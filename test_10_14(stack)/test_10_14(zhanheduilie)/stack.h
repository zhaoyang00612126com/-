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
//这种是静态，不太好控制MAX的大小，可能会造成浪费或者不够反复扩容，所以我们写成动态
//下面的是动态的
#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>//一定不能为空的东西，可以考虑用断言来处理。
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
void StackPushBack(Stack* ps, STDataType x);//入栈
void  StackPop(Stack* ps);//出栈
 STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);//空就返回1，非空就返回0



