#include"string.h"

void get_next(SqString *t, int next[])
{
	int j, k;
	j = 0, k = -1;
	next[0] = -1;
	while (j < t->length - 1)
	{
		if (k == -1 || t->data[j] == t->data[k])
		{
			j++;
			k++;
			if (t->data[j] == t->data[k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMP(SqString *s, SqString *t, int idx, int *next)
{
	int i, j;
	i = idx, j = 0;
	if (s->length == 0 || t->length == 0)
		return (-1);
	while (i < s->length && j < t->length)
	{
		if (j == -1 || s->data[i] == t->data[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= t->length)
		return i;
	else
		return (-1);
}

int count_appear(SqString *s, SqString *t)
{
	int idx, count;
	int next[t->length];
	idx = 0, count = 0;
	get_next(t, next);
	idx = KMP(s, t, idx, next);
	while (idx != -1 && idx != s->length)
	{
		count++;
		idx = KMP(s, t, idx, next);
	}
	return count;
}
