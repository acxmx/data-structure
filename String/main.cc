#include"string.h"

int main()
{
	SqString *s1, *s2, *s3;
	char cstr1[] = "xmxmsdjsabcdefdccvbbbfdddsabcdefssswhhgffhgfifsd";
	char cstr2[] = "abcdef";
	create_string(&s1, cstr1);
	create_string(&s2, cstr2);
	printf("t在s中出现%d次\n", count_appear(s1, s2));
	destroy_string(s1);
	destroy_string(s2);
	return 0;
}
