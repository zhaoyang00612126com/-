#include<stdio.h>
//假设排序都用升序，降序反过来
void InsertSort(int* a, int n)
{
	
	for (int i = 0;i <n-1;i++)//插到最后一个是把下标为N-2的数插进去，所以最后一个数的下标是N-1，所以i<N-1
	{
		//假设[0,end]是有序的，把end+1位置的值插入进去，让[0,end+1]也有序
		int end=i;//这里end表示下标 可能第一个数就是最后一个 可能第二个数就是最后一个  
		int tmp = a[end + 1];//把后面一个值保存起来
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
void ShellSort(int* a, int n)//把间隔为gap的多组数据同时排
{
	int gap=n;//gap取多少没有固定的规定，这里只是一种方法，
	while (gap > 1)
	{
		gap = gap / 2;//这里除2，除到最后一定是1，可以做一次直接插值排序

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
void Swap(int* p1, int* p2)//交换函数
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
void AdjustDown(int* a, int n,int root)//向下调整算法
{
	int parent = root;
	int child = parent * 2 + 1;//默认指向左孩子，在这里不去选哪个大哪个小
	//1、选出左右孩子中大的那个
	while (child < n)
	{
		if (child+1<n &&a[child] < a[child + 1])//右孩子小于左孩子//有可能只有左孩子没有右孩子所以要加child+1<n这个条件
		{
			child = child + 1;//如果右孩子小于左孩子，就选右孩子，挑小的去换父节点
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


void HeapSort(int* a, int n)//堆排序
{
	//建堆
	for (int i=(n-1-1)/2;i>=0;--i)
	{
		
		AdjustDown(a,n,i);
	}
	
	//排升序要建大堆
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
		int mini = begin;//最小的数的下标
		int maxi = begin;//最大的数的下标

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
		//如果begin和maxi重合需要修改maxi的位置
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
	BubbleSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)数组大小
	PrintArry(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	SelectSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)数组大小
	PrintArry(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = {3,5,2,7,8,6,1,9,4,0};
	HeapSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)数组大小
	PrintArry(a, sizeof(a) / sizeof(int));
}
void TestInsertSort()
{
	int a[] = {9,6,5,4,2,3,1};
	InsertSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)数组大小
	PrintArry(a, sizeof(a) / sizeof(int));

}
void TestShellSort()
{
	int a[] = { 9,6,5,4,2,3,1 };
	ShellSort(a, sizeof(a) / sizeof(int));//sizeof(a)/sizeof(int)数组大小
	PrintArry(a, sizeof(a) / sizeof(int));

}

int main()
{
	//TestInsertSort();
	TestBubbleSort();
	return 0;
}