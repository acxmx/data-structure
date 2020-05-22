#include"btree.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode *bt;
	int n = 0;
	create_btree(bt, str);
	printf("\n");
	print_btree(bt);
	printf("\n");
	printf("tree height:%d\n", btree_height(bt));
	printf("postorder travel:\n");	
	post_travel(bt);
	printf("\n");
	printf("inorder travel:\n");
	in_travel1(bt);
	printf("preorder travel:\n");
	pre_travel2(bt);
	printf("postorder travel:\n");
	post_travel1(bt);
	printf("level travel:\n");
	level_travel(bt);
	printf("leaf:\n");
	print_leaf(bt);
	printf("\n");
	printf("D in level %d\n", count_node_level(bt, 1, 'D'));
	count_node_levelk(bt, 1, 3, n);
	printf("level 3 has %d nodes\n", n);
	printf("ancestors of node 'G':\n");
	print_ancestor(bt, 'G');
	printf("\n");
	printf("leaf to root:\n");
	print_reverse_path(bt);
	destroy_btree(bt);
	return 0;
}
