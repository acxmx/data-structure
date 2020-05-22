#include"lkstack.h"

bool is_match(char *str)
{
	char ch, tmp;
	int i = 0;
	bool match = true;
	StackNode *st;
	init_stack(st);
	while (str[i] != '\0')
	{
		ch = str[i];
		if (ch == '(')
			push(st, ch);
		else if (ch == ')')
		{
			if (stack_empty(st))
			{
				match = false;
				break;
			}
			else
				pop(st, tmp);
		}
		i++;
	}
	if (!stack_empty(st))
	{
		match = false;
	}
	destroy_stack(st);
	return match;
}
