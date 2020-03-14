#ifndef LNKLIST
#define LNKLIST
#include<cstdio>
#include<cstdlib>
#include<iostream>

typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}LinkNode;

void CreateListH(LinkNode * &, ElemType [], int);
void CreateListR(LinkNode * &, ElemType [], int);
void InitList(LinkNode * &);
void DestroyList(LinkNode * &);
bool ListEmpty(LinkNode *);
int Listlength(LinkNode *);
void DispList(LinkNode *);
bool GetElemType(LinkNode *, int, ElemType &);
int LocateElemType(LinkNode *, ElemType);
bool ListInsert(LinkNode * &, int, ElemType);
bool ListDelete(LinkNode * &, int, ElemType &);

//Algorithm
void split(LinkNode *, LinkNode * &, LinkNode * &);
void delmaxnode(LinkNode * &);
void sort(LinkNode * &);

#endif
