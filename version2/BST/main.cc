#include"bst.h"

int main()
{
	KeyType a[] = {19,98,10,20,40,15};
	BSTNode *bt = create_bst2(a, sizeof(a)/sizeof(KeyType));
	print_bst(bt);
	printf("\n");
	delete_bst2(&bt, 10);
	print_bst(bt);
	printf("\n");
	destroy_bst(bt);
	return 0;
}
