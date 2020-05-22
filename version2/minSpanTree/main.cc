#include"graph.h"

int main()
{
	int g[][MAXV] = {
	{  0, 28,IFN,IFN,IFN, 10,IFN},
	{ 28,  0, 16,IFN,IFN,IFN, 14},
	{IFN, 16,  0, 12,IFN,IFN,IFN},
	{IFN,IFN, 12,  0, 22,IFN, 18},
	{IFN,IFN,IFN, 22,  0, 25, 24},
	{ 10,IFN,IFN,IFN, 25,  0,IFN},
	{IFN, 14,IFN, 18, 24,IFN,  0}};
	MatGraph *G;
	create_matgraph(G, g);
	print_matgraph(G);
	printf("\n");
	printf("there is the minimal spanning tree of G:\n");
	Prim(G, 0);
	destroy_matgraph(G);
	return 0;
}
