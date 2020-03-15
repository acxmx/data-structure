#ifndef LKSTACK
#define LKSTACK

#include<cstdio>
#include<cstdlib>

typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}StackNode;

//basic operation
void create_stack(StackNode * &, ElemType *, int);
void init_stack(StackNode * &);
void destroy_stack(StackNode *);
void print_stack(StackNode *);
bool stack_empty(StackNode *);
void push(StackNode *, ElemType);
bool pop(StackNode *, ElemType &);

//algorithm
bool is_match(char *);

#endif
