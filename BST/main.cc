#include"bst.h"

int main()
{
	KeyType a[] = {19,98,10,20,40,15};
	BSTNode *bt = create_bst(a, sizeof(a)/sizeof(KeyType));
	print_bst(bt);
	printf("\n");
	delete_bst(bt, 30);
	print_bst(bt);
	printf("\n");
	destroy_bst(bt);
	return 0;
}
