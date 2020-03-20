#include"graph.h"

void Mat_to_List(MatGraph * MG, AdjGraph * &AG)
{
	int i, j;
	ArcNode *p;
	init_adjgraph(AG);
	for (i=0; i<MG->n; i++)
	{
		AG->adjlist[i].firstarc = NULL;
		for (j=MG->n-1; j>=0; j--)
			if (MG->edgs[i][j] != 0 && MG->edgs[i][j] != IFN)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = MG->edgs[i][j];
				p->nextarc = AG->adjlist[i].firstarc;
				AG->adjlist[i].firstarc = p;
			}
	}
	AG->n = MG->n;
	AG->e = MG->e;
}

void List_to_Mat(AdjGraph *AG, MatGraph * &MG)
{
	int i, j;
	ArcNode *p;
	init_matgraph(MG);
	for (i=0; i<AG->n; i++)
		for (j=0; j<AG->n; j++)
			if (i == j)
				MG->edgs[i][j] = 0;
			else
				MG->edgs[i][j] = IFN;
	for (i=0; i<AG->n; i++)
	{
		p = AG->adjlist[i].firstarc;
		while (p != NULL)
		{
			MG->edgs[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	MG->n = AG->n;
	MG->e = AG->e;
}

int visited[MAXV] = {0};
void DFS(AdjGraph *G, int v)
{
	ArcNode *p;
	printf("%2d", v);
	visited[v] = 1;
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void BFS(AdjGraph *G, int v)
{
	int qu[MAXV], front = -1, rear = -1;
	int visited[MAXV] = {0};
	ArcNode *p;
	printf("%2d", v);
	visited[v] = 1;
	rear = (rear + 1) % MAXV;
	qu[rear] = v;
	while (front < rear)
	{
		front = (front + 1) % MAXV;
		p = G->adjlist[qu[front]].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%2d", p->adjvex);
				rear = (rear + 1) % MAXV;
				qu[rear] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}
