#ifndef BTREE
#define BTREE

#include<cstdio>
#include<cstdlib>

typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

//basic operation
void create_btree(BTNode * &, char *);
void init_btree(BTNode * &);
void destroy_btree(BTNode *);
void print_btree(BTNode *);
int btree_height(BTNode *);

//algorithms
void post_travel(BTNode *);
int count_node(BTNode *);
void print_leaf(BTNode *);
int count_node_level(BTNode *, int, char);
void count_node_levelk(BTNode *, int, int, int&);
bool is_like(BTNode *, BTNode *);
bool print_ancestor(BTNode *, int);

#endif
