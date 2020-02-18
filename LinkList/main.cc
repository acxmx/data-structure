#include"LinkList.h"

int main()
{
	LinkNode *L;
	ElemType a[] = {74,43,24,22,98,30,20,40,15}, e;
	int i;
	CreateListR(L,a,sizeof(a)/sizeof(ElemType));
	DispList(L);
//算法测试：
	delmaxnode(L);
	printf("删除最大值的元素后：\n");
	DispList(L);
	sort(L);
	printf("排序后：\n");
	DispList(L);
//插入和删除操作测试：
	printf("请输入插入位置和值(空格分隔)：\n");
	scanf("%d %d",&i,&e);
	if(ListInsert(L,i,e))
	{
		printf("操作成功！\n");
		DispList(L);
	}else
		printf("插入操作失败！\n");
	
	printf("请输入删除位置：\n");
	scanf("%d",&i);
	if(ListDelete(L,i,e))
	{
		printf("操作成功！"
		"值为%d的结点被删除！\n",e);
		DispList(L);
	}else
		printf("删除操作失败！\n");
	LinkNode *L1, *L2;
	split(L,L1,L2);
	printf("L1:\n");
	DispList(L1);
	printf("L2:\n");
	DispList(L2);
	return 0;
}
