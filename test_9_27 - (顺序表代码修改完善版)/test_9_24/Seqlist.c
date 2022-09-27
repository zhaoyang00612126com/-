#include "Seqlist.h"
#include "assert.h"

//�������Σ��β�����ʵ�εĿ������βεĸı䲻��Ӱ��ʵ�Σ�Ȼ��ͨ����ַ�Խṹ��������������޸ģ�����PS������Ի���������ĸ����ֻ��һ������
//��1��& ����� ������ȡһ������ĵ�ַ
//��2��* �������������ָ��ʱ��ʾ����ָ����ָ��Ķ���
void SeqListInit(SeqList* ps)//���Ա��ʼ������
{
	ps->a=NULL;
	ps->capacity=0;
	ps->size=0;
}

void SeqListPushBack(struct SeqList*ps,SeqListDataType x )//β��
{
	if(ps->size==ps->capacity)//���ݿ�ʼ
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;//�����0�͸�4���������0���͸�2��
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));//realloc��ԭ�еĿռ����ݣ����ԭ���Ŀռ��ǿգ����ܺ�mealloc��ͬ
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
//������һ�����⣬���ֻ��������������ɾ��3������ʱ�򣬱�����û��ʶ�������û���������Բ���ֱ��ps->size--,������Ҫ�����µķ���
void SeqListPopBack(SeqList* ps)//�����Ա����ɾ��Ԫ��
{
	if(ps->size>0)
	{
		ps->a[ps->size-1]=0;
		ps->size=ps->size-1;
	}
	/*assert(pd->size >0);���ԣ�������������ź�������Ϊ����û�£�����������Ϊ��
	ps->size--;*/
}

void SeqListPushFront(struct SeqList*ps,SeqListDataType x )//ͷ�壬Ҫ�������ݵ����⣬���ݵ�Ҫ�����һ����ʼ����Ųsize+1
{
	//int end=ps->size-1;//�±������һ��������һ��λ��
	//if(ps->size==ps->capacity)
	//{
	//	int newcapacity=ps->capacity==0?4:ps->capacity*2;
	//	SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));
	//	if(tmp==NULL)
	//	{
	//		printf("realloc fail\n");
	//		exit(-1);//ֱ����ֹ����
	//	}
	//	ps->a=tmp;
	//	ps->capacity=newcapacity;
		/*}*/
	 SeqListInsert(ps,0, x);//�Ľ�  �������±���뺯��
	
	//Ų������
	/*while(end>=0)
	{
		ps->a[end+1]=ps->a[end];
		--end;
	}
	ps->a[0]=x;
	ps->size++;*/
	}


void SeqListPopFront(SeqList* ps)//ͷɾ
{
	int begin=1;
	assert(ps->size>0);
	
	while(begin<ps->size)
	{
		ps->a[begin-1]=ps->a[begin];
		++begin;
	}

}


int SeqListFind(SeqList* ps,SeqListDataType x)//�ҵ������±꣬û�ҵ�����-1
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


void SeqListInsert(SeqList* ps,int pos,SeqListDataType x)//��pos �±�λ�ò���
{
	int end=0;

	/*if(pos>ps->size || pos<0)
	{
		printf("pos invalid\n");
		return;
	}*/
	assert(pos>=0 && pos<=ps->size);
	if(ps->size==ps->capacity)//���ݿ�ʼ
	{
		int newcapacity=ps->capacity==0?4:ps->capacity*2;//�����0�͸�4���������0���͸�2��
		SeqListDataType*tmp=(SeqListDataType*)realloc(ps->a,newcapacity*sizeof(SeqListDataType));//realloc��ԭ�еĿռ����ݣ����ԭ���Ŀռ��ǿգ����ܺ�mealloc��ͬ
		if(tmp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//ֱ����ֹ����
		}
		ps->a=tmp;
		ps->capacity=newcapacity;
	}//���ݽ���
		
		 end=ps->size-1;
	//Ų������
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
