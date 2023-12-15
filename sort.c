#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define RANDOM 0
#define ASCENDING 1
#define DESCENDING 2
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_data(float* arr, int n, int tag);
int is_sorted(float* arr, int n);
void quick_sort(float* arr, int left, int right);

int main() {
	int count = 0;
	int n = 10000;
	while (1) {
		float* arr = (float*)malloc(sizeof(float) * n);

		insert_data(arr, n, ASCENDING);
		quick_sort(arr, 0, n-1);

		printf("quick sorted %d\n", count++);

		//free(arr);
	}
}

void insert_data(float* arr, int n, int tag) {
	int i;
	for (i = 0; i < n; i++)
		arr[i] = (rand() / (0x7fff * 1.0)) * 100000000;

	quick_sort(arr, 0, n - 1);
}

int is_sorted(float* arr, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (!(arr[i] <= arr[i + 1]))
			return FALSE;
	}
	return TRUE;
}

void quick_sort(float* arr, int left, int right) {
	int i, j;
	float pivot;
	float temp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = arr[left];

		do {
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			if (i < j) SWAP(arr[i], arr[j], temp);
		} while (i < j);

		SWAP(arr[left], arr[j], temp);
		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}
