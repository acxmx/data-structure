#ifndef GRAPH
#define GRAPH

#include<stdio.h>
#include<stdlib.h>

#define MAXV 5
#define IFN 65535

typedef struct node
{
    int adjVertex;
    double weight;
    struct node *nextArc;
}arcNode;

typedef struct
{
    arcNode *firstArc;
}vexNode;

typedef struct
{
    vexNode vertexs[MAXV];
    int vex_count;
    int arc_count;
}adjGraph;

void create(adjGraph * *, double *, int, int);
void add(vexNode *, int, double);
void print(adjGraph *);
void destroy(adjGraph *);

#endif
