#ifndef SEQLIST
#define SEQLIST
#include<cstdio>
#include<cstdlib>
#define MAXSIZE 60

typedef struct
{
	int data [MAXSIZE];
	int length;
}SqList;

//基本运算
void create_list(SqList * &, int [], int);
void init_list(SqList * &);
void destroy_list(SqList *);
void print_list(SqList *L);
int list_length(SqList *);
bool list_empty(SqList *);
bool list_insert(SqList *, int, int);
bool list_delete(SqList *, int, int &);

//Algorithm
void swap(int &, int &);
//删除特定值的元素
void delnode1(SqList *, int);
void delnode2(SqList *, int);
void delnode3(SqList *, int);

//大小划分
void partition1(SqList *);
void partition2(SqList *);

#endif
