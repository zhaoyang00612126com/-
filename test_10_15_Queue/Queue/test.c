#include"queue.h"

int main()
{

	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))//��ջһ����Ҫ��ɾ�߳�
	{
	
		printf("%d\n", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);


	return 0;
}
