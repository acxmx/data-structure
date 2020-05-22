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

int count_dbnode(BTNode *bt)
{
	if (bt == NULL)
		return 0;
	else if (bt->lchild != NULL && bt->rchild != NULL)
		return (1 + count_dbnode(bt->lchild)
			+ count_dbnode(bt->rchild));
	else
		return (count_dbnode(bt->lchild)
		+ count_dbnode(bt->rchild));
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
/*
void count_node_k(BTNode *bt, int k, int h)
{
	if (bt == NULL)
		return ;
	else if (h == k)
		cnt++;
	else if (h < k)
	{
		count_node_k(bt->lchild, k, h+1);
		count_node_k(bt->rchild, k, h+1);
	}
}
*/

void count_node_k2(BTNode *bt, int k, int h, int *cp)
{
	if (bt == NULL)
		return ;
	else if (h == k)
		(*cp)++;
	else if (h < k)
	{
		count_node_k2(bt->lchild, k, h+1, cp);
		count_node_k2(bt->rchild, k, h+1, cp);
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
		bool like1 = is_like(bt1->lchild, bt2->lchild);
		bool like2 = is_like(bt1->rchild, bt2->rchild);
		return (like1 && like2);
	}
}

bool print_ancestor(BTNode *bt, ElemType x)
{
	if (bt == NULL)
		return false;
	else if (bt->lchild != NULL && bt->lchild->data == x
	|| bt->rchild != NULL && bt->rchild->data == x)
	{
		printf("%c ", bt->data);
		return true;
	}
	else if (print_ancestor(bt->lchild, x)
	|| print_ancestor(bt->rchild, x))
	{
		printf("%c ", bt->data);
		return true;
	}
	else
		return false;
}

void pre_travel1(BTNode *bt)
{
	BTNode *stack[10], *p;
	int top = -1;
	p = bt;
	while (top != -1 || p != NULL)
	{
		while (p != NULL)
		{
			printf("%c ", p->data);
			stack[++top] = p;
			p = p->lchild;
		}
		if (top != -1)
		{
			p = stack[top--];
			p = p->rchild;
		}
	}
	printf("\n");
}

void pre_travel2(BTNode *bt)
{
	BTNode *stack[10], *p;
	int top = -1;
	if (bt != NULL)
	{
		stack[++top] = bt;
		while (top != -1)
		{
			p = stack[top--];
			printf("%c ", p->data);
			if (p->rchild != NULL)
				stack[++top] = p->rchild;
			if (p->lchild != NULL)
				stack[++top] = p->lchild;
		}
	}
	printf("\n");
}

void in_travel1(BTNode *bt)
{
	BTNode *stack[10], *p;
	int top = -1;
	p = bt;
	while (top != -1 || p != NULL)
	{
		while (p != NULL)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		if (top != -1)
		{
			p = stack[top--];
			printf("%c ", p->data);
			p = p->rchild;
		}
	}
	printf("\n");
}

void post_travel1(BTNode *bt)
{
	BTNode *stack[10], *p, *r;
	int top = -1;
	bool flag;
	p = bt;
	do
	{
		while (p != NULL)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (top != -1 && flag)
		{
			p = stack[top];
			if (p->rchild == r)
			{
				printf("%c ", p->data);
				r = p;
				top--;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	}while (top != -1);
	printf("\n");
}

void print_ancestor1(BTNode *bt)
{
	BTNode *stack[10], *p, *r;
	int top = -1, i;
	bool flag;
	p = bt;
	do
	{
		while (p != NULL)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (top != -1 && flag)
		{
			p = stack[top];
			if (p->rchild == r)
			{
				if (p->lchild == NULL && p->rchild == NULL)
				{
					i = top-1;
					printf("%c: ", p->data);
					while (i != -1)
						printf("%c ", 
						stack[i--]->data);
					printf("\n");
				}
				r = p;
				top--;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	}while (top != -1);
	printf("\n");
}

void level_travel(BTNode *bt)
{
	BTNode *queue[5], *p;
	int front, rear;
	front = rear = -1;
	if (bt == NULL)
		return ;
	rear = (rear + 1) % 5;
	queue[rear] = bt;
	while (front != rear)
	{
		front = (front + 1) % 5;
		p = queue[front];
		printf("%c ", p->data);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % 5;
			queue[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % 5;
			queue[rear] = p->rchild;
		}
	}
	printf("\n");
}

//获取层次结点数
void get_width(BTNode *bt, int h, int wd[])
{
    if (bt == NULL)
        return ;
    else
    {
        wd[h]++;
        get_width(bt->lchild, h+1, wd);
        get_width(bt->rchild, h+1, wd);
    }
}

//简单选择思想求出树宽
int btree_width(BTNode *bt)
{
    int i, n, max;
    n = btree_height(bt);		//求出树高
    int wd[n+1];		//定义数组保存树宽信息
    for (i = 0; i < n+1; i++)
	wd[i] = 0;
    get_width(bt, 1, wd);
    for (i = 1, max = 0; i <= n; i++)
        if (max < wd[i])
            max = wd[i];
    return max;
}

// recursion creating binary tree
BTNode *create_bt1(char *pre, char *in, int n)
{
	BTNode *bt;
	char *p;
	int k;
	if (n <= 0) return NULL;
	bt = (BTNode *)malloc(sizeof(BTNode));
	bt->data = *pre;
	for (p = in; p < in+n; p++)
		if (*p == *pre)
			break;
	k = p - in;
	bt->lchild = create_bt1(pre+1, in, k);
	bt->rchild = create_bt1(pre+1+k, p+1, n-k-1);
	return bt;
}

BTNode *create_bt2(char *post, char *in, int n)
{
	BTNode *bt;
	char *p;
	int k;
	if (n <= 0) return NULL;
	bt = (BTNode *)malloc(sizeof(BTNode));
	bt->data = *(post+n-1);
	for (p = in; p < in+n; p++)
		if (*p == *(post+n-1))
			break;
	k = p - in;
	bt->lchild = create_bt2(post, in, k);
	bt->rchild = create_bt2(post+k, p+1, n-k-1);
	return bt;
}

int btree_width2(BTNode *bt)
{
    typedef struct
    {
        int lvl;
        BTNode *p;
    }Nodequ;
    int front, rear, width, i, lct, nct;
    int n = count_node(bt);
    Nodequ qu[n], tp;
    front = rear = -1;
    if (bt != NULL)
    {
        rear++;
        qu[rear].p = bt;
        qu[rear].lvl = 1;
        while (front != rear)
        {
            front++;
            tp = qu[front];
            if (tp.p->lchild != NULL)
            {
                rear++;
                qu[rear].p = tp.p->lchild;
                qu[rear].lvl = tp.lvl + 1;
            }
            if (tp.p->rchild != NULL)
            {
                rear++;
                qu[rear].p = tp.p->rchild;
                qu[rear].lvl = tp.lvl + 1;
            }
        }
        width = i = 0;
        lct = 0;
        while (i <= rear)
        {
            nct = 0;
            lct++;
            while (i <= rear && qu[i].lvl == lct)
            {
                nct++;
                i++;
            }
            if (width < nct)
                width = nct;
        }
        return width;
    }
    return 0;
}
