#include"thread.h"

BTNode *pre;
void in_thread(BTNode *bt)
{
	if (bt != NULL)
	{
		in_thread(bt->lchild);
		if (bt->lchild == NULL)
		{
			bt->lchild = pre;
			bt->ltag = 1;
		}
		else
			bt->ltag = 0;
		if (pre->rchild == NULL)
		{
			pre->rchild = bt;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = bt;
		in_thread(bt->rchild);
	}
}

BTNode *create_in_thread(BTNode *bt)
{
	BTNode *root = (BTNode *)malloc(sizeof(BTNode));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = bt;
	if (bt == NULL)
		root->lchild = root;
	else	
	{
		root->lchild = bt;
		pre = root;
		in_thread(bt);
		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;
	}
	return root;
}

void print_in_thread(BTNode *root)
{
	BTNode *p;
	p = root->lchild;
	while (p != root)
	{
		while (p->ltag == 0)
			p = p->lchild;
		printf("%2c", p->data);
		while (p->rtag == 1 && p->rchild != root)
		{
			p = p->rchild;
			printf("%2c", p->data);
		}
		p = p->rchild;
	}
	printf("\n");
}
