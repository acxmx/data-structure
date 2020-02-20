#ifndef CIRQUEUE
#define CIRQUEUE

#include<cstdio>
#include<cstdlib>
#define MaxSize 20;

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;
}CirQueue;

void InitQueue(CirQueue * &);
void DestroyQueue(CirQueue * &);
bool QueueEmpty(CirQueue *);
bool IntoQueue(CirQueue * &, ElemType);
bool OutofQueue(CirQueue * &, ElemType &);

#endif
