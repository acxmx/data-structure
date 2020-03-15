#include"lklist.h"

int main()
{
	LinkNode *L;
	int i, e, a[] = {19,98,10,20,40,44,10,15}, b[2];
	create_listR(L, a, sizeof(a)/sizeof(int));
	print_list(L);
	delmaxnode(L);
	print_list(L);
	sort(L);
	print_list(L);
	destroy_list(L);
	return 0;
}
