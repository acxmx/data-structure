#ifndef LINKQUEUE
#define LINKQUEUE

#include<cstdio>
#include<cstdlib>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}QueueNode;

typedef struct node
{
	DataNode *front , *rear;
}LinkQueue;

void InitQueue(LinkQueue * &);
void DestroyQueue(LinkQueue * &);
bool QueueEmpty(LinkQueue *);
bool IntoQueue(LinkQueue * & , ElemType);
bool OutofQueue(LinkQueue * &, ElemType &);

#endif
