#include"cdlklist.h"

void create_listF(CDLinkNode * &L, ElemType *a, int n)
{
	CDLinkNode *s;
	int i;
	L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
	L->prior = L->next = L;
	for (i=0; i<n; i++)
	{
		s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void create_listR(CDLinkNode * &L, ElemType *a, int n)
{
	CDLinkNode *s, *r;
	int i;
	L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
	L->prior = L->next = L;
	r = L;
	for (i=0; i<n; i++)
	{
		s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
		s->data = a[i];
		s->next = r->next;
		r->next->prior = s;
		r->next = s;
		s->prior = r;
		r = s;
	}
}

void init_list(CDLinkNode * &L)
{
	L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
	L->prior = L->next = L;
}

void destroy_list(CDLinkNode *L)
{
	CDLinkNode *pre = L->next, *p;
	if (pre != L)
	{
		p  = pre->next;
		while (p != L)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(L);
}

void print_list(CDLinkNode *L)
{
	CDLinkNode *p = L->next;
	printf("cdlklist:\n");
	while (p != L)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}

int list_length(CDLinkNode *L)
{
	int k = 0;
	CDLinkNode *p = L->next;
	while (p != L)
	{
		k++;
		p = p->next;
	}
	return k;
}

bool list_empty(CDLinkNode *L)
{
	return (L->prior == L->next);
}

bool list_insert(CDLinkNode *L, int i, ElemType e)
{
	int j = 1;
	CDLinkNode *p = L->next, *s;
	if (i < 1)
		return false;
	while (j<i && p != L)
	{
		j++;
		p = p->next;
	}
	if (j == i)
	{
		s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
		s->data = e;
		s->prior = p->prior;
		p->prior->next = s;
		p->prior = s;
		s->next = p;
		return true;
	}
	else
		return false;
}

bool list_delete(CDLinkNode *L, int i, ElemType &e)
{
	int j = 1;
	CDLinkNode *p = L->next;
	if (i < 1)
		return false;
	while (j<i && p != L)
	{
		j++;
		p = p->next;
	}
	if (j == i && p != L)
	{
		e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return true;
	}
	else 
		return false;
}
