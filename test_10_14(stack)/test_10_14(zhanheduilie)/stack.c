#include"stack.h"

void StackInit(Stack* ps)
{
	STDataType*tmp = (STDataType*)malloc(sizeof(STDataType)* 4);

	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else 
	{
		ps->a = tmp;
		ps->capacity = 4;
		ps->top = 0;//top这里可以给0也可以给-1，给0的话，top始终指向新插入栈顶的数据的下一个
		//给-1的话，他就能插入哪个就给哪个。
	}
	
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackPush(Stack* ps, STDataType x)//入栈，栈只需要在栈顶进行操作，栈顶插入删除数据,
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType*tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = ps->capacity*2 ;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
	//ps->top++;
	//ps->a[ps->top] = x;
	//如果初始化那里top设置为-1，则用下面这种方式
}
void StackPop(Stack* ps)//出栈
{
	assert(ps);//栈空了，再调用POP，直接报错
	assert(ps->top > 0);
	ps->top--;
	

}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	// 栈空了，调用Top，直接中止程序报错
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}



int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;


}//空就返回1，非空就返回0