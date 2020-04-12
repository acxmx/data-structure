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

void bin_sort(int *arr, int n, bool (*fp) (int, int ))
{
	int i, j, low, mid, high, tmp;
	for (i = 1; i < n; i++)
		if (fp(*(arr+i), *(arr+i-1)))
		{
			tmp = *(arr+i);
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (fp(tmp, *(arr + mid))) 
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i-1; j >= high+1; j--)
				*(arr + j + 1) = *(arr + j);
			*(arr + high + 1) = tmp;
		}
}

void shell_sort(int *arr, int n, bool (*fp) (int, int))
{
	int i, j, d, tmp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			tmp = *(arr+i);
			j = i-d;
			while (j >= 0 && fp(tmp, *(arr+j)))
			{
				*(arr+j+d) = *(arr+j);
				j -= d;
			}
			*(arr+j+d) = tmp;
		}
		d /= 2;
	}
}

void bubble_sort(int *arr, int n, bool (*fp) (int, int))
{
	int i, j;
	bool exchange;
	for (i = 0; i < n-1; i++)
	{
		exchange = false;
		for (j = n-1; j > i; j--)
			if (fp(*(arr+j), *(arr+j-1)))
			{
				swap(arr, j, j-1);
				exchange = true;
			}
		if (!exchange)
			return ;
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

void swap(int *arr, int i, int j)
{
	int tmp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = tmp;
}
