#include"thread.h"

void in_thread(BTNode *bt, BTNode **pp)
{
	if (bt != NULL)
	{
		in_thread(bt->lchild, pp);
		if (bt->lchild == NULL)
		{
			bt->lchild = *pp;
			bt->ltag = 1;
		}
		else
			bt->ltag = 0;
		if ((*pp)->rchild == NULL)
		{
			(*pp)->rchild = bt;
			(*pp)->rtag = 1;
		}
		else
			(*pp)->rtag = 0;
		*pp = bt;
		in_thread(bt->rchild, pp);
	}
}

BTNode *create_in_thread(BTNode *bt)
{
	BTNode *root, *pre;
	root = (BTNode *)malloc(sizeof(BTNode));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = bt;
	if (bt == NULL)
		root->lchild = root;
	else	
	{
		root->lchild = bt;
		pre = root;
		in_thread(bt, &pre);
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


