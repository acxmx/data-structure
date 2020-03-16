#include"btree.h"

//traveling algorithm
void post_travel(BTNode *bt)
{
	if (bt != NULL)
	{
		post_travel(bt->lchild);
		post_travel(bt->rchild);
		printf("%2c", bt->data);
	}
}

//other algorithms
int count_node(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else
		return count_node(bt->lchild)
		+ count_node(bt->rchild) + 1;
}

void print_leaf(BTNode *bt)
{
	if (bt != NULL)
	{
		if (bt->lchild == NULL && bt->rchild ==NULL)
		{
			printf("%2c", bt->data);
			return ;
		}else{
			print_leaf(bt->lchild);
			print_leaf(bt->rchild);
		}
	}
}

int count_node_level(BTNode *bt, int h, char node)
{
	if (bt == NULL)
		return 0;
	else if (bt->data == node)
		return h;
	else
	{
		int h1 = count_node_level(bt->lchild, h+1, node);
		if (h1 != 0)
			return h1;
		else
			return count_node_level(bt->rchild ,h+1, node);
	}
}

void count_node_levelk(BTNode *bt, int h, int k, int &cnt)
{
	if (bt != NULL)
	{
		if (h == k)
			cnt++;
		else if (h < k)
		{
			count_node_levelk(bt->lchild, h+1, k, cnt);
			count_node_levelk(bt->rchild, h+1, k, cnt);
		}
	}
}

bool is_like(BTNode *bt1, BTNode *bt2)
{
	if (bt1 == NULL && bt2 == NULL)
		return true;
	else if (bt1 == NULL || bt2 == NULL)
		return false;
	else
	{
		bool l1 = is_like(bt1->lchild, bt2->lchild);
		bool l2 = is_like(bt1->rchild, bt2->rchild);
		return l1 && l2;
	}
}

bool print_ancestor(BTNode *bt, int x)
{
	if (bt == NULL)
		return false;
	else if (bt->lchild != NULL && bt->lchild->data == x
		|| bt->rchild != NULL && bt->rchild->data == x)
	{
			printf("%2c", bt->data);
			return true;
	}
	else if (print_ancestor(bt->lchild, x)
	|| print_ancestor(bt->rchild, x))
	{
		printf("%3c", bt->data);
		return true;
	}
	else 
		return false;
}
