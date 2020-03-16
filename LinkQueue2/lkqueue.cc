#include"lkqueue.h"

void create_queue(LkQueue * &qu, ElemType *a, int n)
{
	int i;
	init_queue(qu);
	for (i=0; i<n; i++)
		en_queue(qu, a[i]);
}

void init_queue(LkQueue * &qu)
{
	qu = (LkQueue *)malloc(sizeof(LkQueue));
	qu->front = qu->rear = NULL;
}

void destroy_queue(LkQueue *qu)
{
	QuNode *pre, *p;
	pre = qu->front;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(qu);
}

void print_queue(LkQueue *qu)
{
	QuNode *p = qu->front;
	printf("queue:\n");
	while (p != NULL)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}

int queue_length(LkQueue *qu)
{
	int k=0;
	QuNode *p = qu->front;
	while (p != NULL)
	{
		k++;
		p = p->next;
	}
	return k;
}

bool queue_empty(LkQueue *qu)
{
	return (qu->front == NULL);
}

void en_queue(LkQueue *qu, ElemType e)
{
	QuNode *s;
	s = (QuNode *)malloc(sizeof(QuNode));
	s->data = e;
	if (qu->front == NULL)
	{
		qu->front = qu->rear = s;
		qu->rear->next = NULL;
	}else{
		qu->rear->next = s;
		qu->rear = s;
		qu->rear->next = NULL;
	}
	
}

bool de_queue(LkQueue *qu, ElemType &e)
{
	QuNode *p;
	if (qu->front == NULL)
		return false;
	if (qu->front == qu->rear)
	{
		p = qu->front;
		e = p->data;
		qu->front = qu->rear = NULL;
		free(p);
		return true;
		
	}else{
		p = qu->front;
		qu->front = p->next;
		e = p->data;
		free(p);
		return true;
	}
}
