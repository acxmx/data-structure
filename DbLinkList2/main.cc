#include"dlklist.h"

int main()
{
	ElemType a[] = {35,89,19,98,20,45,10,15}, e;
	DLinkNode *L;
	int i;
	create_listR(L, a, sizeof(a)/sizeof(int));
	print_list(L);
	printf("请输入插入位置和值:\n");
	scanf("%d %d", &i, &e);
	if (list_insert(L, i, e))
		printf("插入成功!\n");
	print_list(L);
	printf("请输入删除位置:\n");
	scanf("%d", &i);
	if (list_delete(L, i, e))
		printf("删除了%d\n", e);
	print_list(L);
	list_delete(L, 2, e);
	reverse(L);
	print_list(L);
	list_insert(L, 2, 9);
	sort(L);
	print_list(L);
	destroy_list(L);
	return 0;
}
