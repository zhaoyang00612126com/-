#include<stdio.h>
#include"Slist.h"

//�βεĸı䲻Ӱ��ʵ��
void testslist1()
{
	SLTNode*plist=NULL;//����Ҫ��ʼ��  ֱ�Ӹ����վͿ���  //�βεĸı䲻Ӱ��ʵ��
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);

	SListPrint(plist);

	PushFront(&plist,1);
	PushFront(&plist,2);
	PushFront(&plist,3);
	PushFront(&plist,4);
	SListPrint(plist);

	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	SListPrint(plist);

	PopFront(&plist);
	
	SListPrint(plist);
}


int main()
{

	testslist1();
	
	return 0;
}