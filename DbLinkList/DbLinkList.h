#include<cstdio>
#include<cstdlib>

//declarations of circular double link list:

typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *prior;
	struct node *next;
}DLinkNode;

void CreateListH(DLinkNode * &, ElemType [], int);
void CreateListR(DLinkNode * &, ElemType [], int);
void InitList(DLinkNode * &);
void DestroyList(DLinkNode * &);
bool ListEmpty(DLinkNode *);
int ListLength(DLinkNode *);
void DispList(DLinkNode *);
bool GetElem(DLinkNode *, int, ElemType &);
int LocateElem(DLinkNode *, ElemType);
bool ListInsert(DLinkNode * &, int, ElemType);
bool ListDelete(DLinkNode * &, int, ElemType &);

//Algorithm
void reverse(DLinkNode * &);
void sort(DLinkNode * &);
int count(DLinkNode *, ElemType);
bool delnode(DLinkNode * &, ElemType);
bool Symm(DLinkNode *);
