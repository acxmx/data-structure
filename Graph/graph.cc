#include"graph.h"

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
