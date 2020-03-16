#include"lkqueue.h"

int main()
{
	ElemType a[] = {19,98,10,20,40,15}, e;
	LkQueue *qu;
	create_queue(qu, a, sizeof(a)/sizeof(ElemType));
	print_queue(qu);
	printf("%d\n", queue_length(qu));
	de_queue(qu, e);
	print_queue(qu);
	destroy_queue(qu);
	return 0;
}
