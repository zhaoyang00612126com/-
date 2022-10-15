#include"queue.h"

void QueueInit(Queue*pq)//*pqΪ�������õĽṹ��ĵ�ַ��Ȼ�����ǾͿ��Ըı�������
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestory(Queue*pq)
{
	assert(pq);
	QNode*cur = pq->head;
	while (cur != NULL)
	{
		QNode*next = cur->next;//�Ȱ���һ��������
		free(cur);
		cur = next;

	
	}
	pq->head = pq->tail = NULL;


}
void QueuePush(Queue*pq, QDtatType x)//��β��
{
	assert(pq);
	QNode*newnode = (QNode*)malloc(sizeof(QNode));//��Ūһ���µĽڵ������
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = pq->tail->next;
	}
}


void QueuePop(Queue*pq)//��ͷ��
{
	assert(pq);
	assert(pq->head);

	if (pq->head->next == NULL)//�����Ŀ����Ϊ�˷�ֹ����ֻ��һ���ڵ��ʱ�򣬳���tailҰָ������
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//����ڵ�����
	{

		//�ȱ�����һ��
			QNode*next = pq->head->next;
			free(pq->head);
			pq->head = next;
	}

	

}

//ȡ��ͷ��β������
QDtatType QueueFront(Queue*pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;


}

QDtatType QueueBack(Queue*pq)
{

	assert(pq);
	assert(pq->head);
	return pq->tail->data;

}

int QueueSize(Queue*pq)//ȡ���ݵĸ���
{
	assert(pq);
	int size = 0;
	QNode*cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue*pq)//�ж϶����Ƿ�Ϊ��
{
	assert(pq);
	return pq->head == NULL;//���ڿ����棬�����ڿ����


}