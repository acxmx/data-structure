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
	printf("DFS:\n");
	DFS(AG, 0);
	printf("\n");
	printf("BFS:\n");
	BFS(AG, 0);
	restore(visited, MAXV);
	printf("find all simple path(from 0 to 3):\n");
	find_all_smppath(AG, 0, 3);
	restore(visited, MAXV);
	printf("find all cycle path for 0:\n");
	find_all_cycpath(AG,0);
	restore(visited, MAXV);
	printf("the shortest path fromt 2 to 4 is :\n");
	find_shortest_path(AG, 2, 4);
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
