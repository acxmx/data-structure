#ifndef MAZE
#define MAZE

#include<cstdio>
#include<cstdlib>
#define MaxSize 100

//about queue
typedef struct
{
	int i, j;
	int pre;
}Box;

bool find_path(int, int, int, int, int [][10]);
void print_path(Box *, int);

#endif
