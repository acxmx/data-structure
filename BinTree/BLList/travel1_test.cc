#include"BLList.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))", ch;
	BTNode *btree_p;
	int val;
	CreateBTree(btree_p,str);
	DispBTree(btree_p);
	printf("\n非递归前序遍历二叉树：\n");
	PreTravel2(btree_p);
	return 0;
}
