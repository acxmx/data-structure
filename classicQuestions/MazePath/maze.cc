#include"maze.h"

bool find_path(int xi, int yi, int xe, int ye, int maze [][10])
{
	Box path[MaxSize], box;
	int i, j, di, i1, j1;
	int front = -1, rear = -1;
	box.i = xi;
	box.j = yi;
	box.pre = -1;
	path[++rear] = box;
	maze[xi][yi] = -1;
	while (front != rear)
	{
		box = path[++front];
		i = box.i;
		j = box.j;
		if (i == xe && j == ye)
		{
			print_path(path, front);
			return true;
		}
		for (di=0; di<4; di++)
		{
			switch (di)
			{
			case 0:
			i1 = i-1; j1 = j; break;
			case 1:
			i1 = i; j1 = j+1; break;
			case 2:
			i1 = i+1; j1 = j; break;
			case 3:
			i1 = i; j1 = j-1; break;
			}
			if (maze[i1][j1] == 0)
			{
				box.i = i1;
				box.j = j1;
				box.pre = front;
				path[++rear] = box;
				maze[i1][j1] = -1;
			}
		}
	}
	return false;
}

void print_path(Box *path, int front)
{
	int i = front, tmp, cnt = 0;
	printf("\n");
	while (i != 0)
	{
		tmp = path[i].pre;
		path[i].pre = -1;
		i = tmp;
	}
	printf("a maze path:\n");
	i = 0;
	while (i < MaxSize)
	{
		if (path[i].pre == -1)
		{
			cnt++;
			printf("\t(%d,%d)", path[i].i, path[i].j);
			if (cnt % 5 == 0)
				printf("\n");
		}
		i++;
	}
	printf("\n");
}
