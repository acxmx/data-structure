//顺序栈的基本实现
#ifndef SEQSTACK
#define SEQSTACK

#include<cstdio>
#include<cstdlib>
#define MaxSize 100

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack * &);
void DestroyStack(SqStack * &);
bool StackEmpty(SqStack *);
bool Push(SqStack * &, ElemType);
bool Pop(SqStack * &, ElemType &);
bool GetTop(SqStack *, ElemType &);
bool symmetry(ElemType *);

#endif
