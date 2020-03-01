//顺序栈的基本实现
#ifndef SEQSTACK
#define SEQSTACK

#include"BLList.h"
#include<cstdio>
#include<cstdlib>
#define MaxSize 100

typedef BTNode* ElemType_stack;
typedef struct
{
	ElemType_stack data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack * &);
void DestroyStack(SqStack * &);
bool StackEmpty(SqStack *);
bool Push(SqStack * &, ElemType_stack);
bool Pop(SqStack * &, ElemType_stack &);
bool GetTop(SqStack *, ElemType_stack &);
bool symmetry(ElemType_stack *);

#endif
