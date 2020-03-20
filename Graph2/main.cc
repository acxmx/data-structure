#include"graph.h"

int main()
{
	int g[MAXV][MAXV] = {
	{  0,  3,  6,IFN,IFN},
	{IFN,  0,  2,IFN,IFN},
	{IFN,IFN,  0,  1,  5},
	{IFN,IFN,IFN,  0,  3},
	{  4,IFN,IFN,IFN,  0}};
	AdjGraph *AG;
	create_adjgraph(AG, g);
	print_adjgraph(AG);
	DFS(AG, 0);
	printf("\n");
	BFS(AG, 0);
//	MatGraph *MG;
//	create_matgraph(MG, g);
//	print_matgraph(MG);
//	Mat_to_List(MG, AG);
//	List_to_Mat(AG, MG);
//	print_matgraph(MG);
//	destroy_matgraph(MG);
	destroy_adjgraph(AG);
	return 0;
}
