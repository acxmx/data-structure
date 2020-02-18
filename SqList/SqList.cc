#include"SqList.h"

void CreateList(SqList * &L, ElemType a[], int n)
{
	int i;
	L = (SqList *)malloc(sizeof(SqList));
	for(i=0; i<n; ++i)
		L->data[i] = a[i];
	L->length = i;
}

void InitList(SqList * &L)
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

void DestroyList(SqList * &L)
{
	free(L);
}

bool ListEmpty(SqList *L)
{
	return (L->length == 0);
}

int ListLength(SqList *L)
{
	return L->length;
}

void DispList(SqList *L)
{
	int i;
	printf("顺序表内容如下:\n");
	for(i=0; i<L->length; i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e)
{
	if(i<1 || i>L->length)
		return false;
	e = L->data[i-1];
	return true;
}

int LocateElem(SqList * L, ElemType e)
{
	int i;
	for(i=0; i<L->length; i++)
		if(L->data[i] == e)
			return i+1;
	return 0;
}

bool ListInsert(SqList * &L, int i, ElemType e)
{
	int j;
	if(i<1 || i>L->length+1)
		return false;
	i--;
	for(j=L->length-1; j>=i; j--)
		L->data[j+1] = L->data[j];
	L->data[i] = e;
	L->length++;
	return true;
}

bool ListDelete(SqList * &L, int i, ElemType &e)
{
	int j;
	if(i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for(j=i+1; j<=L->length-1; j++)
		L->data[j-1] = L->data[j];
	L->length--;
	return true;
}

void delnode1(SqList * &L, ElemType x)
{
	int k,i;
	for(k=0,i=0; i<L->length; i++)
		if(L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k; 
}

void delnode2(SqList * &L, ElemType x)
{
	int k, i;
	for(k=0,i=0; i<L->length; i++)
		if(L->data[i] == x)
			k++;
		else
			L->data[i-k] = L->data[i];
	L->length -= k;
}

void swap(ElemType &a, ElemType &b)
{
	ElemType tmp = a;
	a = b;
	b = tmp;
}

void partition1(SqList * &L)
{
	int i=0, j=L->length-1;
	ElemType pivot = L->data[0];
	while(i<j)
	{
		while(i<j && L->data[j] > pivot)
			j--;
		while(i<j && L->data[i] <= pivot)
			i++;
		if(i<j)
			swap(L->data[i],L->data[j]);
	}
	swap(L->data[0],L->data[i]);
}

void partition2(SqList * &L)
{
	int i=0,j=L->length-1;
	ElemType pivot = L->data[0];
	while(i<j)
	{
		while(j>i && L->data[j] > pivot)
			j--;
		L->data[i] = L->data[j];
		while(i<j && L->data[i] <= pivot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = pivot;
}

void move1(SqList * &L)
{
	int i=0, j=L->length-1;
	while(i<j)
	{
		while(i<j && L->data[j]%2 == 0)
			j--;
		while(i<j && L->data[i]%2 == 1)
			i++;
		if(i<j)
			swap(L->data[i],L->data[j]);
	}
}

void move2(SqList * &L)
{
	int i,j;
	for(i=-1,j=0; j<L->length; j++)
		if(L->data[j]%2 == 1)
		{
			i++;
			if(i!=j)
				swap(L->data[i],L->data[j]);
		}
}
