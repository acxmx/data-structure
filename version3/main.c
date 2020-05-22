#include "graph.h"

int main()
{
    double matrix[][MAXV] = {
    {0,1,0,1,0},
    {0,0,1,1,0},
    {0,0,0,1,1},
    {0,0,0,0,0},
    {1,0,0,1,0}
    };
    adjGraph *graph;
    create(&graph, *matrix, 5, 5);
    print(graph);
    destroy(graph);

    return 0;
}

