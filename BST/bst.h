#ifndef BST
#define BST

#include<cstdio>
#include<cstdlib>

typedef char InfoType;
typedef int KeyType;

typedef struct node
{
	KeyType key;
	InfoType data;
	struct node *lchild;
	struct node *rchild;
}BSTNode;

BSTNode *create_bst(KeyType [], int);
BSTNode *create_bst2(KeyType [], int);
bool insert_bst(BSTNode * &, KeyType);
bool insert_bst2(BSTNode **, KeyType);
void destroy_bst(BSTNode *);
void print_bst(BSTNode *);
bool delete_bst(BSTNode * &, KeyType);
void delete1(BSTNode * &);
void delete2(BSTNode *, BSTNode * &);
bool delete_bst2(BSTNode **, KeyType);
void delete1_2(BSTNode **);
void delete2_2(BSTNode *, BSTNode **);

#endif
