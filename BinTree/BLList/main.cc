#include"BLList.h"

int main()
{
	char str[] = "A(B(D(,G)),C(E,F))", ch;
	BTNode *btree_p;
	int val;
	CreateBTree(btree_p,str);
	DispBTree(btree_p);
	printf("\n");
	printf("根结点的左孩子结点：%p\t"
	"右孩子结点：%p\n",
	FindLChild(btree_p),FindRChild(btree_p));
	printf("值域为'A'的结点的地址：%p\n",
	FindNode(btree_p,'A'));
	printf("树高%d\n",BTreeHeight(btree_p));
	PreTravel(btree_p);
	puts("");
	InTravel(btree_p);
	puts("");
	PostTravel(btree_p);
	puts("");
	printf("nodes count:%d\n",NodesCount(btree_p));
	DispLeaf(btree_p);
	printf("\n");
	printf("'C'in the height:%d\n",
	Level(btree_p, 'C', 1));
	val = 0;
	int a = 1, b = 3, count=0;
	LevelNodesCount(btree_p,a,b,count);
	printf("level 3 nodes count:%d\n", count);
	printf("Ancestors of node 'E':\n");
	Ancestor(btree_p, 'E');
	printf("\n");
	DestroyBTree(btree_p);
	return 0;
}
