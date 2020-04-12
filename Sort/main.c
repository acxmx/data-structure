#include"sort.h"

//头文件中的两个函数声明了排序规则
//less_than：元素递减排序
//greater_than：元素递增排序

int main(void)
{
	int arr[] = {44,13,24,13,56,84,15};
	printf("before sort:\n");
	print_arr(arr, sizeof(arr)/sizeof(int));
	bubble_sort(arr, sizeof(arr)/sizeof(int), greater_than);
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
