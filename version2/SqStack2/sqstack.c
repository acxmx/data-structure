#include"sqstack.h"

SqStack *create_stack(ElemType *a, int n)
{
	int i = 0;
	SqStack *st = (SqStack *)malloc(sizeof(SqStack));
	st->top = -1;
	while (i < n)
		st->data[++st->top] = a[i++];
	return st;
}

SqStack *init_stack()
{
	SqStack *st = (SqStack *)malloc(sizeof(SqStack));
	st->top = -1;
	return st;
}

void destroy_stack(SqStack *st)
{
	free(st);
}

void print_stack(SqStack *st)
{
	int i = st->top;
	printf("stack:\n");
	while (i > -1)
		printf("%3d", st->data[i--]);
	printf("\n");
}

int stack_length(SqStack *st)
{
	return (st->top + 1);
}

bool stack_empty(SqStack *st)
{
	return (st->top == -1);
}

bool push(SqStack *st, ElemType e)
{
	if (st->top == MaxSize-1)
		return false;
	st->data[++st->top] = e;
	return true;
}

bool pop(SqStack *st)
{
	if (st->top == -1)
		return false;
	st->top--;
	return true;
}
