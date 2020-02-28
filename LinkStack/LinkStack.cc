#include"LinkStack.h"

void InitStack(LinkStNode * &stack_p)
{
	stack_p = (LinkStNode *)malloc(sizeof(LinkStNode));
	stack_p->next = NULL;
}

void DestroyStack(LinkStNode * &stack_p)
{
	LinkStNode *pre = stack_p, *p = stack_p->next;
	while(p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool StackEmpty(LinkStNode *stack_p)
{
	return (stack_p->next == NULL);
}

void Push(LinkStNode * &stack_p, ElemType elem)
{
	LinkStNode *node_p;
	node_p = (LinkStNode *)malloc(sizeof(LinkStNode));
	node_p->data = elem;
	node_p->next = stack_p->next;
	stack_p->next = node_p;
}

bool Pop(LinkStNode * &stack_p, ElemType &elem)
{
	LinkStNode *node_p;
	if(StackEmpty(stack_p))
		return false;
	else
	{
	node_p = stack_p->next;
	elem = node_p->data;
	stack_p->next = node_p->next;
	free(node_p);
	return true;
	}
}

bool Match(char *exp)
{
	int i=0;
	ElemType elem;
	LinkStNode *stack_p;
	InitStack(stack_p);
	bool match = true;
	while(exp[i]!='\0' && match)
	{
		if(exp[i] == '(')
			Push(stack_p,exp[i]);
		else if(exp[i] == ')')
			if(StackEmpty(stack_p))
				match = false;
			else
				Pop(stack_p,elem);
		i++;
	}
	if(!StackEmpty(stack_p))
		match = false;
	DestroyStack(stack_p);
	return match;
}
