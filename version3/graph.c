#include"graph.h"

void create(adjGraph * *graph, double *matrix, int rows, int cols)
{
    int row, col, i;

    if (matrix == NULL)
    {
        *graph = NULL;
        return ;
    }
    
    *graph = (adjGraph *) malloc (sizeof(adjGraph));
    for (i = 0; i < MAXV; ++i)
        (*graph)->vertexs[i].firstArc = NULL;
    (*graph)->vex_count = 0;
    (*graph)->arc_count = 0;

    for (row = 0; row < rows; ++row)
    {
        for (col = 0; col < cols; ++col)
        {
            double weight = matrix[row*cols + col];
            if (weight != 0 && weight != IFN)
            {
                add((*graph)->vertexs+row, col, weight);
                (*graph)->arc_count++;
            }
        }
        (*graph)->vex_count++;
    }
}

void add(vexNode *vexHead, int vex, double weight)
{
    arcNode *node = (arcNode *)malloc(sizeof(arcNode));
    node->adjVertex = vex;
    node->weight = weight;
    node->nextArc = vexHead->firstArc;
    vexHead->firstArc = node;
}

void print(adjGraph *graph)
{
    int i;
    arcNode *pNode;

    if (graph == NULL)
        return ;

    for (i = 0; i < graph->vex_count; ++i)
    {
        pNode = graph->vertexs[i].firstArc;
        printf("%3d: ", i);
        while (pNode != NULL)
        {
            printf("%3d[%f]->", pNode->adjVertex, pNode->weight);
            pNode = pNode->nextArc;
        }
        printf("/\\\n");
    }
}

void destroy(adjGraph *graph)
{
    arcNode *pPre, *pNode;
    int i;
    for (i = 0; i < graph->vex_count; ++i)
    {
        pPre = graph->vertexs[i].firstArc;
        if (pPre != NULL)
        {
            pNode = pPre->nextArc;
            while (pNode != NULL)
            {
                free(pPre);
                pPre = pNode;
                pNode = pNode->nextArc;
            }
            free(pPre);
        }
    }
    free(graph);
}
