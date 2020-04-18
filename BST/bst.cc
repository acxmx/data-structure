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

BSTNode *create_bst2(KeyType *arr, int n)
{
	BSTNode *bst = NULL;
	int i = 0;
	while (i < n)
	{
		insert_bst2(&bst, *(arr+i));
		i++;
	}
	return bst;
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

bool insert_bst2(BSTNode **bstp, KeyType key)
{
	if (*bstp == NULL)
	{
		*bstp = (BSTNode *)malloc(sizeof(BSTNode));
		(*bstp)->key = key;
		(*bstp)->lchild = (*bstp)->rchild = NULL;
		return true;
	}
	else if ((*bstp)->key == key)
		return false;
	else if (key < (*bstp)->key)
		return insert_bst2(&(*bstp)->lchild, key);
	else
		return insert_bst2(&(*bstp)->rchild, key);
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

bool delete_bst2(BSTNode **bstp, KeyType key)
{
	if (*bstp == NULL)
		return false;
	else if ((*bstp)->key == key)
	{
		delete1_2(bstp);
		return true;
	}
	else if (key < (*bstp)->key)
		return delete_bst2(&(*bstp)->lchild, key);
	else
		return delete_bst2(&(*bstp)->rchild, key);
}

void delete1_2(BSTNode **bstp)
{
	BSTNode *q;
	if ((*bstp)->rchild == NULL)
	{
		q = *bstp;
		*bstp = (*bstp)->lchild;
		free(q);
	}
	else if ((*bstp)->lchild == NULL)
	{
		q = *bstp;
		*bstp = (*bstp)->rchild;
		free(q);
	}
	else 
		delete2_2(*bstp, &(*bstp)->lchild);
}

void delete2_2(BSTNode *bst, BSTNode **rp)
{
	BSTNode *q;
	if ((*rp)->rchild != NULL)
		delete(bst, &(*rp)->rchild);
	else
	{
		bst->data = (*rp)->data;
		bst->key = (*rp)->key;
		q = *rp;
		*rp = (*rp)->lchild;
		free(q);
	}
}
