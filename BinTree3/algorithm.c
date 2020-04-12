#include"btree.h"

BTNode *find_node(BTNode *bt, ElemType ch)
{
	if (bt == NULL || bt->data == ch)
		return bt;
	else
	{
		BTNode *p = find_node(bt->lchild, ch);
		if (p != NULL)
			return p;
		else
			return find_node(bt->rchild, ch);
	}
}

int btree_height(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else
	{
		int h1 = btree_height(bt->lchild);
		int h2 = btree_height(bt->rchild);
		return ( h1 > h2 ? (h1+1):(h2+1) );
	}
}

void pre_travel(BTNode *bt)
{
	if (bt != NULL)
	{
		printf("%c ", bt->data);
		pre_travel(bt->lchild);
		pre_travel(bt->rchild);
	}
}

void in_travel(BTNode *bt)
{
	if (bt != NULL)
	{
		in_travel(bt->lchild);
		printf("%c ", bt->data);
		in_travel(bt->rchild);
	}
}

void post_travel(BTNode *bt)
{
	if (bt != NULL)
	{
		post_travel(bt->lchild);
		post_travel(bt->rchild);
		printf("%c ", bt->data);
	}
}

int count_node(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else
		return (count_node(bt->lchild) + 
		count_node(bt->rchild) + 1);
}

void print_leaf(BTNode *bt)
{
	if (bt == NULL)
		return ;
	else if (bt->lchild == NULL && bt->rchild == NULL)
	{
		printf("%c ", bt->data);
		return ;
	}
	else
	{
		print_leaf(bt->lchild);
		print_leaf(bt->rchild);
	}
}

int find_node_level(BTNode *bt, ElemType x, int h)
{
	if (bt == NULL)
		return 0;
	else if (bt->data == x)
		return h;
	else
	{
		int l = find_node_level(bt->lchild, x, h+1);
		if (l != 0)
			return l;
		else
			return find_node_level(bt->rchild, x, h+1);
	}
}
