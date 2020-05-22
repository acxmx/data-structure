#include"maze.h"

int main()
{
	int maze[][MazeSize+2] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}};
	AdjGraph *G;
	create_adjgraph(G, maze);
	Path path[100];
	DFS(G, 1, 1, 8, 8, path, -1);
	printf("there are a total %d maze path.\n", cnt);
	destroy_adjgraph(G);
	return 0;
}
