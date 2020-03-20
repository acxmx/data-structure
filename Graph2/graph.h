#ifndef GRAPH
#define GRAPH

#include<cstdio>
#include<cstdlib>
#define MAXV 5
#define IFN 255

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

#endif
