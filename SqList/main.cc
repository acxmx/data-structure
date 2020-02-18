#include"SqList.h"

int main()
{
	SqList *L;
	ElemType a[] = {11,71,32,34,44,13,24,19,24,98,10,20,40,15},
	e;
	int i;
	CreateList(L,a,sizeof(a)/sizeof(int));
	printf("创建顺序表完成。\n");
	DispList(L);
	delnode1(L,24);
	printf("删除值为24的元素×××");
	DispList(L);
	partition1(L);
	printf("进行基准划分×××");
	DispList(L);
	move2(L);
	printf("进行奇偶排序×××");
	DispList(L);
	printf("请输入要插入的位置及元素的值（空格分隔）:\n");
	scanf("%d %d",&i,&e);
	if(ListInsert(L,i,e))
	{
		printf("插入操作成功！\n");
		DispList(L);
	}
	else
	{
		printf("操作失败！\n");
		DispList(L);
	}
	printf("请输入要删除的元素的位置:\n");
	scanf("%d",&i);
	if(ListDelete(L,i,e))
	{
		printf("删除操作成功！\n");
		DispList(L);
	}
	else
	{
		printf("操作失败！\n");
		DispList(L);
	}
	return 0;
}
