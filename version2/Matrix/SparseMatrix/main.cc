#include"sparse.h"

int main()
{
	int A[][N] = {
	{1,0,3,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,1,1}};
	SPMatrix t;
	create_matrix(&t, A);
	print_matrix(&t);
	return 0;
}
