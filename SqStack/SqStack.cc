#include"SqStack.h"

void InitStack(SqStack * &s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack * &s)
{
	free(s);
}

bool StackEmpty(SqStack *s)
{
	return (s->top == -1);
}

bool Push(SqStack * &s, ElemType e)
{
	if(s->top == MaxSize-1)
		return false;
	s->data[++s->top] = e;
	return true;
}

bool Pop(SqStack * &s, ElemType &e)
{
	if(StackEmpty(s))
		return false;
	e = s->data[s->top--];
	return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
	if(StackEmpty(s))
		return false;
	e = s->data[s->top];
	return true;
}

//判断回文算法
bool symmetry(ElemType *str)
{
	int i;
	ElemType e;
	SqStack *s;
	s = (SqStack *)malloc(sizeof(SqStack));
	for(i=0; str[i]!='\0'; i++)
		Push(s,str[i]);
	for(i=0; str[i]!='\0'; i++)
	{
		Pop(s,e);
		if(e != str[i])
		{
			DestroyStack(s);
			return false;
		}
	}
	DestroyStack(s);
	return true;
}
