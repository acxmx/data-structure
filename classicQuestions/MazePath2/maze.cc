#include"maze.h"

void create_adjgraph(AdjGraph * &G, int maze[][MazeSize+2])
{
	int i, j;
	init_adjgraph(G);
	for (i=0; i<MazeSize+2; i++)
		for (j=0; j<MazeSize+2; j++)
			if (maze[i][j] == 1)
			{
				G->adjlist[i][j].firstarc = NULL;
			}
			else
			{
				create_arclist(G, i, j, maze);
			}
}

void create_arclist(AdjGraph *G, int i, int j, int maze[][MazeSize+2])
{
	int i1, j1, d;
	ArcNode *p;
	G->adjlist[i][j].firstarc = NULL;
//	VexNode *head = &G->adjlist[i][j];
	for (d=0; d<4; d++)
	{
		switch (d)
		{
		case 0: i1=i;j1=j-1;break;
		case 1: i1=i+1;j1=j;break;
		case 2: i1=i;j1=j+1;break;
		case 3: i1=i-1;j1=j;break;
		}
		if (maze[i1][j1] == 0)
		{
			p = (ArcNode *)malloc(sizeof(ArcNode));
			p->i = i1;
			p->j = j1;
			p->nextarc = G->adjlist[i][j].firstarc;
			G->adjlist[i][j].firstarc = p;
		}
	}
}

void init_adjgraph(AdjGraph * &G)
{
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
}

void destroy_adjgraph(AdjGraph *G)
{
	int i, j;
	ArcNode *pre, *p;
	for (i=0; i<MazeSize; i++)
		for (j=0; j<MazeSize; j++)
		{
			pre = G->adjlist[i][j].firstarc;
			if (pre != NULL)
			{
				p = pre->nextarc;
				while (p != NULL)
				{
					free(pre);
					pre = p;
					p = p->nextarc;
				}
				free(pre);
			}
		}
	free(G);
}

int visited[MazeSize+2][MazeSize+2] = {0};

void DFS(AdjGraph *G, int xi, int yi, int xe, int ye, Path path[], int d)
{
	ArcNode *p;
	visited[xi][yi] = 1;
	d++;
	path[d].i = xi;
	path[d].j = yi;
	if (xi == xe && yi == ye)
	{
		int i;
		printf("a maze path:\n");
		for (i=0; i<=d; i++)
		{
			if (i > 0 && i % 5 == 0)
				printf("\n");
			printf("(%d,%d)\t", path[i].i, path[i].j);
		}
		return ;
	}
	p = G->adjlist[xi][yi].firstarc;
	while (p != NULL)
	{
		if (visited[p->i][p->j] == 0)
			DFS(G, p->i, p->j, xe, ye, path, d);
		p = p->nextarc;
	}
}
