#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int* ptr = new int;
	int& ref = *ptr;
	ref = 200;
	cout << ref << endl;

	return 0;
}
