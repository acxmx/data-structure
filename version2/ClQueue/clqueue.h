#ifndef CLQUEUE
#define CLQUEUE

#include<cstdio>
#include<cstdlib>
#define MaxSize 50

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}ClQueue;

//basic operation
void create_queue(ClQueue * &, ElemType *, int);
void init_queue(ClQueue * &);
void destroy_queue(ClQueue *);
void print_queue(ClQueue *);
int queue_length(ClQueue *);
bool en_queue(ClQueue *, ElemType);
bool de_queue(ClQueue *, ElemType &);

//algorithm
void numberof(char *);

#endif
