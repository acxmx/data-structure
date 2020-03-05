#ifndef GRAPH
#define GRAPH

#include<cstdio>
#include<cstdlib>
#define MAXV 5
#define IFN 32767

typedef char InfoType [21];

typedef struct node
{
	int adjvex;
	int weight;
	struct node *nextarc;
}ArcNode;

typedef struct
{
	InfoType info;  //vertex information
	ArcNode *firstarc;
}VexNode;

typedef struct
{
	VexNode adjlist[MAXV];
	int vex_n, edg_n;
}AdjGraph;

typedef struct
{
	int no;
	InfoType info;
}VertexType;

typedef struct
{
	int edges[MAXV][MAXV];
	int vertexs[MAXV];
	int vex_n, edg_n;
}MatGraph;

void CreateAdjGraph(AdjGraph * &, int [][MAXV], int, int);
void DestroyAdjGraph(AdjGraph *);
void DispAdjGraph(AdjGraph *);
void ListToMat(AdjGraph *, MatGraph);

#endif
