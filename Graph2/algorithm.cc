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
