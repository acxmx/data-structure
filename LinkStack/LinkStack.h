#ifndef LINKSTACK
#define LINKSTACK

#include<cstdio>
#include<cstdlib>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkStNode;

//基本运算
void InitStack(LinkStNode * &);
void DestroyStack(LinkStNode * &);
bool StackEmpty(LinkStNode *);
void Push(LinkStNode * &, ElemType);
bool Pop(LinkStNode * &, ElemType &);
bool GetTop(LinkStNode *, ElemType);

//栈的应用：括号的匹配
bool Match(char *);

#endif
