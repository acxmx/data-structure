#include"sqqueue.h"

int main()
{
	ElemType a[] = {19,98,10,20,40,15}, e;
	SqQueue *qu;
	create_queue(qu, a, sizeof(a)/sizeof(ElemType));
	print_queue(qu);
	en_queue(qu, 12);
	print_queue(qu);
	de_queue(qu, e); 
	print_queue(qu);
	destroy_queue(qu);
	return 0;
}
