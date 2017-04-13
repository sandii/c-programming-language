/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 16, 2017
*
* binary search
*/

#include <stdio.h>

int _binsearch (int x, int arr[], int len) {
	int low = 0;
	int high = len - 1;
	while (low < high) {
		// printf("%d %d\n", low, high);
		int mid = (low + high) / 2;
		int v = arr[mid];
		if (x < v) {
			high = mid;	
			// because mid is a floor integer, we can't set "high = mid - 1"
		} else if (x > v) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}
int binsearch (int x, int arr[], int len) {
	int low = 0;
	int high = len - 1;
	while (low < high) {
		// printf("%d %d\n", low, high);
		int mid = (low + high) / 2;
		if (x <= arr[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return (arr[low] == x) ? low : -1;
}

main() {
	int len = 100;
	int a[len];
	for (int i = 0; i < len; i++) {
		a[i] = i * 3;
	}
	printf("%d\n", _binsearch(0, a, len));
	printf("\n\n\n");
	printf("%d\n", binsearch(300, a, len));
}
