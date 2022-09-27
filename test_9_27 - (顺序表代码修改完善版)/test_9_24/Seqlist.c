#include "Seqlist.h"
#include "assert.h"

//函数传参，形参是是实参的拷贝，形参的改变不会影响实参，然后通过地址对结构体里面的内容做修改，所以PS这个可以换成任意字母，这只是一个符号
//（1）& 运算符 ：用于取一个对象的地址
//（2）* 运算符：作用于指针时表示访问指针所指向的对象
void SeqListInit(SeqList* ps)//线性表初始化函数
{
	ps->a=NULL;
	ps->capacity=0;
	ps->size=0;
}

void SeqListPushBack(struct SeqList*ps,SeqListDataType x )//尾插
{
	if(ps->size==ps->capacity)//扩容开始
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;//如果是0就给4，如果不是0，就给2倍
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));//realloc对原有的空间扩容，如果原来的空间是空，则功能和mealloc相同
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
//这里有一个问题，如果只插入两个数，但删除3个数的时候，编译器没法识别出来，没法报错，所以不能直接ps->size--,我们需要用如下的方法
void SeqListPopBack(SeqList* ps)//从线性表后面删除元素
{
	if(ps->size>0)
	{
		ps->a[ps->size-1]=0;
		ps->size=ps->size-1;
	}
	/*assert(pd->size >0);断言，断言是如果括号后面条件为真则没事，否则则条件为假
	ps->size--;*/
}

void SeqListPushFront(struct SeqList*ps,SeqListDataType x )//头插，要考虑扩容的问题，数据的要从最后一个开始往后挪size+1
{
	//int end=ps->size-1;//下标是最后一个数的下一个位置
	//if(ps->size==ps->capacity)
	//{
	//	int newcapacity=ps->capacity==0?4:ps->capacity*2;
	//	SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
	//	if(tmp==NULL)
	//	{
	//		printf("realloc fail\n");
	//		exit(-1);//直接终止程序
	//	}
	//	ps->a=tmp;
	//	ps->capacity=newcapacity;
		/*}*/
	 SeqListInsert(ps,0, x);//改进  服用了下标插入函数
	
	//挪动数据
	/*while(end>=0)
	{
		ps->a[end+1]=ps->a[end];
		--end;
	}
	ps->a[0]=x;
	ps->size++;*/
	}


void SeqListPopFront(SeqList* ps)//头删
{
	int begin=1;
	assert(ps->size>0);
	
	while(begin<ps->size)
	{
		ps->a[begin-1]=ps->a[begin];
		++begin;
	}

}


int SeqListFind(SeqList* ps,SeqListDataType x)//找到返回下标，没找到返回-1
{
	int i=0;
	for(i=0;i<=ps->size;i++)
	{
		if(ps->a[i]==x)
		{
			return i;
		}
	}
	return -1;

}


void SeqListInsert(SeqList* ps,int pos,SeqListDataType x)//在pos 下标位置插入
{
	int end=0;

	/*if(pos>ps->size || pos<0)
	{
		printf("pos invalid\n");
		return;
	}*/
	assert(pos>=0 && pos<=ps->size);
	if(ps->size==ps->capacity)//扩容开始
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;//如果是0就给4，如果不是0，就给2倍
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));//realloc对原有的空间扩容，如果原来的空间是空，则功能和mealloc相同
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//直接终止程序
		}
		ps->a=tmp;
		ps->capacity=newcapacity;
	}//扩容结束
		
		 end=ps->size-1;
	//挪动数据
		while(end>=pos)
		{
			ps->a[end+1]=ps->a[end];
			--end;
		}
		ps->a[pos]=x;
		ps->size ++;

}
void SeqListDelete(SeqList* ps,int pos)
{
	
	int begin=0;
	assert(pos>=0 && pos<=ps->size);

	 begin=pos+1;
	while(begin<ps->size)
	{
		ps->a[begin-1]=ps->a[begin];
		++begin;
	}
	ps->size++;

}
