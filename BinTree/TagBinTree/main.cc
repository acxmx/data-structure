#include"TagBLList.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))";
	TagBTNode *btree_p, *root;
	CreateTagBTree(btree_p, str);
	DispTagBTree(btree_p);
	printf("\n");
	root = CreateThread(btree_p);
	printf("创建线索二叉树并输出:\n");
	ThreadInTravel(root);
	printf("\n");
	return 0;
}
