#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//前置声明
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;
typedef BTNode* QDtatType;

typedef struct QueueNode
{
	struct QuedeNode*next;
	QDtatType data;



}QNode;


typedef struct Queue
{
	QNode*head;
	QNode*tail;

}Queue;

void QueueInit(Queue*pq);
void QueueDestory(Queue*pq);

void QueuePush(Queue*pq, QDtatType x);//队尾入
void QueuePop(Queue*pq);//队头出

//取队头队尾的数据
QDtatType QueueFront(Queue*pq);
QDtatType QueueBack(Queue*pq);

int QueueSize(Queue*pq);//取数据的个数

bool QueueEmpty(Queue*pq);//判断队列是否为空