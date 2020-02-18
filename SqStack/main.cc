#include"SqStack.h"

int main()
{
	char str[] = "abcecdcecba";
	printf("按任意键判断%s是否是回文.\n",
	str);
	getchar();
	if(symmetry(str))
		printf("%s是回文.\n",str);
	else
		printf("%s不是回文.\n",str);
	return 0;
}
