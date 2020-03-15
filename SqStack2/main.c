#include"sqstack.h"

int main(void)
{
	ElemType a[] = {19,98,10,20,40,15};
	SqStack *st = create_stack(a, sizeof(a)/sizeof(int));
	print_stack(st);
	push(st,11);
	print_stack(st);
	pop(st);
	print_stack(st);
	destroy_stack(st);
	char str[MaxSize];
	scanf("%s", str);
	if (symmetry(str))
		printf("是回文\n");
	return 0;
}
