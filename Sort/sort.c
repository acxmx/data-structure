#include"sort.h"

void insert_sort(int *arr, int n, bool (*fp) (int, int))
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
		if (fp(*(arr+i), *(arr+i-1)))
		{
			tmp = *(arr+i);
			j = i - 1;
			do
			{
				*(arr+j+1) = *(arr+j);
				j--;
			}while (j >= 0 && fp(tmp, *(arr+j)));
			*(arr+j+1) = tmp;
		}
}

void print_arr(int *arr, int n)
{
	int i = 0;
	while (i < n)
		printf("%3d", *(arr+i++));
	printf("\n");
}

bool less_than(int a, int b)
{
	return (a < b);
}

bool greater_than(int a, int b)
{
	return (a > b);
}
