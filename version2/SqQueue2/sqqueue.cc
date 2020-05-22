#include"sqqueue.h"

void create_queue(SqQueue * &qu, ElemType *a, int n)
{
	int i;
	init_queue(qu);
	for (i=0; i<n; i++)
		qu->data[++qu->rear] = a[i];
}

void init_queue(SqQueue * &qu)
{
	qu = (SqQueue *)malloc(sizeof(SqQueue));
	qu->front = qu->rear = -1;
}

void destroy_queue(SqQueue *qu)
{
	free(qu);
}

void print_queue(SqQueue *qu)
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

int queue_length(SqQueue *qu)
{
	return (qu->rear - qu->front);
}

bool en_queue(SqQueue *qu, ElemType e)
{
	if (qu->rear == MaxSize-1)
		return false;
	qu->data[++qu->rear] = e;
	return true;
}

bool de_queue(SqQueue *qu, ElemType &e)
{
	if (qu->front == qu->rear)
		return false;
	e = qu->data[++qu->front];
	return true;
}
