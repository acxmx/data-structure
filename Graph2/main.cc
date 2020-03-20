#include"graph.h"

int main()
{
	int g[MAXV][MAXV] = {
	{  0,  8,IFN,  5,IFN},
	{IFN,  0,  3,IFN,IFN},
	{IFN,IFN,  0,IFN,  6},
	{IFN,IFN,  9,  0,IFN},
	{IFN,IFN,IFN,IFN,  0}};
	MatGraph *MG;
	AdjGraph *AG;
//	create_matgraph(MG, g);
//	print_matgraph(MG);
	create_adjgraph(AG, g);
//	Mat_to_List(MG, AG);
	List_to_Mat(AG, MG);
	print_adjgraph(AG);
	print_matgraph(MG);
	destroy_adjgraph(AG);
	destroy_matgraph(MG);
	return 0;
}
