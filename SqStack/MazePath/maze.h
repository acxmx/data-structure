#ifndef MAZE
#define MAZE
#include<cstdio>
#include<cstdlib>
#define MaxSize 100 //定义路径最大规模
#define ROW 8
#define COLM 8

extern int maze[][COLM+2];

typedef struct
{
	int row_num;
	int colm_num;
	int flag_next_box;
}Box;
typedef struct
{
	Box data[MaxSize];
	int top;	//栈顶指针
}SqStack;

void InitStack(SqStack * &);
void DestroyStack(SqStack * &);
bool StackEmpty(SqStack *);
bool Push(SqStack * &, Box);
bool Pop(SqStack * &, Box &);
bool find_maze_path(int, int, int, int);

#endif
