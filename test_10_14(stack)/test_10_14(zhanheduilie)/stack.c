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
		ps->top = 0;//top������Ը�0Ҳ���Ը�-1����0�Ļ���topʼ��ָ���²���ջ�������ݵ���һ��
		//��-1�Ļ��������ܲ����ĸ��͸��ĸ���
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
void StackPush(Stack* ps, STDataType x)//��ջ��ջֻ��Ҫ��ջ�����в�����ջ������ɾ������,
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
	//�����ʼ������top����Ϊ-1�������������ַ�ʽ
}
void StackPop(Stack* ps)//��ջ
{
	assert(ps);//ջ���ˣ��ٵ���POP��ֱ�ӱ���
	assert(ps->top > 0);
	ps->top--;
	

}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	// ջ���ˣ�����Top��ֱ����ֹ���򱨴�
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


}//�վͷ���1���ǿվͷ���0