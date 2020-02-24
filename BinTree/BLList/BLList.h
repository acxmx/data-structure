#ifndef BLLIST
#define BLLIST
#include<cdtsio>
#include<cstdlib>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;


#endif
