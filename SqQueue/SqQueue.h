#ifndef SQQUEUE
#define SQQUEUE

#include<cstdio>
#include<cstdlib>
#define MaxSize 20;

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;

void InitQueue(SqQueue * &);
void DestroyQueue(SqQueue * &);
bool QueueEmpty(SqQueue *);
bool IntoQueue(SqQueue * &, ElemType);
bool OutofQueue(SqQueue * &, ElemType &);

#endif
