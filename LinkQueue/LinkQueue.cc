#include"LinkQueue.h"

void InitQueue(LinkQueue * &queue_p)
{
	queue_p = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue_p->front = queue_p->rear = NULL;
}

void DestroyQueue(LinkQueue * &queue_p)
{
	QueueNode *pre = queue_p->front, *p;
	if(pre)
	{
		p = pre->next;
		while(p)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(queue_p);
}

bool QueueEmpty(LinkQueue * queue_p)
{
	return (queue_p->rear == NULL);
}

bool IntoQueue(LinkQueue * &queue_p, ElemType elem)
{
	QueueNode *new_node_p;
	new_node_p = (QueueNode *)malloc(sizeof(QueueNode));
	new_node_p->data = elem;
	new_node_p->next = NULL;
	if(QueueEmpty(queue_p))
	{
		queue_p->front = queue_p->rear = new_node_p;
	}
	else
	{
		queue_p->rear->next = new_node_p;
		queue_p->rear = new_node_p;
	}
}

bool OutofQueue(LinkQueue * &queue_p, ElemType &elem)
{
	QueueNode *dele_node_p = queue_p->front;
	if(QueueEmpty(queue_p)	// 判断是否队空
		return false;
	if(queue_p->front == queue_p->rear)	//判断队列是否只有一个结点
		queue_p->front = queue_p->rear = NULL;
	else
		queue_p->front = dele_node_p->next;
	elem = dele_node_p->data;
	free(dele_node_p);
	return true;
}
