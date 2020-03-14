#include"LinkList.h"

//头插法创建单链表
void CreateListH(LinkNode * &L, ElemType a[], int n)
{
	int i;
	LinkNode *s;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	for(i=0; i<n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;  //进行插入操作
		L->next = s;
	}
}

//尾插法创建单链表
void CreateListR(LinkNode * &L, ElemType a[], int n)
{
	int i;
	LinkNode *s, *t;
	t = L = (LinkNode *)malloc(sizeof(LinkNode));
	for(i=0; i<n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		t->next = s;  //进行插入操作
		t = s;
	}
	t->next = NULL;
}

void InitList(LinkNode * &L)
{
	//初始化头指针，将其指针置空
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode * &L)
{
	LinkNode *pre = L, *p = pre->next;
	while(p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool ListEmpty(LinkNode * L)
{
	return (L->next == NULL);
}

int ListLength(LinkNode * L)
{
	int count = 0;
	LinkNode *p = L;
	while(p->next)
	{
		count++;
		p = p->next;
	}
	return count;
}

void DispList(LinkNode * L)
{
	LinkNode *p = L->next;
	printf("链表内容如下：\n");
	while(p)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L;
	if(i <= 0)
		return false;
	while(j<i && p)
	{
		j++;
		p = p->next;
	}
	if(!p)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

int LocateList(LinkNode * &L, ElemType e)
{
	int j = 1;
	LinkNode *p = L->next;
	while(p && p->data!=e)
	{
		j++;
		p = p->next;
	}
	if(!p)
		return 0;
	else
		return j;
}

bool ListInsert(LinkNode * &L, int i, ElemType e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if(i <= 0)
		return false;
	while(j<i-1 && p)
	{
		j++;
		p = p->next;
	}
	if(!p)
		return false;
	else
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode * &L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L, *q;
	if(i <= 0)
		return false;
	while(j<i-1 && p)
	{
		j++;
		p = p->next;
	}
	if(!p)
		return false;
	else
	{
		q = p->next;
		if(!q)
			return false;
		else
		{
			e = q->data;
			p->next = q->next;
			free(q);
			return true;
		}
	}
}

void split(LinkNode *L, LinkNode * &L1, LinkNode * &L2)
{
	LinkNode *p = L->next, *tmp, *r1;
	r1 = L1 = L;
	L2 = (LinkNode *)malloc(sizeof(LinkNode));
	L2->next = NULL;
	while(p)
	{
		r1->next = p;
		r1 = p;
		p = p->next;
		tmp = p->next;
		p->next = L2->next;
		L2->next = p;
		p = tmp;
	}
	r1->next = NULL;
}

void delmaxnode(LinkNode * &L)
{
	LinkNode *pre = L, *p = L->next,
	*maxpre = pre, *maxp = p;
	while(p)
	{
		if(p->data > maxp->data)
		{
			maxpre = pre;
			maxp = p;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	free(maxp);
}

//链表的直接插入排序
void sort(LinkNode * &L)
{
	LinkNode *p = L->next->next, *pre, *tmp;
	L->next->next = NULL;
	while(p)
	{
		tmp = p->next;
		pre = L;
		while(pre->next && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = tmp;
	}	
}
