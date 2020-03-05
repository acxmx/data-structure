#ifndef HUFFMAN
#define HUFFMAN

#include<cstdio>
#include<cstdlib>
#define MaxSize 100
#define CodeSize 10

typedef struct
{
	char data;
	double weight;
	int parent;
	int lchild, rchild;
}HuffmanTree;

typedef struct
{
	char code[CodeSize];
	int start;
	
}HuffmanCode;

void create_huffman_tree(HuffmanTree *, int);
void create_huffman_code(HuffmanTree *, HuffmanCode *, int);

#endif
