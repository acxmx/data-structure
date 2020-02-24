#ifndef CIRQUEUE
#define CIRQUEUE

#include<cstdio>
#include<cstdlib>
#define MaxSize 20

typedef int ElemType;
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

//解决报数出列问题函数
void NumberOffOut(int [] , int);

#endif
