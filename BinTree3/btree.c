#include"btree.h"

void create_btree(BTNode **pp, char *str)
{
    int len = strlen(str);
    int k, i = 0, top = -1;
    char ch;
    BTNode *p, *stack[len];
    init_btree(pp);
    ch = *(str + i);
    while (ch != '\0')
    {
        switch (ch)
        {
            case '(':
              stack[++top] = p;
              k = 1;
              break;
            case ',':
              k = 2;
              break;
            case ')':
              top--;
              break;
            default:
                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (*pp == NULL)
                    *pp = p;
                else
                {
                    switch (k)
                	{
                    case 1:
                        stack[top]->lchild = p;
                        break;
                    case 2:
                        stack[top]->rchild = p;
                        break;
                	}
                }
                break;
        }
        i++;
        ch = *(str + i);
    }
}

void init_btree(BTNode **pp)
{
	*pp = NULL;
}

void destroy_btree(BTNode *bt)
{
    if (bt == NULL)
        return ;
    else
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

