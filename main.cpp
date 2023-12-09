#include <stdio.h>
#include <stdlib.h>

int* f1() {
	int a = 10;
	return(&a);
}

//int* f2() {
//	int* ptr;
//	*ptr = 10;
//	return ptr;/
//}

int* f3() {
	int* ptr;
	ptr = (int*)malloc(sizeof(int));
	
	*ptr = 10;
	return ptr;
}

// Stack
//int max_stack_size = 3; // �ʱⰪ
//int* stack, top = -1;
//void printStack();
//void push(int);
//int pop();

int main() {
	int* p1, * p2, * p3;
	p1 = f1();
	//p2 = f2();
	p3 = f3();

	printf("%d", *p1);
}
