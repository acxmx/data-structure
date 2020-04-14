#ifndef BTREE
#define BTREE

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
void count_node_k(BTNode *, int, int);
void count_node_k2(BTNode *, int, int, int *);
bool is_like(BTNode *, BTNode *);
bool print_ancestor(BTNode *, ElemType x);

//non-recursion traveling
void pre_travel1(BTNode *);
void pre_travel2(BTNode *);
void in_travel1(BTNode *);
void post_travel1(BTNode *);
void print_ancestor1(BTNode *);
void level_travel(BTNode *);

//recursion creating binary tree
BTNode *create_bt1(char *, char *, int);
BTNode *create_bt2(char *, char *, int);

#endif
