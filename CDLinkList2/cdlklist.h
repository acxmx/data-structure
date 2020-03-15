#ifndef CDLKLIST
#define CDLKLIST

#include<cstdio>
#include<cstdlib>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *prior;
	struct node *next;
}CDLinkNode;

//basic operation
void create_listF(CDLinkNode * &, ElemType *, int);
void create_listR(CDLinkNode * &, ElemType *, int);
void init_list(CDLinkNode * &);
void destroy_list(CDLinkNode *);
void print_list(CDLinkNode *);
int list_length(CDLinkNode *);
bool list_empty(CDLinkNode *);
bool list_insert(CDLinkNode *, int, ElemType);
bool list_delete(CDLinkNode *, int, ElemType &);

//algorithm
int count(CDLinkNode *);
bool delnode(CDLinkNode *, ElemType);
bool symm(CDLinkNode *);

#endif
