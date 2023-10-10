#include <stdio.h>
#include <stdlib.h>

typedef struct _polynomial {
	int num1;
	float num2;
}polynomial;

int main() {
	polynomial arr[2] = {
		{1, 100.0},
		{1, 0}
	};
	
	printf("%d, %.1f", arr[0].num1, arr[0].num2);
}
