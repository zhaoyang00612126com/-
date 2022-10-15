
#include"stack.h"

int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	
	while (!StackEmpty(&ps))
	{
		printf("%d   ",StackTop(&ps));
		StackPop(&ps);
	}
	printf("\n");
	StackDestory(&ps);
	return 0;
}