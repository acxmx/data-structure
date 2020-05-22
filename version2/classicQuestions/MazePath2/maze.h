#ifndef MAZE
#define MAZE

#include<cstdio>
#include<cstdlib>

#define MazeSize 8

extern int visited[][MazeSize+2];
extern int cnt;

typedef struct node
{
	int i, j;
	struct node *nextarc;
}ArcNode;

typedef struct
{
	ArcNode *firstarc;
}VexNode;

typedef struct
{
	VexNode adjlist[MazeSize+2][MazeSize+2];
}AdjGraph;

void create_adjgraph(AdjGraph * &, int [][MazeSize+2]);
void create_arclist(AdjGraph *, int, int, int[][MazeSize+2]);
void init_adjgraph(AdjGraph * &);
void destroy_adjgraph(AdjGraph *);

typedef struct
{
	int i, j;
}Path;
void DFS(AdjGraph *, int, int, int, int, Path [], int);
void BFS(AdjGraph *, int, int, int, int);

#endif
