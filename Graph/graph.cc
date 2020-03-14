#include"graph.h"

int visited[MAXV] = {0};
int visited2[MAXV] = {0};

void CreateAdjGraph(AdjGraph * &AG, int A[][MAXV], int vex_n, int edg_n)
{
	int i, j;
	ArcNode *p;
	AG = (AdjGraph *)malloc(sizeof(AdjGraph));
	for(i=0; i<vex_n; i++)
		AG->adjlist[i].firstarc = NULL;
	for(i=0; i<vex_n; i++)
		for(j=vex_n-1; j>=0; j--)
			if(A[i][j] != 0 && A[i][j] != IFN)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = AG->adjlist[i].firstarc;
				AG->adjlist[i].firstarc = p;
			}
	AG->vex_n = vex_n;
	AG->edg_n = edg_n;
}

void DestroyAdjGraph(AdjGraph *AG)
{
	int i;
	ArcNode *pre, *p;
	for(i=0; i<AG->vex_n; i++)
	{
		pre = AG->adjlist[i].firstarc;
		if(pre != NULL)
		{
			p = pre->nextarc;
			while(p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(AG);
}

void DispAdjGraph(AdjGraph *AG)
{
	int i;
	ArcNode *p;
	for(i=0; i<AG->vex_n; i++)
	{
		p = AG->adjlist[i].firstarc;
		printf("%3d:\t", i);
		while(p != NULL)
		{
			printf("%3d[%3d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("/\\\n");
	}
}

void ListToMat(AdjGraph *adg, MatGraph &mtg)
{
	int i, j;
	ArcNode *p;
	for(i=0; i<adg->vex_n; i++){
		for(j=0; j<adg->vex_n; j++)
			mtg.edges[i][j] = IFN;
		p = adg->adjlist[i].firstarc;
		while(p != NULL){
			mtg.edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
		mtg.edges[i][i] = 0;
	}
	mtg.vex_n = adg->vex_n;
	mtg.edg_n = adg->edg_n;
}

void DFS(AdjGraph *G, int v)
{
	ArcNode *p;
	printf("%3d", v);
	visited[v] = 1;
	p = G->adjlist[v].firstarc;
	while(p != NULL){
		if(visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void BFS(AdjGraph *G, int v)
{
	int w, i, visited[MAXV];
	ArcNode *p;
	SqQueue *qu;
	InitQueue(qu);
	for(i=0; i<G->vex_n; i++) visited[i] = 0;

	printf("%3d", v);
	visited[v] = 1;
	enQueue(qu, v);

	while(! QueueEmpty(qu)){
		deQueue(qu, w);
		p = G->adjlist[w].firstarc;
		while(p != NULL){
			if(visited[p->adjvex] == 0){
				printf("%3d", p->adjvex);
				visited[p->adjvex] = 1;
				enQueue(qu, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	printf("\n");
	DestroyQueue(qu);
}

void InitQueue(SqQueue * &qu)
{
	qu = (SqQueue *)malloc(sizeof(SqQueue));
	qu->front = qu->rear = -1;
}

void DestroyQueue(SqQueue *qu)
{
	free(qu);
}

bool enQueue(SqQueue *qu, int v)
{
	if( (qu->rear + 1) % MAXV == qu->front)
		return false;
	qu->rear = (qu->rear + 1) % MAXV;
	qu->data[qu->rear] = v;
	return true;
}

bool deQueue(SqQueue *qu, int &v)
{
	if((qu->rear + 1) % MAXV == qu->front)
		return false;
	qu->front = (qu->front + 1) % MAXV;
	v = qu->data[qu->front];
	return true;
}

bool QueueEmpty(SqQueue *qu)
{
	return (qu->front == qu->rear);
}

//Algorithms
void find_all_path(AdjGraph *G, int u, int v, int path[], int d)
{
	ArcNode *p;
	path[++d] = u;
	visited2[u] = 1;
	if(u == v)
	{
		int i;
		for(i=0; i<=d; i++)
			printf("%2d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc;
	while(p != NULL)
	{
		if(visited2[p->adjvex] == 0)
			find_all_path(G,p->adjvex,v,path,d);
		p = p->nextarc;
	}
	visited2[u] = 0;
}
