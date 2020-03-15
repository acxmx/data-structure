#ifndef DLKLIST
#define DLKLIST

#include<cstdio>
#include<cstdlib>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *prior;
	struct node *next;
}DLinkNode;

//basic operation
void create_listF(DLinkNode * &, ElemType *, int);
void create_listR(DLinkNode * &, ElemType *, int);
void init_list(DLinkNode * &);
void destroy_list(DLinkNode *);
void print_list(DLinkNode *);
int list_length(DLinkNode *);
bool list_empty(DLinkNode *);
bool list_insert(DLinkNode *, int, ElemType);
bool list_delete(DLinkNode *, int, ElemType &);

//algorithm
void reverse(DLinkNode *);
void sort(DLinkNode *);

#endif
