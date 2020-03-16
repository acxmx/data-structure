#ifndef LKQUEUE
#define LKQUEUE

#include<cstdio>
#include<cstdlib>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}QuNode;

typedef struct
{
	QuNode *front;
	QuNode *rear;
}LkQueue;

//basic operation
void create_queue(LkQueue * &, ElemType *, int);
void init_queue(LkQueue * &);
void destroy_queue(LkQueue *);
void print_queue(LkQueue *);
int queue_length(LkQueue *);
bool queue_empty(LkQueue *);
void en_queue(LkQueue *, ElemType);
bool de_queue(LkQueue *, ElemType &);

#endif
