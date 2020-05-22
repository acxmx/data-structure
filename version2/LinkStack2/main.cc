#include"lkstack.h"

int main()
{
#if 0
	ElemType a[] = {19,98,10,20,40,15}, e;
	StackNode *st;
	create_stack(st, a, sizeof(a)/sizeof(ElemType));
	print_stack(st);
	push(st, 11);
	print_stack(st);
	pop(st, e);
	print_stack(st);
	destroy_stack(st);
#endif
	char str[20];
	scanf("%s", str);
	if (is_match(str))
		printf("true!\n");
	return 0;
}
