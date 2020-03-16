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

//non-recursion travling
void pre_travel1(BTNode *bt)
{
	BTNode *st[30], *p;
	int top = -1;
	if (bt != NULL)
	{
		st[++top] = bt;
		while (top != -1)
		{
			p = st[top--];
			printf("%2c", p->data);
			if (p->rchild != NULL)
				st[++top] = p->rchild;
			if (p->lchild != NULL)
				st[++top] = p->lchild;
		}
		printf("\n");
	}
}

void pre_travel2(BTNode *bt)
{
	BTNode *st[30], *p;
	int top = -1;
	p = bt;
	while (top != -1 || p != NULL)
	{
		while (p != NULL)
		{
			printf("%2c", p->data);
			st[++top] = p;
			p = p->lchild;
		}
		if (top != -1)
		{
			p = st[top--];
			p = p->rchild;
		}
	}
	printf("\n");
}

void in_travel1(BTNode *bt)
{
	BTNode *st[30], *p;
	int top = -1;
	p = bt;
	while (top != -1 || p != NULL)
	{
		while (p != NULL)
		{
			st[++top] = p;
			p = p->lchild;
		}
		if (top != -1)
		{
			p = st[top--];
			printf("%2c", p->data);
			p = p->rchild;
		}
	}
	printf("\n");
}

void post_travel1(BTNode *bt)
{
	BTNode *st[10], *p, *r;
	int top = -1;
	bool flag;
	p = bt;
	do
	{
		while (p != NULL)
		{
			st[++top] = p;
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (top != -1 && flag)
		{
			p = st[top];
			if (p->rchild == r)
			{
				p = st[top--];
				printf("%2c", p->data);
				r = p;
			}else{
				p = p->rchild;
				flag = false;
			}
		}
	}while (top != -1);
	printf("\n");
}

void level_travel(BTNode *bt)
{
	const int MaxSize = 10;
	BTNode *qu[MaxSize], *p;
	int front = -1, rear = -1;
	rear = (rear + 1) % MaxSize;
	qu[rear] = bt;
	while (front != rear)
	{
		front = (front + 1) % MaxSize;
		p = qu[front];
		printf("%2c", p->data);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
	printf("\n");
}

