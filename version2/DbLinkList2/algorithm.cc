#include"dlklist.h"

//链表逆转
void reverse(DLinkNode *L)
{
	DLinkNode *p = L->next, *q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		if (L->next != NULL)
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}

void sort(DLinkNode *L)
{
	DLinkNode *p1 = L->next->next, *p2, *q;
	L->next->next = NULL;
	while (p1 != NULL)
	{
		q = p1->next;
		p2 = L;
		while (p2->next != NULL && p2->next->data < p1->data)
			p2 = p2->next;
		p1->next = p2->next;
		if (p2->next != NULL)
			p2->next->prior = p1;
		p2->next = p1;
		p1->prior = p2;
		p1 = q;
	}
}
