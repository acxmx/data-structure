#ifndef RQUEUE
#define RQUEUE

#include<cstdio>
#include<cstdlib>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}QuNode;

//basic operation
void create_queue(QuNode * &, ElemType *, int);
void init_queue(QuNode * &);
void destroy_queue(QuNode *);
void print_queue(QuNode *);
int queue_length(QuNode *);
bool queue_empty(QuNode *);
void en_queue(QuNode * &, ElemType);
bool de_queue(QuNode * &, ElemType &);

#endif
