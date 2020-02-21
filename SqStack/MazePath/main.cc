#include"maze.h"

int main()
{
	if(!find_maze_path(1,1,ROW,COLM))
		printf("此迷宫问题无解！\n");
	return 0;
}
