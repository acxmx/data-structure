#ifndef BLLIST
#define BLLIST
#include<cstdio>
#include<cstdlib>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTree(BTNode * &, char *);
void DestroyBTree(BTNode * &);
void DispBTree(BTNode *);
BTNode * FindLChild(BTNode *);
BTNode * FindRChild(BTNode *);
BTNode * FindNode(BTNode *, ElemType);
int BTreeHeight(BTNode *);
//recursive traveling binarytree 
void PreTravel(BTNode *);
void InTravel(BTNode *);
void PostTravel(BTNode *);

//recursion applying
int NodesCount(BTNode *);
void DispLeaf(BTNode *);
int Level(BTNode *, ElemType, int);
void LevelNodesCount(BTNode *, int, int, int &);
bool BTreeLike(BTNode *, BTNode *);
bool Ancestor(BTNode *, ElemType);

#endif
