#include<stdio.h>

void move(int n, char X, char Z)
{
	printf("将第%d个盘片从%c移动到%c\n",
	n, X, Z);
}

void hanoi(int n, char X, char Y, char Z)
{
	if(n == 1)
		printf("将第%d个盘片从%c移动到%c\n",
		n, X, Z);
	else
	{
		hanoi(n-1, X, Z, Y);
		move(n, X, Z);
		hanoi(n-1, Y, X, Z);
	}
}

int main ()
{
	int n;
	printf("请输入盘片数:");
	scanf("%d",&n);
	hanoi(n, 'X', 'Y', 'Z');
	return 0;
}
