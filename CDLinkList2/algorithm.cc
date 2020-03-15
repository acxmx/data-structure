#include"cdlklist.h"

bool symm(CDLinkNode *L)
{
	CDLinkNode *p = L->next, *q = L->prior;
	bool same = true;
	while (same)
	{
		if (p->data != q->data)
			same = false;
		else if (p == q || p->next == q)
			break;
		p = p->next;
		q = q->prior;
	}
	return same;
}
