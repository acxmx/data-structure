#include"BLList.h"

void CreateBTree(BTNode * &btree_p, char *str)
{
	BTNode *node_stack[50], *node;
	int top = -1, index = 0, flag;
	char ch = str[index];
	while(ch != '\0')
	{
		switch(ch)
		{
			case '(':
				top++;
				node_stack[top] = node;
				flag = 1;
				break;
			case ')':
				top--;
				break;
			case ',':
				flag = 2;
				break;
			default:
				node = (BTNode *)malloc(sizeof(BTNode));
				node->data = ch;
				if(!btree_p)
					btree_p = node;
				else
				{
					switch(flag)
					{
						case 1:
							node_stack[top]->lchild = node;
							break;
						case 2:
							node_stack[top]->rchild = node;
							break;
					}
				}
				break;
		}
		index++;
		ch = str[index];
	}
}

void DestroyBTree(BTNode * &btree_p)
{
	if(btree_p)
	{
		DestroyBTree(btree_p->lchild);
		DestroyBTree(btree_p->rchild);
		free(btree_p);
	}
}

BTNode * FindLChild(BTNode *btree_p)
{
	return (btree_p->lchild);
}

BTNode * FindRChild(BTNode *btree_p)
{
	return (btree_p->rchild);
}

BTNode * FindNode(BTNode *btree_p, ElemType elem)
{
	if(btree_p == NULL)
		return NULL;
	else if(btree_p->data == elem)
		return btree_p;
	else
	{
		BTNode *found_node = FindNode(btree_p->lchild, elem);
		if(found_node)
			return found_node;
		else
			FindNode(btree_p->rchild, elem);
	}
}

int BTreeHeight(BTNode *btree_p)
{
	if(!btree_p)
		return 0;
	else
	{
		int lchild_height = BTreeHeight(btree_p->lchild);
		int rchild_height = BTreeHeight(btree_p->rchild);
		return (lchild_height>rchild_height) ? (lchild_height + 1) : (rchild_height + 1);
	}
}

void DispBTree(BTNode *btree_p)
{
	if(btree_p)
	{
		printf("%c",btree_p->data);
		if(btree_p->lchild || btree_p->rchild)
		{
			printf("(");
			DispBTree(btree_p->lchild);
			if(btree_p->rchild)
				printf(",");
			DispBTree(btree_p->rchild);
			printf(")");
		}
	}
}

void PreTravel(BTNode *btree_p)
{
	if(btree_p)
	{
		printf("%c",btree_p->data);
		PreTravel(btree_p->lchild);
		PreTravel(btree_p->rchild);
	}
}

void InTravel(BTNode *btree_p)
{
	if(btree_p)
	{
		InTravel(btree_p->lchild);
		printf("%c",btree_p->data);
		InTravel(btree_p->rchild);
	}
}

void PostTravel(BTNode *btree_p)
{
	if(btree_p)
	{
		PostTravel(btree_p->lchild);
		PostTravel(btree_p->rchild);
		printf("%c",btree_p->data);
	}
}

int NodesCount(BTNode *btree_p)
{
	if(btree_p == NULL)
		return 0;
	else
		return NodesCount(btree_p->lchild)
		+ NodesCount(btree_p->rchild) + 1;
}

void DispLeaf(BTNode *btree_p)
{
	if(btree_p != NULL)
	{
		if(btree_p->lchild == NULL
		&& btree_p->rchild == NULL)
			printf("%c\t",btree_p->data);
		else
		{
		DispLeaf(btree_p->lchild);
		DispLeaf(btree_p->rchild);
		}
	}
}

int Level(BTNode *btree_p, ElemType find_data, int height)
{
	if(btree_p == NULL)
		return 0;
	else if(btree_p->data == find_data)
		return height;
	else
	{
		int height2 = Level(btree_p->lchild,find_data,height+1);
		if(height2 != 0)
			return height2;
		else
			return (btree_p->rchild,find_data,height+1);
	}
}
