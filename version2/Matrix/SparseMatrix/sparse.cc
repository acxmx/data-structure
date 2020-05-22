#include"sparse.h"

void create_matrix(SPMatrix *t, int A[M][N])
{
	int i, j;
	t->rows = M;
	t->cols = N;
	t->nums = 0;
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			if (A[i][j] != 0)
			{
				t->data[t->nums].r = i;
				t->data[t->nums].c = j;
				t->data[t->nums].d = A[i][j];
				t->nums++;
			}
}

bool modify(SPMatrix *t, ElemType x, int i, int j)
{
	int k = 0, k1;
	if (i >= t->rows || j >= t->cols)
		return false;
	while (k < t->nums && i > t->data[k].r) k++;
	while (k < t->nums && i == t->data[k].r
		&& j > t->data[k].c) k++;
	if (t->data[k].r == i && t->data[k].c == j)
		t->data[k].d = x;
	else
	{
		for (k1 = t->nums-1; k1 >= k; k1--)
		{
			t->data[k1+1].r = t->data[k1].r;
			t->data[k1+1].c = t->data[k1].c;
			t->data[k1+1].d = t->data[k1].d;
		}
		t->data[k].r = i;
		t->data[k].c = j;
		t->data[k].d = x;
		t->nums++;
	}
	return true;
}

bool assign(SPMatrix *t, int i, int j, ElemType *p)
{
	int k = 0;
	if (i >= t->rows || j >= t->cols)
		return false;
	while (k < t->nums && i > t->data[k].r) k++;
	while (k < t->nums && i == t->data[k].r
		&& j > t->data[k].c) k++;
	if (t->data[k].r == i && t->data[k].c == j)
		*p = t->data[k].d;
	else
		*p = 0;
	return true;
}

void print_matrix(SPMatrix *t)
{
	int k;
	if (t->nums <= 0)
		return ;
	printf("\t%d\t%d\t%d\n", t->rows, t->cols, t->nums);
	for (k=0; k < t->nums; k++)
		printf("\t%d\t%d\t%d\n", t->data[k].r, t->data[k].c,
			t->data[k].d);
}
