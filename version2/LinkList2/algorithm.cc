#include"lklist.h"

void delmaxnode(LinkNode *L)
{
	LinkNode *pre = L, *p = L->next,
	*maxpre = pre, *maxp = p;
	while(p != NULL)
	{
		if(maxp->data < p->data)
		{
			maxpre = pre;
			maxp = p;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	free(maxp);
}

void sort(LinkNode *L)
{
	LinkNode *p1, *p2, *q;
	p1 = L->next->next;
	L->next->next = NULL;
	while(p1 != NULL)
	{
		q = p1->next;
		p2 = L;
		while(p2->next != NULL && p2->next->data < p1->data)
			p2 = p2->next;
		p1->next = p2->next;
		p2->next = p1;
		p1 = q;
	}
}
