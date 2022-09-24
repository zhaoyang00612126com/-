#include "Seqlist.h"
#include "assert.h"
void SeqListInit(SeqList* ps)
{
	ps->a=NULL;
	ps->capacity=0;
	ps->size=0;
}

void SeqListPushBack(struct SeqList*ps,SeqListDataType x )//β��
{
	if(ps->size==ps->capacity)//���ݿ�ʼ
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//ֱ����ֹ����
		}
		ps->a=tmp;
		ps->capacity=newcapacity;
	}//���ݽ���
	
	
	ps->a[ps->size]=x;//���ݵ�size��0��ʼ�����Դ�ʱ��size-1���������ڻ��пռ䣬ֱ�ӽ�x�ŵ��������棬�����λ������ps->size���
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
void SeqListPopBack(SeqList* ps)//�����Ա����ɾ��Ԫ��
{
	if(ps->size>0)
	{
		ps->a[ps->size-1]=0;
		ps->size=ps->size-1;
	}
	/*assert(pd->size >0);
	ps->size--;*/
}

void SeqListPushFront(struct SeqList*ps,SeqListDataType x )//ͷ�壬Ҫ�������ݵ�����
{
	int end=ps->size-1;
	if(ps->size==ps->capacity)
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//ֱ����ֹ����
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
void SeqListPopFront(SeqList* ps)//ͷɾ
{
	assert(ps->size>0);
	
	while(begin<ps->size)
	{
		ps->a[begin-1]=ps->a[begin];
		++begin;
	}

}
