#include"hfman.h"
#include<ctime>

int main()
{
	HTNode hft[15];
	HCNode hfc[8];
	int i;
	char data;
	srand((unsigned)time(0));

	for(i=0,data='a'; i<8; i++,data++)
	{
		hft[i].data = data;
		hft[i].weight = rand()%10+1;
	}
	create_hftree(hft, 8);
	for (i=0; i<15; i++)
	{
		printf("%c\t%f\t%d\t%d\t%d\n", hft[i].data, hft[i].weight,
hft[i].parent, hft[i].lchild, hft[i].rchild);
	}
	create_hfcode(hft, hfc, 8);
	printf("HuffmanCodes:\n");
	for(i=0; i<8; i++){
		printf("%c:\t%s",
		hft[i].data, &hfc[i].code[hfc[i].start]);
		printf("\n");
	}
	return 0;
}
