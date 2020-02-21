#include"maze.h"

int maze[ROW+2][COLM+2] = 
{ {1,1,1,1,1,1,1,1,1,1} , {1,0,0,1,0,0,0,1,0,1},
  {1,0,0,1,0,0,0,1,0,1} , {1,0,0,0,0,1,1,0,0,1},
  {1,0,1,1,1,0,0,0,0,1} , {1,0,0,0,1,0,0,0,0,1},
  {1,0,1,0,0,0,1,0,0,1} , {1,0,1,1,1,0,1,1,0,1},
  {1,1,0,0,0,0,0,0,0,1} , {1,1,1,1,1,1,1,1,1,1}};

void InitStack(SqStack * &stack_p)
{
	stack_p = (SqStack *)malloc(sizeof(SqStack));
	stack_p->top = -1;
}

void DestroyStack(SqStack * &stack_p)
{
	free(stack_p);
}

bool StackEmpty(SqStack *stack_p)
{
	return (stack_p->top == -1);
}

bool Push(SqStack * &stack_p , Box box)
{
	if(stack_p->top == MaxSize-1)
		return false;
	stack_p->top++;
	stack_p->data[stack_p->top] = box;
	return true;
}

bool Pop(SqStack * &stack_p , Box &box)
{
	if(StackEmpty(stack_p))
		return false;
	box = stack_p->data[stack_p->top];
	stack_p->top--;
	return true;
}

bool GetTop(SqStack *stack_p , Box &box)
{
	if(StackEmpty(stack_p))
		return false;
	box = stack_p->data[stack_p->top];
	return true;
}

bool find_maze_path(int row_en , int colm_en , int row_ex , int colm_ex)
{
	Box path[MaxSize] , box;
	int row_num1 , colm_num1 , row_num2 , colm_num2 , flag_next_box ,
	index;
	bool find;	
	SqStack *stack_p;
	InitStack(stack_p);
	box.row_num = row_en;
	box.colm_num = colm_en;
	box.flag_next_box = -1;
	Push(stack_p , box);
	maze[row_en][colm_en] = -1;
	while(!StackEmpty(stack_p))
	{
		GetTop(stack_p , box);
		row_num1 = box.row_num;
		colm_num1 = box.colm_num;
		flag_next_box = box.flag_next_box;
		if(row_num1 == row_ex && colm_num1 == colm_ex)
		{
			index = 0;
			while(!StackEmpty(stack_p))
			{
				Pop(stack_p , box);
				path[index] = box;
				index++;
			}
			index--;
			printf("解决迷宫问题的路径之一如下:\n");
			while(index >= 0)
			{
				printf("\t(%d , %d)" ,
				path[index].row_num  , 
				path[index].colm_num);
				if((index+2)%5 == 0)	printf("\n");
				index--;
			}
			DestroyStack(stack_p);
			return true;
		}
		find = false;
		while(flag_next_box < 4 && !find)
		{
			flag_next_box++;
			switch(flag_next_box)
			{
				case 0:
				row_num2 = row_num1 - 1;
				colm_num2 = colm_num1;
				break;
				case 1:
				row_num2 = row_num1;
				colm_num2 = colm_num1 + 1;
				break;
				case 2:
				row_num2 = row_num1 + 1;
				colm_num2 = colm_num1;
				break;
				case 3:
				row_num2 = row_num1;
				colm_num2 = colm_num1 - 1;
				break;
			}
			if(maze[row_num2][colm_num2] == 0)
				find = true;
		}
		if(find)
		{
			stack_p->data[stack_p->top].flag_next_box
			= flag_next_box;
			box.row_num = row_num2;
			box.colm_num = colm_num2;
			box.flag_next_box = -1;
			Push(stack_p , box);
			maze[row_num2][colm_num2] = -1;
		}
		else
		{
			Pop(stack_p , box);
			maze[box.row_num][box.colm_num] = 0;
		}
	}
	DestroyStack(stack_p);
	return false;
}
