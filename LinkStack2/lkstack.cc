#include"lkstack.h"

void create_stack(StackNode * &st, ElemType *a, int n)
{
	int i;
	StackNode *s;
	st = (StackNode *)malloc(sizeof(StackNode));
	st->next = NULL;
	for(i=0; i<n; i++)
	{
		s = (StackNode *)malloc(sizeof(StackNode));
		s->data = a[i];
		s->next = st->next;
		st->next = s;
	}
}

void init_stack(StackNode * &st)
{
	st = (StackNode *)malloc(sizeof(StackNode));
	st->next = NULL;
}

void destroy_stack(StackNode *st)
{
	StackNode *pre = st, *p = st->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void print_stack(StackNode *st)
{
	StackNode *p = st->next;
	printf("stack:\n");
	while (p != NULL)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}

bool stack_empty(StackNode *st)
{
	return (st->next == NULL);
}

void push(StackNode *st, ElemType e)
{
	StackNode *p;
	p = (StackNode *)malloc(sizeof(StackNode));
	p->data = e;
	p->next = st->next;
	st->next = p;
}

bool pop(StackNode *st, ElemType &e)
{
	StackNode *p;
	p = st->next;
	if (stack_empty(st))
		return false;
	e = p->data;
	st->next = p->next;
	free(p);
	return true;
}
