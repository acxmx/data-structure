#include"bllist.h"

void CreateBTree(BTNode * &bt, char *str)
{
	BTNode *stack[50], *p;
	int top = -1, idx= 0, flag;
	bt = NULL;
	char ch = str[idx];
	while(ch != '\0')
	{
		switch(ch){
		case '(':
		top++;
		stack[top] = p;
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
	
		if(!bt)
			bt = p;
		else
		{
			switch(flag){
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
		idx++;
		ch = str[idx];
	}
}

void DestroyBTree(BTNode * bt)
{
	if(bt != NULL)
	{
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}

BTNode * FindNode(BTNode *bt, ElemType e)
{
	if(bt == NULL)
	{
		return NULL;
	}
	else if (bt->data == e)
	{
		return bt;
	}
	else
	{
		BTNode *p = FindNode(bt->lchild, e);
		if(p != NULL)
			return p;
		else
			return FindNode(bt->rchild, e);
	}
}

int BTreeHeight(BTNode *bt)
{
	if(bt == NULL)
	{
		return 0;
	}
	else
	{
		int lh = BTreeHeight(bt->lchild);
		int rh = BTreeHeight(bt->rchild);
		return (lh > rh) ? (lh + 1) : (rh + 1);
	}
}

void DispBTree(BTNode *bt)
{
	if(bt != NULL)
	{
		printf("%c",bt->data);
		if(bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			DispBTree(bt->lchild);
			if(bt->rchild)
	        		printf(",");
			DispBTree(bt->rchild);
			printf(")");
		}
	}
}

void PreTravel(BTNode *bt)
{
	if(bt != NULL)
	{
	    printf("%c",bt->data);
	    PreTravel(bt->lchild);
	    PreTravel(bt->rchild);
	}
#if 0  
效仿Unix风格，函数尽可能短小，简洁
此乃递归出口，因为函数返回值是void类型，因此可缺省，由编译器默认执行
	else
		return ;
#endif
}

void InTravel(BTNode *bt)
{
	if(bt != NULL)
	{
	    InTravel(bt->lchild);
	    printf("%c",bt->data);
	    InTravel(bt->rchild);
	}
}

void PostTravel(BTNode *bt)
{
	if(bt != NULL)
	{
		PostTravel(bt->lchild);
		PostTravel(bt->rchild);
		printf("%c",bt->data);
	}
}

int NodesCount(BTNode *bt)
{
	if(bt == NULL)
		return 0;
	else
		return NodesCount(bt->lchild)
		+ NodesCount(bt->rchild) + 1;
}

void DispLeaf(BTNode *bt)
{		
	if(bt != NULL)
	{
		if(bt->lchild == NULL
		&& bt->rchild == NULL)
		{
			printf("%c\t",bt->data);
		}
		else
		{
			DispLeaf(bt->lchild);
			DispLeaf(bt->rchild);
		}
	}
}

int Level(BTNode *bt, ElemType find_data, int height)
{
	if(bt == NULL)
	{
		return 0;
	}
	else if(bt->data == find_data)
	{
		return height;
	}
	else
	{
		int height2 = Level(bt->lchild,find_data,height+1);
		if(height2 != 0)
			return height2;
		else
			return (Level(bt->rchild,find_data,height+1));
	}
}

//层级结点数计算 --> 重点在于层级
void LevelNodesCount(BTNode *bt, int height_now, int height_goal
, int &count)
{
	if(bt == NULL)
	{
		return ;
	}
	else
	{
		if(height_now == height_goal)
		{
			count++;
		}
		else if(height_now < height_goal)
		{
			LevelNodesCount(bt->lchild, height_now+1
			, height_goal, count);
			LevelNodesCount(bt->rchild, height_now+1
			, height_goal, count);
		}
	}
}

bool BTreeLike(BTNode *bt1, BTNode *bt2)
{
	if(bt1 == NULL && bt2 == NULL)
	{
		return true;
	}
	else if(bt1 == NULL || bt2 == NULL)
	{
		return false;
	}
	else
	{
		bool like1 = BTreeLike(bt1->lchild, bt2->lchild);
		bool like2 = BTreeLike(bt1->rchild, bt2->rchild);
		return (like1 && like2);
	}
}

//输出祖先，那么如何判断祖先呢？祖先的定义、逆向思考：从子孙结点的定义出发
bool Ancestor(BTNode *bt, ElemType data)
{
	if(bt == NULL)
	{
		return false;
	}
	else if(bt->lchild != NULL && bt->lchild->data == data
	|| bt->rchild != NULL && bt->rchild->data == data)
	{
		printf("%c",bt->data);
		return true;
	}
	else if(Ancestor(bt->lchild, data) 
	|| Ancestor(bt->rchild, data))
	{
		printf("%c",bt->data);
		return true;
	}
	else
	{
		return false;
	}
}
