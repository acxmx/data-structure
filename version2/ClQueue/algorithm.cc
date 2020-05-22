#include"clqueue.h"

void numberof(char *str)
{
	char qu[MaxSize];
	int front = -1, rear = -1, i;
	for (i=0; str[i] != '\0'; i++)
		qu[++rear] = str[i];
	printf("numberof:\n");
	while (front != rear )
	{
		front = (front + 1) % MaxSize;
		printf("%3c", qu[front]);
		if (front != rear)
		{
			front = (front + 1) % MaxSize;
			rear = (rear + 1) % MaxSize;
			qu[rear] = qu[front];
		}
	}
	printf("\n");
}
