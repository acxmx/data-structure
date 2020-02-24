#include"CirQueue.h"

int main()
{
	int num_arr[8];
	printf("请输入任意8个数进行报数出列：\n");
	for(int i=0; i<8; i++)
		scanf("%d",&num_arr[i]);
	printf("输入的8个数如下：\n");
	for(int i=0; i<8; i++)
		printf("\t%d",num_arr[i]);
	printf("\n");
	printf("报数出列如下：\n");
	NumberOffOut(num_arr , 8);
	return 0;
}
