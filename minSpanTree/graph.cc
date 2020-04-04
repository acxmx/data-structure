#include"graph.h"

//adjacency matrix:
void create_matgraph(MatGraph * &G, int g[MAXV][MAXV])
{
	int i, j;
	init_matgraph(G);
	for (i=0; i<MAXV; i++)
	{
		G->vexs[i].no = i;
		for (j=0; j<MAXV; j++)
		{
			G->edgs[i][j] = g[i][j];
			if (g[i][j]>0 && g[i][j]<IFN )
				G->e++;
		}

	}
	G->n = MAXV;
}

void init_matgraph(MatGraph * &G)
{
	G = (MatGraph *)malloc(sizeof(MatGraph));
	G->n = G->e = 0;
}

void destroy_matgraph(MatGraph *G)
{
	free(G);
}

void print_matgraph(MatGraph *G)
{
	int i, j;
	printf("%-5c", '\0');
	for (i=0; i<G->n; i++)
		printf("%-5d", i);
	printf("\n");
	for (i=0; i<G->n; i++)
	{
		printf("%-4d", i);
		for(j=0; j<G->n; j++ )
			printf("%-5d", G->edgs[i][j]);
		printf("\n");
	}
	printf("\n");
}

//adjacency list:
void create_adjgraph(AdjGraph * &G, int g[][MAXV])
{
	int i, j;
	ArcNode *p;
	init_adjgraph(G);
	for (i=0; i<MAXV; i++)
	{
		G->adjlist[i].firstarc = NULL;
		for (j=MAXV-1; j>=0; j--)
		{
			if (g[i][j] != 0 && g[i][j] != IFN)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = g[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
				G->e++;
			}
		}
	}
	G->n = MAXV;
}

void init_adjgraph(AdjGraph * &G)
{
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	G->n = G->e = 0;
}

void destroy_adjgraph(AdjGraph *G)
{
	ArcNode *pre, *p;
	int i;
	for (i=0; i<G->n; i++)
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}

void print_adjgraph(AdjGraph *G)
{
	int i;
	ArcNode *p;
	for (i=0; i<G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d:", i);
		while (p != NULL)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("/\\\n");
	}
}
