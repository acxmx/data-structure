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

int visited[MAXV];

void dfs(adjGraph *graph, int start)
{
    arcNode *pNode = NULL;
    
    printf("%d->", start);
    visited[start] = 1;
    pNode = graph->vertexs[start].firstArc;

    while (pNode != NULL)
    {
        int nextVex = pNode->adjVertex;
        if (visited[nextVex] == 0)
            dfs(graph, nextVex);
        pNode = pNode->nextArc;
    }
}

void bfs(adjGraph *graph, int start)
{
    int i;
    int visited[MAXV];
    queue<int> myQueue;
    for (i = 0; i < graph->vex_count; ++i)
        visited[i] = 0;
    printf("%d->", start);
    visited[start] = 1;
    myQueue.push(start);

    while (!myQueue.empty())
    {
        int frontVex = myQueue.front();
        myQueue.pop();
        arcNode *pNode = graph->vertexs[frontVex].firstArc;

        while (pNode != NULL)
        {
            int adjVex = pNode->adjVertex;
            if (visited[adjVex] == 0)
            {
                printf("%d->", adjVex);
                visited[adjVex] = 1;
                myQueue.push(adjVex);
            }
            pNode = pNode->nextArc;
        }
    }
}
