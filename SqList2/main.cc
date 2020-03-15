#include"sqlist.h"

int main()
{
	SqList *L;
	int a[] = {19,98,10,20,40,15,15,20}, e;
	int i;
	create_list(L,a,sizeof(a)/sizeof(int));
	printf("创建顺序表完成。\n");
	print_list(L);
	partition2(L);
	printf("partition1:\n");
	print_list(L);
	destroy_list(L);
	return 0;
}
