#include"bst.h"

BSTNode *create_bst(KeyType R[], int n)
{
	int i = 0;
	BSTNode *bt = NULL;
	while (i < n)
	{
		insert_bst(bt, R[i]);
		i++;
	}
	return bt;
}

bool insert_bst(BSTNode * &bt, KeyType k)
{
	if (bt == NULL)
	{
		bt = (BSTNode *)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)
	{
		return false;
	}
	else if (k < bt->key)
	{
		return insert_bst(bt->lchild, k);
	}
	else
	{
		return insert_bst(bt->rchild, k);
	}
}

void print_bst(BSTNode *bt)
{
	if (bt != NULL)
	{
		print_bst(bt->lchild);
		printf("%3d", bt->key);
		print_bst(bt->rchild);
	}
}

void destroy_bst(BSTNode *bt)
{
	if (bt != NULL)
	{
		destroy_bst(bt->lchild);
		destroy_bst(bt->rchild);
		free(bt);
	}
}

bool delete_bst(BSTNode * &bt, KeyType k)
{
	if (bt == NULL)
	{
		return false;
	}
	else if (k == bt->key)
	{
		delete1(bt);
		return true;
	}
	else if (k < bt->key)
	{
		return delete_bst(bt->lchild, k);
	}
	else
	{
		return delete_bst(bt->rchild, k);
	}
}

void delete1(BSTNode *&p)
{
	BSTNode *q;
	if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else
		delete2(p, p->lchild);
}

void delete2(BSTNode *p, BSTNode * &r)
{
	BSTNode *q;
	if (r->rchild != NULL)
		delete2(p, r->rchild);
	else
	{
		q = r;
		p->key = r->key;
		p->data = r->data;
		r = r->lchild;
		free(q);
	}
}
