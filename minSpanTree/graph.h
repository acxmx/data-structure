#ifndef GRAPH
#define GRAPH

#include<cstdio>
#include<cstdlib>
#define MAXV 7
#define IFN 255

extern int visited[];

typedef char InfoType;

//adjacency matrix:
typedef struct
{
	int no;
	InfoType info;
}VexType;

typedef struct
{
	int edgs[MAXV][MAXV];
	int n, e;
	VexType vexs[MAXV];
}MatGraph;

void create_matgraph(MatGraph * &, int [][MAXV]);
void init_matgraph(MatGraph * &);
void destroy_matgraph(MatGraph *);
void print_matgraph(MatGraph *);

//adjacency list:
typedef struct node
{
	int adjvex;
	struct node *nextarc;
	int weight;
}ArcNode;

typedef struct
{
	InfoType info;
	ArcNode *firstarc;
}VexNode;

typedef struct
{
	VexNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void create_adjgraph(AdjGraph * &, int [][MAXV]);
void init_adjgraph(AdjGraph * &);
void destroy_adjgraph(AdjGraph *);
void print_adjgraph(AdjGraph *);

//algorithm
void Mat_to_List(MatGraph *, AdjGraph *&);
void List_to_Mat(AdjGraph *, MatGraph *&);

void DFS(AdjGraph *, int);
void BFS(AdjGraph *, int);
void restore(int [], int n);

//find all simple path without regard to cycle path
void find_all_smppath(AdjGraph *, int, int);
void dfs_smp(AdjGraph *, int, int, int [], int);
//find all simple cycle path
void find_all_cycpath(AdjGraph *, int);
void dfs_cyc(AdjGraph *, int, int, int [], int);

//find shortest path algorithm
typedef struct
{
	int data;
	int parent;
}QuNode;
void find_shortest_path(AdjGraph *, int, int);
void print_shortest_path(QuNode [], int);

//find farthest vertex
int find_farthest_vertex(AdjGraph *, int);

void Prim(MatGraph *, int);

#endif
