#include"TagBLList.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))";
	TagBTNode *btree_p, *root1, *root2;
	CreateTagBTree(btree_p, str);
	DispTagBTree(btree_p);
	printf("\n");
#if 0
	root1 = CreateInThread(btree_p);
	printf("创建中序线索二叉树并输出：\n");
	InThreadTravel(root1);
	printf("\n");
#endif
	root2 = CreatePreThread(btree_p);
	printf("创建前序线索二叉树并输出：\n");
	PreThreadTravel(root2);
	printf("\n");
	return 0;
}
