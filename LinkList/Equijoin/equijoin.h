#ifndef EQUIJOIN
#define EQUIJOIN

#include<cstdio>
#include<cstdlib>
#define MAXCOL 10

typedef int ElemType;

typedef struct node
{
	ElemType data[MAXCOL];
	struct node *next;
}RowNode;

typedef struct node
{
	int ROW,COL;
	RowNode *next;
}HeadNode;

#endif
