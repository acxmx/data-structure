#include"DbLinkList.h"

void CreateListH(DLinkNode * &L, ElemType a[], int n)
{
	int i;
	DLinkNode *s;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	s = (DLinkNode *)malloc(sizeof(DLinkNode));
	s->data = a[0];
	L->next = s;
	s->prior = L;
	s->next = L;
	L->prior = s;
	for(i=1; i<n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void CreateListR(DLinkNode * &L, ElemType a[], int n)
{
	int i;
	DLinkNode *s, *r;
	r = L = (DLinkNode *)malloc(sizeof(DLinkNode));
	for(i=0; i<n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}

void InitList(DLinkNode * &L)
{
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
}

void DestroyList(DLinkNode * &L)
{
	DLinkNode *pre = L->next, *p;
	if(!pre)  //表为空的情况
	{
		free(L);
	}
	else  //表不为空的情况
	{
		p = pre->next;
		while(p!=L)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(p);
		free(pre);
	}
}

bool ListEmpty(DLinkNode * L)
{
	return (L->next == L->prior);
}

int ListLength(DLinkNode * L)
{
	int j=0;
	DLinkNode *p = L;
	while(p->next!=L)
	{
		j++;
		p = p->next;
	}
	return j;
}

void DispList(DLinkNode * L)
{
	DLinkNode *p = L->next;
	printf("链表元素如下：\n");
	while(p!=L)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

bool GetElem(DLinkNode *L, int i, ElemType &e)
{
	int j=1;
	DLinkNode *p = L->next;
	if(!p)
		return false;
	if(i<1)
		return false;
	while(j<i && p!=L)
	{
		j++;
		p = p->next;
	}
	if(p==L)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

int LocateElem(DLinkNode * L, ElemType e)
{
	int j=1;
	DLinkNode *p = L->next;
	if(!p)
		return false;
	while(p!=L && p->data!=e)
	{
		j++;
		p = p->next;
	}
	if(p==L)
		return 0;
	else
		return j;
}

bool ListInsert(DLinkNode * &L, int i, ElemType e)
{
	int j=1;
	DLinkNode *p = L->next, *s;
	if(i<1)
		return false;
	//循环双链表的插入需要区分头部的插入和其他位置的插入的情况
	//头部插入
	if(i == 1)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = L->next;
		L->next->prior = s;
		L->next = s;
		s->prior = L;
		return true;
	}
	//其他位置的插入
	while(j<i-1 && p!=L)
	{
		j++;
		p = p->next;
	}
	if(p == L)
		return false;
	else
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		s->prior = p;
		return true;
	}
}

bool ListDelete(DLinkNode * &L, int i, ElemType &e)
{
	int j=1;
	DLinkNode *p = L->next;
	if(i<1)
		return false;
	if(L->next == L->prior)
		return false;
	while(j<i && p!=L)
	{
		j++;
		p = p->next;
	}
	if(p == L)
		return false;
	else
	{
		e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return true;
	}
}

//逆转链表元素(假设链表非空)
void reverse(DLinkNode * &L)
{
	DLinkNode *q = L->next, *p = q->next, *np;
	//处理第一个元素
	L->next = q;
	q->prior = L;
	q->next = L;
	L->prior = q;
	//头插法处理其他位置元素
	while(p!=L)
	{
		np = p->next;
		p->next = L->next;
		L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = np;
	}
}

//直接插入排序思想(假设表非空)
void sort(DLinkNode * &L)
{
	DLinkNode *p = L->next->next, *q, *np;
	//处理第一个元素，建立初始有序区
	L->next->next = L;
	L->prior = L->next;
	//直插排序处理其他位置元素
	while(p != L)
	{
		np = p->next;
		q = L;
		//找到插入位置元素的前驱
		while(q->next != L &&
		q->next->data < p->data)
			q = q->next;
		//进行插入
		p->next = q->next;
		q->next->prior = p;
		q->next = p;
		p->prior = q;
		p = np;
	}
}

int count(DLinkNode * L, ElemType x)
{
	int count = 0;
	DLinkNode *p = L->next;
	if(p->next == p->prior)
		return 0;
	while(p != L)
	{
		if(p->data == x)
			count++;
		p = p->next;
	}
	return count;
}

bool delnode(DLinkNode * &L, ElemType x)
{
	DLinkNode *p = L->next;
	if(L->next == L->prior)
		return false;
	while(p!= L && p->data != x)
		p = p->next;
	if(p == L)
		return false;
	else
	{
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return true;
	}
}

bool Symm(DLinkNode *L)
{
	bool same = true;
	DLinkNode *p = L->next, *q = L->prior;
	while(same)
	{
		if(p->data != q->data)
			same = false;
		else
		{
			if(p == q || p->next == q)
				break;
			p = p->next;
			q = q->prior;
		}
	}
	return same;
}
