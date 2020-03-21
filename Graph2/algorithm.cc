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
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				qu[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}

void restore(int visited[], int n)
{
	int i;
	for (i=0; i<n; i++)
		visited[i] = 0;
}

void find_all_smppath(AdjGraph *G, int u, int v)
{
	int path[MAXV];
	dfs_smp(G, u, v, path, -1);
}

void dfs_smp(AdjGraph *G, int u, int v, int path[], int d)
{
	ArcNode *p;
	visited[u] = 1;
	path[++d] = u;
	if (u == v)
	{
		int i;
		for (i=0; i<=d; i++)
			printf("%2d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			dfs_smp(G, p->adjvex, v, path, d);
		p = p->nextarc;
	}
	visited[u] = 0;
}

void find_all_cycpath(AdjGraph *G, int k)
{
	int path[MAXV];
	dfs_cyc(G, k, k, path, -1);
}

void dfs_cyc(AdjGraph *G, int u, int v, int path[], int d)
{
	ArcNode *p;
	visited[u] = 1;
	path[++d] = u;
	p = G->adjlist[u].firstarc;
	while (p != NULL)
	{  // variable d is setting for undirected graph
		if (p->adjvex == v && d>1)
		{
			int i;
			for (i=0; i<=d; i++)
				printf("%2d", path[i]);
			printf("%2d\n", v);
		}
		if (visited[p->adjvex] == 0)
			dfs_cyc(G, p->adjvex, v, path, d);
		p = p->nextarc;
	}
	visited[u] = 0;
}

//the shortest path algorithm
void find_shortest_path(AdjGraph *G, int u, int v)
{
	QuNode qu[MAXV];
	int front = -1, rear = -1;
	int w;
	ArcNode *p;
	visited[u] = 1;
	rear++;
	qu[rear].data = u;
	qu[rear].parent = -1;
	while (front != rear)
	{
		front++;
		w = qu[front].data;
		if (w == v)
		{
			print_shortest_path(qu, front);
			return ;
		}
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				visited[p->adjvex] = 1;
				rear++;
				qu[rear].data = p->adjvex;
				qu[rear].parent = front;
			}
			p = p->nextarc;
		}
	}
}

void print_shortest_path(QuNode qu[], int front)
{
	int i = front, tmp, k;
	while (i != 0)
	{
		tmp = qu[i].parent;
		qu[i].parent = -1;
		i = tmp;
	}
	k = 0;
	while (k < MAXV)
	{
		if (qu[k].parent == -1)
			printf("%2d", qu[k].data);
		k++;
	}
	printf("\n");
}
