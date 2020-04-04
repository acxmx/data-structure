#include"graph.h"

void Prim(MatGraph *G, int v)
{
	int lowcost[MAXV];
	int closest[MAXV];
	int i, j, k, MIN;
	for (i=0; i<G->n; i++)
	{
		lowcost[i] = G->edgs[v][i];
		closest[i] = v;
	}
	for (i=1; i<G->n; i++)
	{
		MIN = IFN;
		for (j=0; j<G->n; j++)
			if (lowcost[j] != 0 && lowcost[j] < MIN)
			{
				MIN = lowcost[j];
				k = j;
			}
		printf("the weight of edge(%d,%d) is %d.\n",
		closest[k], k, lowcost[k]);
		for (j=0; j<G->n; j++)
			if (lowcost[j] != 0 && G->edgs[k][j] < lowcost[j])
			{
				lowcost[j] = G->edgs[k][j];
				closest[j] = k;
			}
	}
}
