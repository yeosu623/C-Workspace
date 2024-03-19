#include <stdio.h>
#define macroFunc() func(1, 2)

int func(int a, int b)
{
	if(a == b) return 1;
	else return 0;
}

int main()
{
	int result = macroFunc();
	printf("%d", result);
}
