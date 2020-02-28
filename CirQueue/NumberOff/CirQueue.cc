#include"CirQueue.h"

void InitQueue(CirQueue * &queue_p)
{
	queue_p = (CirQueue *)malloc(sizeof(CirQueue));
	queue_p->front = queue_p->rear = 0;
}

void DestroyQueue(CirQueue * &queue_p)
{
	free(queue_p);
}

bool QueueEmpty(CirQueue *queue_p)
{
	return (queue_p->front == queue_p->rear);
}

bool IntoQueue(CirQueue * &queue_p , ElemType elem)
{
	if((queue_p->rear + 1) % MaxSize == queue_p->front)
		return false;
	queue_p->rear++;
	queue_p->data[queue_p->rear] = elem;
	return true;
}

bool OutofQueue(CirQueue * &queue_p , ElemType &elem)
{
	if(queue_p->front == queue_p->rear)
		return false;
	queue_p->front++;
	elem = queue_p->data[queue_p->front];
	return true;
}

void NumberOffOut(int num_arr[] , int n)
{
	int index , out_elem;
	CirQueue *queue_p;
	InitQueue(queue_p);
	for(index=0; index<n; index++)
		IntoQueue(queue_p , num_arr[index]);
	while(!QueueEmpty(queue_p))
	{
		OutofQueue(queue_p , out_elem);
		printf("\t%d",out_elem);
		if(!QueueEmpty(queue_p))
		{
			OutofQueue(queue_p , out_elem);
			IntoQueue(queue_p , out_elem);
		}
	}
	printf("\n");
	DestroyQueue(queue_p);
}