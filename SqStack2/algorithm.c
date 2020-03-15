#include"sqstack.h"

bool symmetry(char *str)
{
	int i, top = -1;
	char stack[MaxSize], ch;
	bool symm = true;
	for(i=0; str[i]!='\0'; i++)
		stack[++top] = str[i];
	for(i=0; str[i] != '\0'; i++)
	{
		if(stack[top] != str[i])
			return false;
		top--;
	}
	return true;
}
