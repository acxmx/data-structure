#include"TagBLList.h"

TagBTNode *pre_p;

void CreateTagBTree(TagBTNode * &btree_p, char *str)
{
	TagBTNode *stack[10], *node_p;
	btree_p = NULL;
	int top = -1, index = 0, flag;
	char ch;
	ch = str[index];
	while(ch != '\0')
	{
		switch(ch)
		{
			case '(':
			top++;
			stack[top] = node_p;
			flag = 1;
			break;
			case ',':
			flag = 2;
			break;
			case ')':
			top--;
			break;
			default:
			node_p = (TagBTNode *)malloc(sizeof(TagBTNode));
			node_p->data = ch;
			node_p->lchild = node_p->rchild = NULL;
			if(btree_p == NULL)
				btree_p = node_p;
			else
			{
				switch(flag)
				{
					case 1:
					stack[top]->lchild = node_p;
					break;
					case 2:
					stack[top]->rchild = node_p;
					break;
				}
			}
		}
	index++;
	ch = str[index];
	}
}

void DestroyTagBTree(TagBTNode * &btree_p)
{
	if(btree_p != NULL)
	{
		DestroyTagBTree(btree_p->lchild);
		DestroyTagBTree(btree_p->rchild);
		free(btree_p);
	}
}

void DispTagBTree(TagBTNode *btree_p)
{
	if(btree_p != NULL)
	{
		printf("%c", btree_p->data);
		if(btree_p->lchild != NULL
		|| btree_p->rchild != NULL)
		{
			printf("(");
			DispTagBTree(btree_p->lchild);
			if(btree_p->rchild != NULL)
				printf(",");
			DispTagBTree(btree_p->rchild);
			printf(")");
		}
	}
}

void Thread(TagBTNode *btree_p)
{
	if(btree_p == NULL)
		return ;
	else
	{
		Thread(btree_p->lchild);
		if(btree_p->lchild == NULL)
		{
			btree_p->lchild = pre_p;
			btree_p->ltag = 1;
		}
		else
			btree_p->ltag = 0;
		if(pre_p->rchild == NULL)
		{
			pre_p->rchild = btree_p;
			pre_p->rtag = 1;
		}
		else
			pre_p->rtag = 0;
		pre_p = btree_p;
		Thread(btree_p->rchild);
	}
}

TagBTNode * CreateThread(TagBTNode *btree_p)
{
	TagBTNode *root = (TagBTNode *)malloc(sizeof(TagBTNode));
	root->ltag = 0; root->rtag = 1;
	root->rchild = btree_p;
	if(btree_p == NULL)
		root->lchild = root;
	else
	{
		root->lchild = btree_p;
		pre_p = root;
		Thread(btree_p);
		pre_p->rtag = 1;
		pre_p->rchild = root;
		root->rchild = pre_p;
	}
	return root;
}

void ThreadInTravel(TagBTNode *root)
{
	TagBTNode *node_p = root->lchild;
	while(node_p != root)
	{
		while(node_p->ltag == 0)
			node_p = node_p->lchild;
		printf("%c", node_p->data);
		while(node_p->rtag == 1 && node_p->rchild != root)
		{
			node_p = node_p->rchild;
			printf("%c", node_p->data);
		}
		node_p = node_p->rchild;
	}
}
