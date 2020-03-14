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
}VexType;

typedef struct
{
	int edges[MAXV][MAXV];
	VexType vexs[MAXV];
	int vex_n, edg_n;
}MatGraph;

void CreateAdjGraph(AdjGraph * &, int [][MAXV], int, int);
void DestroyAdjGraph(AdjGraph *);
void DispAdjGraph(AdjGraph *);
void ListToMat(AdjGraph *, MatGraph &);

void DFS(AdjGraph *, int);
void BFS(AdjGraph *, int);

typedef struct
{
	int data[MAXV];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue * &);
void DestroyQueue(SqQueue *);
bool enQueue(SqQueue *, int);
bool deQueue(SqQueue *, int &);
bool QueueEmpty(SqQueue *);

//Algorithms
void cycle_dfs(AdjGraph *, int, int, int *, int);
void find_all_path(AdjGraph *, int, int, int *, int);
void find_all_cycle(AdjGraph *, int);

#endif
