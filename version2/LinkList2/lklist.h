#ifndef LKLIST
#define LKLIST

#include<cstdio>
#include<cstdlib>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode;

//basic operation
void create_listF(LinkNode * &, ElemType [], int);
void create_listR(LinkNode * &, ElemType [], int);
void init_list(LinkNode * &);
void destroy_list(LinkNode *);
void print_list(LinkNode *);
int list_length(LinkNode *);
bool list_empty(LinkNode *);
bool list_insert(LinkNode *, int, ElemType);
bool list_delete(LinkNode *, int, ElemType *);

//algorithm
void delmaxnode(LinkNode *);
void sort(LinkNode *);

#endif
