#include"huffmancode.h"

void create_huffman_tree(HuffmanTree *hft , int n0)
{
	int i, k, idx1, idx2;
	double wght1, wght2;
	for(i=0; i<2*n0-1; i++)
		hft[i].parent = hft[i].lchild = hft[i].rchild = -1;
	for(i=n0; i<2*n0-1; i++){
		idx1 = idx2 = -1;
		wght1 = wght2 = 32767;
		for(k=0; k<i; k++){
			if(hft[k].parent == -1){
				if(hft[k].weight < wght1){
					idx2 = idx1;
					wght2 = wght1;
					idx1 = k;
					wght1 = hft[k].weight;
				}else if(hft[k].weight < wght2){
					idx2 = k;
					wght2 = hft[k].weight;
				}
			}
		}
		hft[i].weight = hft[idx1].weight + hft[idx2].weight;
		hft[i].lchild = idx1; hft[i].rchild = idx2;
		hft[idx1].parent = i; hft[idx2].parent = i;
	}
}

void create_huffman_code(HuffmanTree *hft, HuffmanCode *hfc, int n0)
{
	int chd, prt, i;
	HuffmanCode cd;
	for(i=0; i<n0; i++){
		cd.start = n0;
		cd.code[n0+1] = '\0';
		chd = i;
		prt = hft[chd].parent;
		while(prt != -1){
			if(chd == hft[prt].lchild)
				cd.code[cd.start--] = '0';
			else
				cd.code[cd.start--] = '1';
			chd = prt;
			prt = hft[prt].parent;
		}
		cd.start++;
		hfc[i] = cd;
	}
}
