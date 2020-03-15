#include"sqlist.h"

//交换函数
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//重建法
void delnode1(SqList *L, int x)
{
	int i, j;
	for(i=0, j=-1; i<L->length; i++)
		if (L->data[i] != x)
			L->data[++j] = L->data[i];
	L->length = j+1;
}

//移动法
void delnode2(SqList *L, int x)
{
	int i, k;
	for(i=0, k=0; i<L->length; i++)
		if(L->data[i] == x)
			k++;
		else
			L->data[i-k] = L->data[i];
	L->length -= k;
}

//区间划分法
void delnode3(SqList *L, int x)
{
	int i, j;
	for(i=0, j=-1; i<L->length; i++)
		if(L->data[i] != x)
		{
			j++;
			if(j != i)
				swap(L->data[i], L->data[j]);
		}
	L->length = j+1;
}

//划分算法1
void partition1(SqList *L)
{
	int i=0, j=L->length-1;
	int pivot = L->data[0];
	while(i<j)
	{
		while(i<j && L->data[j] >= pivot)
			j--;
		while(i<j && L->data[i] <= pivot)
			i++;
		if(i<j)
			swap(L->data[i], L->data[j]);
	}
	swap(L->data[0], L->data[i]);
}

//划分算法2
void partition2(SqList *L)
{
	int i=0, j=L->length-1;
	int pivot = L->data[0];
	while(i<j)
	{
		while(j>i && L->data[j] >= pivot)
			j--;
		L->data[i] = L->data[j];
		while(i<j && L->data[i] <= pivot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = pivot;
}


