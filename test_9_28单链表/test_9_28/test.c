#include<stdio.h>
#include"Slist.h"

//形参的改变不影响实参
void testslist1()
{
	SLTNode*plist=NULL;//不需要初始化  直接给个空就可以  //形参的改变不影响实参
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