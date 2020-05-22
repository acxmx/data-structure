#include"rqueue.h"

int main()
{
	ElemType a[] = {19,98,10,20,40,15}, e;
	QuNode *rear;
	create_queue(rear, a, sizeof(a)/sizeof(ElemType));
	print_queue(rear);
	de_queue(rear, e);
	print_queue(rear);
	printf("l:%d\n", queue_length(rear));
	destroy_queue(rear);
	return 0;
}
