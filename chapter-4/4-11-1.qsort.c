/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 19, 2017
*
* quick sort
*/

#include <stdio.h>

void swap (int a[], int i, int j) {
	if (i == j) return;
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void qsort (int a[], int left, int right) {
	// one element
	if (left >= right) return;
	// two elements
	if (right - left == 1) {
		if (a[left] <= a[right]) return;
		swap(a, left, right);
		return;
	}
	// more than two elements
	// set middle element as pivot value
	int pivot = (left + right) / 2;
	int v = a[pivot];

	// temporarily put pivot to left, for comparison convinience
	swap(a, left, pivot);
	pivot = left;

	// compare every element to pivot value
	// move smaller ones to left
	// bigger ones stay at where they are
	// during this process, pivot value keep staying at leftest position
	// but pivot position keep changing
	for (int i = left + 1; i <= right; i++) {
		if (a[i] >= v) continue;
		pivot++;
		swap(a, pivot, i);		
	}
	// move pivot value back to pivot position
	// now, all elements at its left side are smaller
	// and its right side are bigger ones
	swap(a, left, pivot);
	
	// sort left sub-array
	// there should be at least 2 elements in sub-array
	if (pivot - left >= 2) {
		qsort(a, left, pivot - 1);
	}
	// sort right sub-array
	if (right - pivot >= 2) {
		qsort(a, pivot + 1, right);
	}
}

main () {
	int len = 10;
	int a[] = {4,11,36,1,65,3,33,55,16,10};
	qsort(a, 0, len - 1);
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
