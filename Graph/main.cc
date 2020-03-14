#include"graph.h"

int main()
{
	int A [][MAXV] = {{0,   8, IFN,   5, IFN},
			{IFN,   0,   3, IFN, IFN},
			{IFN, IFN,   0, IFN,   6},
			{IFN, IFN,   9,   0, IFN},
			{IFN, IFN, IFN, IFN,   0}};
	AdjGraph *G;
	MatGraph mtg;
	int i, j;
	CreateAdjGraph(G, A, 5, 5);
	DispAdjGraph(G);
	ListToMat(G, mtg);
	for(i=0; i<MAXV; i++){
		for(j=0; j<MAXV; j++)
			printf("%6d", mtg.edges[i][j]);
		printf("\n");
	}
	printf("以0为起始点对图进行DFS，输出如下：\n");
	DFS(G, 0);
	printf("\n");
	printf("以0为起始点对图进行BFS，输出如下:\n");
	BFS(G, 0);
	int path[MAXV];
	printf("\n");
	find_all_path(G,0,4,path,-1);
	DestroyAdjGraph(G);
	return 0;
}
