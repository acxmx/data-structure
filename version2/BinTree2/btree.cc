#include"btree.h"

//creating order: root --> left child --> right child
void create_btree(BTNode * &bt, char *str)
{
	BTNode *st[20], *p;
	int top = -1, i = 0, flag;
	char ch;
	ch = str[i];
	init_btree(bt);
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
		st[++top] = p; flag = 1; break;
		case ')':
		top--; break;
		case ',':
		flag = 2; break;
		default:
		p = (BTNode *)malloc(sizeof(BTNode));
		p->data = ch;
		p->lchild = p->rchild = NULL;
		if (bt == NULL)
			bt = p;
		else
		{
			switch (flag)
			{
			case 1:
			st[top]->lchild = p; break;
			case 2:
			st[top]->rchild = p; break;
			default:break;
			}
		}
		}
	i++;
	ch = str[i];
	}
}

void init_btree(BTNode * &bt)
{
	bt = NULL;
}

void destroy_btree(BTNode *bt)
{
	if (bt != NULL)
	{
		destroy_btree(bt->lchild);
		destroy_btree(bt->rchild);
		free(bt);
	}
}

void print_btree(BTNode *bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			print_btree(bt->lchild);
			if (bt->rchild != NULL)
				printf(",");
			print_btree(bt->rchild);
			printf(")");
		}
	}
}

int btree_height(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else
	{
		int lh = btree_height(bt->lchild);
		int rh = btree_height(bt->rchild);
		return lh > rh ? lh+1 : rh +1;
	}
}
