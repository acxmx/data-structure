#include"clqueue.h"

void create_queue(ClQueue * &qu, ElemType *a, int n)
{
	int i;
	init_queue(qu);
	for (i=0; i<n; i++)
		en_queue(qu, a[i]);
}

void init_queue(ClQueue * &qu)
{
	qu = (ClQueue *)malloc(sizeof(ClQueue));
	qu->front = qu->rear = -1;
}

void destroy_queue(ClQueue *qu)
{
	free(qu);
}

void print_queue(ClQueue *qu)
{
	int i = qu->front + 1;
	printf("queue:\n");
	while (i <= qu->rear)
	{
		printf("%3d", qu->data[i]);
		i++;
	}
	printf("\n");
}

int queue_length(ClQueue *qu)
{
	return ((qu->rear - qu->front + MaxSize) % MaxSize);
}

bool en_queue(ClQueue *qu, ElemType e)
{
	if ((qu->rear+1) % MaxSize == qu->front)
		return false;
	qu->rear = (qu->rear + 1) % MaxSize;
	qu->data[qu->rear] = e;
	return true;
}

bool de_queue(ClQueue *qu, ElemType &e)
{
	if (qu->front == qu->rear)
		return false;
	qu->front = (qu->front + 1) % MaxSize;
	e = qu->data[qu->front];
	return true;
}
