#include "Seqlist.h"
#include "assert.h"
void TestSeqList1()
{
	SeqList S1;
	SeqListInit(&S1);
	 SeqListPushBack(&S1,1);
	 SeqListPushBack(&S1,2);
	 SeqListPushBack(&S1,3);
	 SeqListPushBack(&S1,4);
	 SeqListPushBack(&S1,5);
	 SeqListPushBack(&S1,6);
	 SeqListPrint(&S1);
	  SeqListPushFront(&S1,20);//Í·²å
	  SeqListPrint(&S1);
	   SeqListPopFront(&S1);
	   SeqListPrint(&S1);
	 
	   SeqListPopFront(&S1);
	   SeqListPrint(&S1);

	   SeqListDestory(&S1);
}



int main()
{

	TestSeqList1();
	return 0;
}