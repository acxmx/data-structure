#ifndef HFMAN
#define HFMAN

#include<cstdio>
#include<cstdlib>
#define LEAF 8
typedef char ElemType;

typedef struct
{
	ElemType data;
	double weight;
	int parent;
	int lchild, rchild;
}HTNode;

typedef struct
{
	char code[LEAF];
	int start;
}HCNode;

void create_hftree(HTNode *, int);
void create_hfcode(HTNode *, HCNode *, int);

#endif
