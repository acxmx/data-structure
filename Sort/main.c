#include"sort.h"

int main(void)
{
	int arr[] = {44,13,24,13,56,84,15};
	print_arr(arr, sizeof(arr)/sizeof(int));
	insert_sort(arr, sizeof(arr)/sizeof(int), greater_than);
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
