#ifndef SQQUEUE
#define SQQUEUE

#include<cstdio>
#include<cstdlib>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

//basic operation
void create_queue(SqQueue * &, ElemType *, int);
void init_queue(SqQueue * &);
void destroy_queue(SqQueue *);
void print_queue(SqQueue *);
int queue_length(SqQueue *);
bool queue_empty(SqQueue *);
bool en_queue(SqQueue *, ElemType);
bool de_queue(SqQueue *, ElemType &);

#endif
