#include"BLList.h"
#include"SqStack.h"

void CreateBTree(BTNode * &btree_p, char *str)
{
	BTNode *node_stack[50], *node;
	int top = -1, index = 0, flag;
	btree_p = NULL;  //尽量在定义指针时进行指针的初始化
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
				node->lchild = node->rchild = NULL;  //一定要记得初始化指针域
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
	if(btree_p != NULL)
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

BTNode * FindNode(BTNode *btree_p, ElemType data)
{
	if(btree_p == NULL)
		return NULL;
	else if(btree_p->data == data)
		return btree_p;
	else
	{
		BTNode *found_node = FindNode(btree_p->lchild, data);
		if(found_node)
			return found_node;
		else
			return FindNode(btree_p->rchild, data);
	}
}

int BTreeHeight(BTNode *btree_p)
{
	if(btree_p == NULL)
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
	if(btree_p != NULL)
	{
		printf("%c",btree_p->data);
		if(btree_p->lchild != NULL
		|| btree_p->rchild != NULL)
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
	if(btree_p != NULL)
	{
		printf("%c",btree_p->data);
		PreTravel(btree_p->lchild);
		PreTravel(btree_p->rchild);
	}
#if 0  
此乃递归出口，因为函数返回值是void类型，因此可缺省，由编译器默认执行
	else
		return ;
#endif
}

void InTravel(BTNode *btree_p)
{
	if(btree_p != NULL)
	{
		InTravel(btree_p->lchild);
		printf("%c",btree_p->data);
		InTravel(btree_p->rchild);
	}
}

void PostTravel(BTNode *btree_p)
{
	if(btree_p != NULL)
	{
		PostTravel(btree_p->lchild);
		PostTravel(btree_p->rchild);
		printf("%c",btree_p->data);
	}
}

void PreTravel1(BTNode * btree_p)
{
	BTNode *node_p;
	SqStack *stack_p;
	InitStack(stack_p);
	if(btree_p != NULL)
	{
		Push(stack_p, btree_p);
		while(!StackEmpty(stack_p))
		{
			Pop(stack_p, node_p);
			printf("%c",node_p->data);
			if(node_p->rchild != NULL)
				Push(stack_p, node_p->rchild);
			if(node_p->lchild != NULL)
				Push(stack_p, node_p->lchild);
		}
		printf("\n");
	}
	DestroyStack(stack_p);
}

void PreTravel2(BTNode *btree_p)
{
	BTNode *node_p = btree_p;
	SqStack *stack_p;
	InitStack(stack_p);
	while (!StackEmpty(stack_p) || node_p != NULL)
	{
		while (node_p != NULL)
		{
			printf("%c", node_p->data);
			Push(stack_p, node_p);
			node_p = node_p->lchild;
		}
		if (!StackEmpty(stack_p))
		{
			Pop(stack_p, node_p);
			node_p = node_p->rchild;
		}	
	}
	printf("\n");
	DestroyStack(stack_p);
}

void InTravel1(BTNode *btree_p)
{
	SqStack *stack_p;
	InitStack(stack_p);
	BTNode *node_p;
	node_p = btree_p;
	while(!StackEmpty(stack_p) || node_p != NULL)
	{
		while(node_p != NULL)
		{
			Push(stack_p, node_p);
			node_p = node_p->lchild;
		}
		if(!StackEmpty(stack_p))
		{
			Pop(stack_p, node_p);
			printf("%c", node_p->data);
			node_p = node_p->rchild;
		}
	}
	printf("\n");
	DestroyStack(stack_p);
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
			return (Level(btree_p->rchild,find_data,height+1));
	}
}

//层级结点数计算 --> 重点在于层级
void LevelNodesCount(BTNode *btree_p, int height_now, int height_goal
, int &count)
{
	if(btree_p == NULL)
		return ;
	else
	{
		if(height_now == height_goal)
			count++;
		else if(height_now < height_goal)
		{
			LevelNodesCount(btree_p->lchild, height_now+1
			, height_goal, count);
			LevelNodesCount(btree_p->rchild, height_now+1
			, height_goal, count);
		}
	}
}

bool BTreeLike(BTNode *btree_p1, BTNode *btree_p2)
{
	if(btree_p1 == NULL && btree_p2 == NULL)
		return true;
	else if(btree_p1 == NULL || btree_p2 == NULL)
		return false;
	else
	{
		bool like1 = BTreeLike(btree_p1->lchild, btree_p2->lchild);
		bool like2 = BTreeLike(btree_p1->rchild, btree_p2->rchild);
		return (like1 && like2);
	}
}

//输出祖先，那么如何判断祖先呢？祖先的定义、逆向思考：从子孙结点的定义出发
bool Ancestor(BTNode *btree_p, ElemType data)
{
	if(btree_p == NULL)
		return false;
	else if(btree_p->lchild != NULL && btree_p->lchild->data == data
	|| btree_p->rchild != NULL && btree_p->rchild->data == data)
	{
		printf("%c",btree_p->data);
		return true;
	}
	else if(Ancestor(btree_p->lchild, data) 
	|| Ancestor(btree_p->rchild, data))
	{
		printf("%c",btree_p->data);
		return true;
	}
	else
		return false;
}
