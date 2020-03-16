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
	printf("post travel:\n");	
	post_travel(bt);
	printf("\n");
	print_leaf(bt);
	printf("\n");
	printf("D in level %d\n", count_node_level(bt, 1, 'D'));
	count_node_levelk(bt, 1, 3, n);
	printf("level 3 has %d nodes\n", n);
	printf("ancestors of node 'G':\n");
	print_ancestor(bt, 'G');
	printf("\n");
	destroy_btree(bt);
	return 0;
}
