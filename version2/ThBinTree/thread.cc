#include"thread.h"

void create_btree(BTNode * &bt, char *str)
{
	const int MaxSize = 20;
	BTNode *st[MaxSize], *p;
	int top = -1, i = 0, flag;
	char ch;
	init_btree(bt);
	ch = str[i];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
		st[++top] = p;
		flag = 1;
		break;
		case ')':
		top--;
		break;
		case ',':
		flag = 2;
		break;
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
			st[top]->lchild = p;
			break;
			case 2:
			st[top]->rchild = p;
			break;
			default: break;
			}
		}
		break;
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

int btree_length(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else
	{
		int l1 = btree_length(bt->lchild);
		int l2 = btree_length(bt->rchild);
		return l1 > l2 ? l1+1 : l2+2;
	}
}
