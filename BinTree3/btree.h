#ifndef BTREE
#define BTREE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

//basic operation
void create_btree(BTNode **, char *);
void init_btree(BTNode **);
void destroy_btree(BTNode *);
void print_btree(BTNode *);

//algorithm
BTNode *find_node(BTNode *, ElemType);
int btree_height(BTNode *);
void pre_travel(BTNode *);
void in_travel(BTNode *);
void post_travel(BTNode *);
int count_node(BTNode *);
void print_leaf(BTNode *);
int find_node_level(BTNode *, ElemType, int);

#endif
