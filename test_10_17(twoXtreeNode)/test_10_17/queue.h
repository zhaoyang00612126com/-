#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//ǰ������
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

void QueuePush(Queue*pq, QDtatType x);//��β��
void QueuePop(Queue*pq);//��ͷ��

//ȡ��ͷ��β������
QDtatType QueueFront(Queue*pq);
QDtatType QueueBack(Queue*pq);

int QueueSize(Queue*pq);//ȡ���ݵĸ���

bool QueueEmpty(Queue*pq);//�ж϶����Ƿ�Ϊ��