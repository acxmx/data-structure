#include"DbLinkList.h"

int main()
{
	int i;
//	ElemType a[] = {12,41,63,88,21,14,17,39}, e;
	ElemType a[] = {1,2,1};
	DLinkNode *L;
	CreateListR(L,a,sizeof(a)/sizeof(ElemType));
	DispList(L);
#if 0
	reverse(L);
	printf("元素逆转后：\n");
	DispList(L);
	sort(L);
	printf("元素排序后：\n");
	DispList(L);
	printf("输入要统计的元素值：\n");
	scanf("%d",&e);
	printf("data值为%d的元素个数为%d\n",e,count(L,e));
	printf("请输入要删除的元素的值：\n");
	scanf("%d",&e);
	if(delnode(L,e))
	{
		printf("操作成功！\n");
		DispList(L);
	}else
		printf("操作失败！\n");
#endif
	if(Symm(L))
		printf("链表对称！\n");
	else
		printf("链表不对称！\n");
#if 0
	printf("请输入插入位置及值(空格分隔)：\n");
	scanf("%d %d",&i,&e);
	if(ListInsert(L,i,e))
	{
		printf("插入成功！\n");
		DispList(L);
	}else
		printf("操作失败！\n");
	printf("请输入要删除的元素的逻辑序号：\n");
	scanf("%d",&i);
	if(ListDelete(L,i,e))
	{
		printf("删除成功！\n");
		printf("被删除元素的值为%d\n",e);
		DispList(L);
	}else
		printf("操作失败！\n");
#endif

#if 0
	printf("当前表长为：%d\n",ListLength(L));
	printf("请输入要获得元素值的元素位置：\n");
	scanf("%d",&i);
	if(GetElem(L,i,e))
	{
		printf("操作成功！\n");
		printf("第%d个元素的值为%d\n",i,e);
	}else
		printf("操作失败！\n");
	printf("请输入要查找的元素值：\n");
	scanf("%d",&e);
	if(i = LocateElem(L,e))
	{
		printf("操作成功！\n");
		printf("第一个值为%d的元素在逻辑序号%d\n",
		e,i);
	}else
		printf("没有此值的元素！\n");
#endif
	return 0;
}
