#include"list.h"

void test1()
{
	
	ListNode*Plist=ListInit();
	//ListDestory(&Plist);
	ListPushBack(Plist,1);
	ListPushBack(Plist,2);
	ListPushBack(Plist,3);
	ListPrint(Plist);


}

int main()
{
	test1();
	return 0;

}
