#include"graph.h"

int main()
{
	int A [][MAXV] = {{0,   8, IFN,   5, IFN},
			{IFN,   0,   3, IFN, IFN},
			{IFN, IFN,   0, IFN,   6},
			{IFN, IFN,   9,   0, IFN},
			{IFN, IFN, IFN, IFN,   0}};
	AdjGraph *AG;
	CreateAdjGraph(AG, A, 5, 5);
	DispAdjGraph(AG);
	DestroyAdjGraph(AG);
	return 0;
}
