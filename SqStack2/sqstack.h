#ifndef SQSTACK
#define SQSTACK

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

/* using the function return value replaces the function of C++ reference to
 * create the stack
*/
SqStack *create_stack(ElemType *, int);
SqStack *init_stack();
void destroy_stack(SqStack *);
void print_stack(SqStack *);
int stack_length(SqStack *);
bool stack_empty(SqStack *);
bool push(SqStack *, ElemType);
bool pop(SqStack *);

//algorithm
bool symmetry(char *);

#endif
