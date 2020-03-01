#ifndef TAGBTREE
#define TAGBTREE

#include<cstdio>
#include<cstdlib>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	int ltag, rtag;
	struct node *lchild;
	struct node *rchild;
}TagBTNode;

void CreateTagBTree(TagBTNode * &, char *);
void DestroyTagBTree(TagBTNode * &);
void DispTagBTree(TagBTNode *);

//下面一个函数的形参可以不为引用，因为修改一个结点的内容，只要得到它的指针即可；而指针的初始化函数必须使用引用类型，因为未初始化的指针是个悬空指针，必须把函数内初始化分配的地址赋给指针变量，并带回给实参指针变量
void Thread(TagBTNode *);
TagBTNode *CreateThread(TagBTNode *);
void ThreadInTravel(TagBTNode *);

#endif
