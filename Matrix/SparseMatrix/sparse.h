#ifndef SPARSE
#define SPARSE

#include<cstdio>
#include<cstdlib>

#define M 4
#define N 4
#define MaxSize 16

typedef int ElemType;

typedef struct
{
	int r;
	int c;
	ElemType d;
}TupNode;
typedef struct
{
	int rows;
	int cols;
	int nums;
	TupNode data [MaxSize];
}SPMatrix;

//basic operation
void create_matrix(SPMatrix *, int [][N]);
bool modify(SPMatrix *, ElemType, int, int);
bool assign(SPMatrix *, int, int, ElemType *);
void print_matrix(SPMatrix *);
void transpose(SPMatrix *, SPMatrix *);

#endif
