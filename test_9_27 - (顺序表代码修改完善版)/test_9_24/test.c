#include "Seqlist.h"
#include "assert.h"
//void TestSeqList1()
//{
//	SeqList S1;
//	SeqListInit(&S1);
//	 SeqListPushBack(&S1,1);
//	 SeqListPushBack(&S1,2);
//	 SeqListPushBack(&S1,3);
//	 SeqListPushBack(&S1,4);
//	 SeqListPushBack(&S1,5);
//	 SeqListPushBack(&S1,6);
//	 SeqListPrint(&S1);
//	  
//	 
//	 SeqListPushFront(&S1,20);//Õ∑≤Â
//	  SeqListPrint(&S1);
//	  
//	  SeqListPopFront(&S1);
//	   SeqListPrint(&S1);
//	   
//	   
//	   SeqListPopFront(&S1);
//	   SeqListPrint(&S1);
//
//	   SeqListDestory(&S1);
//}
//
//void TestSeqList2()
//{
//	 int pos=0;	
//	SeqList S2;
//		SeqListInit(&S2);
//		SeqListPushBack(&S2,1);
//	 SeqListPushBack(&S2,2);
//	 SeqListPushBack(&S2,3);
//	 SeqListPushBack(&S2,4);
//	 SeqListPushBack(&S2,5);
//	 SeqListPushBack(&S2,6);
//	 SeqListPrint(&S2);
//	 SeqListInsert(&S2,2,200);
//	 SeqListPrint(&S2);
//	
//	 pos=SeqListFind(&S2,4);
//	 if(pos!=-1)
//	 {
//		 SeqListInsert(&S2,5,700);
//	 
//	 }
//	 
//	 SeqListPushFront(&S2,-1 );
//	 SeqListPrint(&S2);
//	 SeqListDelete(&S2,3);
//	 SeqListPrint(&S2);
//	 SeqListDestory(&S2);
//}

void menu()
{
	printf("*****************************************\n");
	printf("«Î ‰»Î÷µ£∫\n");
	printf("1°¢Õ∑≤Â    2°¢Œ≤≤Â  \n  ");
	printf("1°¢Õ∑…æ    2°¢Œ≤…æ  \n  ");
	printf("*****************************************\n");
	
}

int main()
{
	int i=0;
	/*TestSeqList1();*/
	/*TestSeqList2();*/
	
	while(i!=-1)
	{
	SeqList S1;
	SeqListInit(&S1);
	SeqListPushBack(&S1,1);
	SeqListPushBack(&S1,2);
	SeqListPushBack(&S1,3);
	SeqListPushBack(&S1,4);
	 SeqListPrint(&S1); 
	menu();
	scanf("%d",&i);

		switch(i)
	{
	case 1:
		SeqListPushFront(&S1,20);
		 SeqListPrint(&S1);
		 break;
	case 2:
		SeqListPushBack(&S1,1);
		 SeqListPrint(&S1);
		  break;
	case 3:
		SeqListPopFront(&S1);
		 SeqListPrint(&S1);
		  break;
	case 4:
		SeqListPopBack(&S1);
		 SeqListPrint(&S1);
		  break;
	
	}
	
	
}


	/*if(i=1)
	{
		SeqListPushFront(&S1,20);
		 SeqListPrint(&S1);
	}
	else if(i=2)
	{
		SeqListPushBack(&S1,1);
		 SeqListPrint(&S1);
	}
	else if(i=3)
	{
		SeqListPopFront(&S1);
		 SeqListPrint(&S1);
	}
	else if(i=4)
	{
		SeqListPopBack(&S1);
		 SeqListPrint(&S1);
	}*/
	return 0;
}