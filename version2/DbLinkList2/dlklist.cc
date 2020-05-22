#include"dlklist.h"

void create_listF(DLinkNode * &L, ElemType *a, int n)
{
	int i;
	DLinkNode *s;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	L->next = NULL;
	for (i=0; i<n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if(L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void create_listR(DLinkNode * &L, ElemType *a, int n)
{
	int i;
	DLinkNode *s, *r;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	r = L;
	for (i=0; i<n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

void init_list(DLinkNode * &L)
{
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
}

void destroy_list(DLinkNode *L)
{
	DLinkNode *pre = L, *p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void print_list(DLinkNode *L)
{
	DLinkNode *p = L->next;
	printf("double link list:\n");
	while (p != NULL)
	{
		printf("%3d",p->data);
		p = p->next; 
	}
	printf("\n");
}

int list_length(DLinkNode *L)
{
	int k=0;
	DLinkNode *p = L->next;
	while (p != NULL)
	{
		k++;
		p = p->next;
	}
	return k;
}

bool list_empty(DLinkNode *L)
{
	return (L->next == NULL);
}

bool list_insert(DLinkNode *L, int i, ElemType e)
{
	int j = 0;
	DLinkNode *p = L, *s, *q;
	if (i < 1)
		return false;
	while (j<i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = (DLinkNode *)malloc(sizeof(DLinkNode));
	s->data = e;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}

bool list_delete(DLinkNode *L, int i, ElemType &e)
{
	int j = 0;
	DLinkNode *p = L, *q;
	if (i < 1)
		return false;
	while (j<i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	q->next->prior = p;
	e = q->data;
	free(q);
	return true;
}
