#include"clqueue.h"

int main()
{
	ElemType a[] = {19,98,10,20,40,15};
	ClQueue *qu;
	create_queue(qu, a, sizeof(a)/sizeof(ElemType));
	print_queue(qu);
	char str[20];
	printf("input:");
	scanf("%s", str);
	numberof(str);
	destroy_queue(qu);
	return 0;
}
