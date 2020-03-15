#include"lklist.h"

void create_listF(LinkNode * &L, ElemType a[], int n)
{
	int i;
	LinkNode *s;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	for(i=0; i<n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void create_listR(LinkNode * &L, ElemType a[], int n)
{
	int i;
	LinkNode *s, *r;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	r = L;
	for(i=0; i<n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void init_list(LinkNode * &L)
{
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void destroy_list(LinkNode *L)
{
	LinkNode *pre = L, *p = L->next;
	while(p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void print_list(LinkNode *L)
{
	LinkNode *p = L->next;
	printf("linklist:\n");
	while(p != NULL)
	{
		printf("%4d",p->data);
		p = p->next;
	}
	printf("\n");
}

int list_length(LinkNode *L)
{
	int k = 0;
	LinkNode *p = L->next;
	while(p != NULL)
	{
		k++;
		p = p->next;
	}
	return k;
}

bool list_empty(LinkNode *L)
{
	return (L->next == NULL);
}

bool list_insert(LinkNode *L, int i, ElemType e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if(i < 1)
		return false;
	while(j<i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if(p == NULL)
		return false;
	s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool list_delete(LinkNode *L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L, *q;
	if(i < 1)
		return false;
	while(j<i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if(p == NULL)
		return false;
	q = p->next;
	if(q == NULL)
		return false;
	p->next = q->next;
	e = q->data;
	free(q);
	return true;
}
