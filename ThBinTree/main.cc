#include"thread.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode *bt;
	create_btree(bt, str);
	print_btree(bt);
	printf("\n");
	BTNode *root = create_in_thread(bt);
	printf("print inorder thread btree:\n");
	print_in_thread(root);
//the leftest child have a left child after threading
//so, the destroying operation will dump
//	destroy_btree(bt);
	return 0;
}
