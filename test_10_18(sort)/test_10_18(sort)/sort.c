#include<stdio.h>
//�������������򣬽��򷴹���
void InsertSort(int* a, int n)
{
	
	for (int i = 0;i <n-1;i++)//�嵽���һ���ǰ��±�ΪN-2�������ȥ���������һ�������±���N-1������i<N-1
	{
		//����[0,end]������ģ���end+1λ�õ�ֵ�����ȥ����[0,end+1]Ҳ����
		int end=i;//����end��ʾ�±� ���ܵ�һ�����������һ�� ���ܵڶ������������һ��  
		int tmp = a[end + 1];//�Ѻ���һ��ֵ��������
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}	
}
void ShellSort(int* a, int n)//�Ѽ��Ϊgap�Ķ�������ͬʱ��
{
	int gap=n;//gapȡ����û�й̶��Ĺ涨������ֻ��һ�ַ�����
	while (gap > 1)
	{
		gap = gap / 2;//�����2���������һ����1��������һ��ֱ�Ӳ�ֵ����

		for (int i = 0;i < n - gap;++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int* p1, int* p2)//��������
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void PrintArry(int* a, int n)
{
	for (int i = 0;i < n;++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void AdjustDown(int* a, int n,int root)//���µ����㷨
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��ָ�����ӣ������ﲻȥѡ�ĸ����ĸ�С
	//1��ѡ�����Һ����д���Ǹ�
	while (child < n)
	{
		if (child+1<n &&a[child] < a[child + 1])//�Һ���С������//�п���ֻ������û���Һ�������Ҫ��child+1<n�������
		{
			child = child + 1;//����Һ���С�����ӣ���ѡ�Һ��ӣ���С��ȥ�����ڵ�
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)//������
{
	//����
	for (int i=(n-1-1)/2;i>=0;--i)
	{
		
		AdjustDown(a,n,i);
	}
	
	//������Ҫ�����
	int end = n - 1;
	while(end>0)
	{
		Swap(&a[0],&a[end]);
		AdjustDown(a, end, 0);
		--end;
	}


}
void SelectSort(int*a,int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin<end)//3287945     1  
	{
		int mini = begin;//��С�������±�
		int maxi = begin;//���������±�

		for (int i = begin;i <= end;++i)
		{
			if (a[i]<a[mini])
			{
				mini = i;			
			}
			if (a[i]> a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//���begin��maxi�غ���Ҫ�޸�maxi��λ��
		if (begin==maxi)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}


}

void BubbleSort(int* a, int n)
{
	
	for (int j=0;j<n;++j)
	{
		int exchange = 0;
		for (int i=1;i<n-j;i++)
		{
			if (a[i-1]>a[i])
			{
				Swap(&a[i - 1],&a[i]);
				exchange = 1;
			}
		}
		if (exchange==0)
		{
		
			break;
		
		
		}
	
	}
	
}




void TestBubbleSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	BubbleSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)�����С
	PrintArry(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	SelectSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)�����С
	PrintArry(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = {3,5,2,7,8,6,1,9,4,0};
	HeapSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)�����С
	PrintArry(a, sizeof(a) / sizeof(int));
}
void TestInsertSort()
{
	int a[] = {9,6,5,4,2,3,1};
	InsertSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)�����С
	PrintArry(a, sizeof(a) / sizeof(int));

}
void TestShellSort()
{
	int a[] = { 9,6,5,4,2,3,1 };
	ShellSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)�����С
	PrintArry(a, sizeof(a) / sizeof(int));

}

int main()
{
	//TestInsertSort();
	TestBubbleSort();
	return 0;
}