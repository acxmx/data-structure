#include"sqlist.h"

void create_list(SqList * &L, int a[], int n)
{
	int i;
	L = (SqList *)malloc(sizeof(SqList));
	for(i=0; i<n; ++i)
		L->data[i] = a[i];
	L->length = i;
}

void init_list(SqList * &L)
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

void destroy_list(SqList * L)
{
	free(L);
}

bool list_empty(SqList *L)
{
	return (L->length == 0);
}

int list_length(SqList *L)
{
	return L->length;
}

void print_list(SqList *L)
{
	int i;
	printf("顺序表内容如下:\n");
	for(i=0; i<L->length; i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}

bool list_insert(SqList * &L, int i, int e)
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

bool list_delete(SqList * &L, int i, int &e)
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
