/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 17, 2017
*
* convert int to string
*/

#include <stdio.h>
#include <stdlib.h>	// abs
#include <string.h>	// strlen

void swap (char s[], int i, int j) {
	if (i == j) return;
	int temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void reverse (char s[]) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		swap(s, i, j);
	}
}

void itoa (int n, char s[]) {
	int copy = n;
	int writer = 0;
	do {
		s[writer++] = abs(n % 10) + '0';
		n /= 10;
	} while (n);

	if (copy < 0) {
		s[writer++] = '-';
	}
	s[writer] = '\0';

	reverse(s);
}

main () {
	char dst[10];
	itoa(123, dst);		printf("%s\n", dst);
	itoa(-123, dst);	printf("%s\n", dst);
	itoa(53, dst);		printf("%s\n", dst);
}
