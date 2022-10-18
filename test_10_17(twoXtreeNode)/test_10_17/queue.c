#include"queue.h"

void QueueInit(Queue*pq)//*pq为我们设置的结构体的地址，然后我们就可以改变它了捏
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
		QNode*next = cur->next;//先把下一个保存了
		free(cur);
		cur = next;

	
	}
	pq->head = pq->tail = NULL;


}
void QueuePush(Queue*pq, QDtatType x)//队尾入
{
	assert(pq);
	QNode*newnode = (QNode*)malloc(sizeof(QNode));//先弄一个新的节点出来；
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


void QueuePop(Queue*pq)//队头出
{
	assert(pq);
	assert(pq->head);

	if (pq->head->next == NULL)//这里的目的是为了防止队列只有一个节点的时候，出现tail野指针的情况
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//多个节点的情况
	{

		//先保存下一个
			QNode*next = pq->head->next;
			free(pq->head);
			pq->head = next;
	}

	

}

//取队头队尾的数据
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

int QueueSize(Queue*pq)//取数据的个数
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

bool QueueEmpty(Queue*pq)//判断队列是否为空
{
	assert(pq);
	return pq->head == NULL;//等于空则真，不等于空则假


}