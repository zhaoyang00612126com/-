#include "Seqlist.h"
#include "assert.h"
void SeqListInit(SeqList* ps)
{
	ps->a=NULL;
	ps->capacity=0;
	ps->size=0;
}

void SeqListPushBack(struct SeqList*ps,SeqListDataType x )//尾插
{
	if(ps->size==ps->capacity)//扩容开始
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//直接终止程序
		}
		ps->a=tmp;
		ps->capacity=newcapacity;
	}//扩容结束
	
	
	ps->a[ps->size]=x;//数据的size从0开始，所以此时是size-1，正好现在还有空间，直接将x放到数组里面，数组的位置是在ps->size这里。
	ps->size=ps->size+1;

}

void SeqListPrint(SeqList* ps)
{
	int i=0;
	for(i=0;i<ps->size;i=i+1)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");

}

void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a=NULL;
	ps->capacity=0;
	ps->size=0;
}
void SeqListPopBack(SeqList* ps)//从线性表后面删除元素
{
	if(ps->size>0)
	{
		ps->a[ps->size-1]=0;
		ps->size=ps->size-1;
	}
	/*assert(pd->size >0);
	ps->size--;*/
}

void SeqListPushFront(struct SeqList*ps,SeqListDataType x )//头插，要考虑扩容的问题
{
	int end=ps->size-1;
	if(ps->size==ps->capacity)
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//直接终止程序
		}
		ps->a=tmp;
		ps->capacity=newcapacity;
	}


	while(end>=0)
	{
		ps->a[end+1]=ps->a[end];
		--end;
	}
	ps->a[0]=x;
	ps->size++;
	}

int begin=1;
void SeqListPopFront(SeqList* ps)//头删
{
	assert(ps->size>0);
	
	while(begin<ps->size)
	{
		ps->a[begin-1]=ps->a[begin];
		++begin;
	}

}
