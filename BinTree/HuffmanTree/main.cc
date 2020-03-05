#include"huffmancode.h"
#include<ctime>

int main()
{
	HuffmanTree hft[15];
	HuffmanCode hfc[8];
	int i;
	char data;
	srand((unsigned)time(0));

	for(i=0,data='a'; i<8; i++,data++){
		hft[i].data = data;
		hft[i].weight = rand()%10+1;
	}
	create_huffman_tree(hft, 8);
	create_huffman_code(hft, hfc, 8);
	printf("HuffmanCodes:\n");
	for(i=0; i<8; i++){
		printf("%c:\t%s",
		hft[i].data, &hfc[i].code[hfc[i].start]);
		printf("\n");
	}
	return 0;
}
