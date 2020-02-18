#ifndef SEQLIST
#define SEQLIST
#include<cstdio>
#include<cstdlib>
#define MAXSIZE 60

typedef int ElemType;
typedef struct
{
	ElemType data [MAXSIZE];
	int length;
}SqList;

void CreateList(SqList * &, ElemType [], int);
void InitList(SqList * &);
void DestroyList(SqList * &);
bool ListEmpty(SqList *);
int ListLength(SqList *);
void DispList(SqList *L);
bool GetElem(SqList *L, int, ElemType &);
bool LocateElem(SqList *L, int, ElemType);
bool ListInsert(SqList * &, int, ElemType);
bool ListDelete(SqList * &, int, ElemType &);

//Algorithm
//删除特定值的元素
void delnode1(SqList * &, ElemType);
void delnode2(SqList * &, ElemType);

//大小划分
void swap(ElemType &, ElemType &);
void partition1(SqList * &);
void partition2(SqList * &);

//奇偶排序
void move1(SqList * &);
void move2(SqList * &);

#endif
