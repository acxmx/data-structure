#include"string.h"

void create_string(SqString **S, char cstr[])
{
	int i;
	init_string(S);
	for (i=0; cstr[i] != '\0' && i<MaxSize; i++)
		(*S)->data[i] = cstr[i];
	(*S)->length = i;
}

void init_string(SqString **S)
{
	(*S) = (SqString *)malloc(sizeof(SqString));
	(*S)->length = 0;
}

void destroy_string(SqString *S)
{
	free(S);
}

void print_string(SqString *S)
{
	int i;
	for (i=0; i<S->length; i++)
		printf("%c", S->data[i]);
	printf("\n");
}

int string_length(SqString *S)
{
	return S->length;
}

void strcpy(SqString *s, SqString *t)
{
	int i;
	for (i=0; i<t->length; i++)
		s->data[i] = t->data[i];
	s->length = t->length;
}

bool string_equal(SqString *s, SqString *t)
{
	int i = 0;
	bool flag = true;
	if (s->length != t->length)
		flag = false;
	else
	{
		while (i < s->length)
		{
			if (s->data[i] != t->data[i])
			{
				flag = false;
				break;

			}
			i++;
		}
	}
	return flag;
}

SqString *concat(SqString *s, SqString *t)
{
	int i;
	SqString *str;
	init_string(&str);
	for (i=0; i<s->length; i++)
		str->data[i] = s->data[i];
	for (i=0; i<t->length; i++)
		str->data[s->length + i] = t->data[i];
	str->length = s->length + t->length;
	return str;
}

SqString *substr(SqString *s, int i, int j)
{
	int k;
	SqString *str;
	init_string(&str);
	if (i < 1 || i > s->length || i+j-2 > s->length-1)
		return str;
	for (k = i-1; k < i+j-1; k++)
		str->data[k-i+1] = s->data[k];
	str->length = j;
	return str;
}

SqString *insstr(SqString *s, int i, SqString *t)
{
	int k;
	SqString *str;
	init_string(&str);
	if (i < 1 || i > s->length + 1)
		return str;
	for (k = 0; k < i-1; k++)
		str->data[k] = s->data[k];
	for (k = 0; k < t->length; k++)
		str->data[i+k-1] = t->data[k];
	for (k = i-1; k < s->length; k++)
		str->data[k + t->length] = s->data[k];
	str->length = s->length + t->length;
	return str;
}

SqString *delstr(SqString *s, int i, int j)
{
	int k;
	SqString *str;
	init_string(&str);
	if (i < 1 || i > s->length || i+j-1 > s->length)
		return str;
	for (k = 0; k < i-1; k++)
		str->data[k] = s->data[k];
	for (k = i+j-1; k < s->length; k++)
		str->data[k-j] = s->data[k];
	str->length = s->length - j;
	return str;
}

SqString *repstr(SqString *s, int i, int j, SqString *t)
{
	int k;
	SqString *str;
	init_string(&str);
	if (i < 1 || i > s->length || i+j-1 > s->length)
		return str;
	for (k = 0; k < i-1; k++)
		str->data[k] = s->data[k];
	for (k = 0; k < t->length; k++)
		str->data[i+k-1] = t->data[k];
	for (k = i+j-1; k < s->length; k++)
		str->data[k+t->length-j] = s->data[k];
	str->length = s->length + t->length - j;
	return str;
}
