#include"btree.h"

int main(void)
{
	BTNode *bt, *p;
	char str[] = "A(B(D(,G)),C(E,F))";
	create_btree(&bt, str);
	print_btree(bt);
	printf("\n");
	if (p = find_node(bt, 'A'))
		printf("%c\n", p->data);
	else
		printf("no find!\n");
	printf("btree's height:%d\n", btree_height(bt));
	printf("preorder travel:\n");
	pre_travel(bt);
	printf("\ninorder travel:\n");
	in_travel(bt);
	printf("\npostorder travel:\n");
	post_travel(bt);
	printf("\n");
	printf("binary tree has nodes sum:%d\n", count_node(bt));
	printf("leaf node:\n");
	print_leaf(bt);
	printf("\n");
	printf("node G in level %d\n", find_node_level(bt, 'G', 1));
	destroy_btree(bt);
	return 0;
}
