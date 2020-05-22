#include"hfman.h"

void create_hftree(HTNode hft[], int n0)
{
	const int IFN = 32767;
	int idx1, idx2, i, j;
	double wgt1, wgt2;
	for (i=0; i<2*n0-1; i++)
		hft[i].parent = hft[i].lchild = hft[i].rchild = -1;
	for (i=n0; i<2*n0-1; i++)
	{
		idx1 = idx2 = -1;
		wgt1 = wgt2 = IFN;
		for (j=0; j<i; j++)
		{
			if (hft[j].parent == -1)
			{
				if (hft[j].weight < wgt1)
				{
					wgt2 = wgt1;
					idx2 = idx1;
					wgt1 = hft[j].weight;
					idx1 = j;
				}else if (hft[j].weight < wgt2)
				{
					wgt2 = hft[j].weight;
					idx2 = j;
				}
			}
		}
		hft[i].weight = wgt1 + wgt2;
		hft[i].lchild = idx1;
		hft[i].rchild = idx2;
		hft[idx1].parent = i;
		hft[idx2].parent = i;
	}
}

void create_hfcode(HTNode hft[], HCNode hfc[], int n0)
{
	int chd, prt, i;
	HCNode cd;
	for (i=0; i<n0; i++)
	{
		chd = i;
		prt = hft[chd].parent;
		cd.start = n0-2;
		cd.code[n0-1] = '\0';
		while (prt != -1)
		{
			if (chd == hft[prt].lchild)
				cd.code[cd.start--] = '0';
			else	
				cd.code[cd.start--] = '1';
			chd = prt;
			prt = hft[chd].parent;
		}
		cd.start++;
		hfc[i] = cd;
	}
}
