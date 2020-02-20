#include"SqQueue.h"


void InitQueue(SqQueue * &queue_p)
{
	queue_p = (SqQueue *)malloc(sizeof(SqQueue));
	queue_p->front = queue_p->rear = -1;
}

void DestroyQueue(SqQueue * &queue_p)
{
	free(queue_p);
}

bool QueueEmpty(SqQueue *queue_p)
{
	return (queue_p->front == queue_p->rear);
}

bool IntoQueue(SqQueue * &queue_p, ElemType elem)
{
	if(queue_p->rear == MaxSize - 1)
		return false;
	queue_p->rear++;
	queue_p->data[queue_p->rear] = elem;
	return true;
}

bool OutofQueue(SqQueue * &queue_p, ElemType &elem)
{
	if(queue_p->front == queue_p->rear)
		return false;
	queue_p->front++;
	elem = queue_p->data[queue_p->front];
	return true;
}
