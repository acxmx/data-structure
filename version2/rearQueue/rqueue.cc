#include"rqueue.h"

void create_queue(QuNode * &rear, ElemType *a, int n)
{
	int i;
	init_queue(rear);
	for (i=0; i<n; i++)
		en_queue(rear, a[i]);
}

void init_queue(QuNode * &rear)
{
	rear = NULL;
}

void destroy_queue(QuNode * rear)
{
	QuNode *pre, *p;
	if (rear != NULL)
	{
		pre = rear->next;
		rear->next = NULL;
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
}

void print_queue(QuNode *rear)
{
	QuNode *p;
	if (rear != NULL)
	{
		printf("queue:\n");
		p = rear->next;
		while (p != rear)
		{
			printf("%3d", p->data);
			p = p->next;
		}
		printf("%3d\n", rear->data);
	}
	
}

int queue_length(QuNode *rear)
{
	int k=0;
	QuNode *p;
	if (rear != NULL)
	{
		p = rear->next;
		while (p != rear)
		{
			k++;
			p = p->next;
		}
		k++;
	}
	return k;
}

bool queue_empty(QuNode *rear)
{
	return (rear == NULL);
}

void en_queue(QuNode * &rear, ElemType e)
{
	QuNode *s;
	s = (QuNode *)malloc(sizeof(QuNode));
	s->data = e;
	if (rear == NULL)
	{
		s->next = s;
		rear = s;
	}else{
		s->next = rear->next;
		rear->next = s;
		rear = s;
	}
}

bool de_queue(QuNode * &rear, ElemType &e)
{
	QuNode *p;
	if (rear == NULL)
		return false;
	else
	{
		p = rear->next;
		if (rear == p)
		{
			e = p->data;
			free(p);
			rear = NULL;
		}else{
			rear->next = p->next;
			e = p->data;
			free(p);
		}
		return true;
	}
}
