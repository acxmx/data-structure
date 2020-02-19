#include"LinkStack.h"

int main()
{
	char exp[21];
	printf("请输入一个表达式，"
	"用以判断括号是否对称(最多20个字符)：\n");
	scanf("%s",exp);
	if(Match(exp))
		printf("输入表达式对称。\n");
	else
		printf("输入表达式不对称！\n");
	return 0;
}
