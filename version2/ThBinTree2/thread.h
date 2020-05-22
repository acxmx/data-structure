#ifndef THREAD
#define THREAD

#include<cstdio>
#include<cstdlib>

typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
	int ltag, rtag;
}BTNode;

//basic algorithm
void create_btree(BTNode * &, char *);
void init_btree(BTNode * &);
void destroy_btree(BTNode *);
void print_btree(BTNode *);
int btree_height(BTNode *);

//threding
void in_thread(BTNode *, BTNode **);
BTNode * create_in_thread(BTNode *);
void print_in_thread(BTNode *);

#endif
