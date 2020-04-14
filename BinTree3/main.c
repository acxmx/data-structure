#include"btree.h"

int main(void)
{
	BTNode *bt, *p, *bt2;
	char str[] = "A(B(D(,G)),C(E,F))";
	int cnt = 0;
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
	count_node_k2(bt, 3, 1, &cnt);
	printf("level 3 node sum: %d\n", cnt);
	printf("all ancestor of every leaf node :\n");
	print_ancestor1(bt);
	printf("ancestor of node 'G':\n");
	print_ancestor(bt, 'G');
	printf("\nnon-recursion travling:\n");
	pre_travel2(bt);
	printf("inorder:\n");
	in_travel1(bt);
	printf("postorder:\n");
	post_travel1(bt);
	printf("level traveling:\n");
	level_travel(bt);
	printf("------------------------------\n");
	bt2 = create_bt2("GBEFCA", "BGAECF", 6);
	print_btree(bt2);
	printf("\n");
	destroy_btree(bt2);
	destroy_btree(bt);
	return 0;
}
