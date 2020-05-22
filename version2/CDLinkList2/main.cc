#include"cdlklist.h"

int main()
{
	ElemType a[] = {40,11,11,40}, e;
	CDLinkNode *L;
	create_listR(L, a, sizeof(a)/sizeof(int));
	print_list(L);
	if (list_insert(L, 9, 45))
		printf("插入成功！\n");
	print_list(L);
	if (list_delete(L, 10, e))
		printf("删除%d成功！\n", e);
	if (symm(L))
		printf("循环双链表对称！\n");
	print_list(L);
	destroy_list(L);
	return 0;
}
