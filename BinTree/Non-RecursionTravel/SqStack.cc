#include"SqStack.h"

void InitStack(SqStack * &stack_p)
{
	stack_p = (SqStack *)malloc(sizeof(SqStack));
	stack_p->top = -1;
}

void DestroyStack(SqStack * &stack_p)
{
	free(stack_p);
}

bool StackEmpty(SqStack *stack_p)
{
	return (stack_p->top == -1);
}

bool Push(SqStack * &stack_p, ElemType_stack elem)
{
	if(stack_p->top == MaxSize-1)
		return false;
	else
	{
		stack_p->top++;
		stack_p->data[stack_p->top] = elem;
		return true;
	}
}

bool Pop(SqStack * &stack_p, ElemType_stack &elem)
{
	if(StackEmpty(stack_p))
		return false;
	else
	{
		elem = stack_p->data[stack_p->top];
		stack_p->top--;
		return true;
	}
}

bool GetTop(SqStack *stack_p, ElemType_stack &elem)
{
	if(StackEmpty(stack_p))
		return false;
	else
	{
		elem = stack_p->data[stack_p->top];
		return true;
	}
}

