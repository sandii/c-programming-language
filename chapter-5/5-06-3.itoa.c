/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 22, 2017
*
* convert integer to string
*/

#include <stdio.h>
#include <string.h>	// strlen

void swap (char* p1, char* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void reverse (char* p) {
	char* l = p;
	char* r = p + strlen(p) - 1;
	for ( ; l < r; l++, r--) {
		swap(l, r);
	}
}

void itoa (char* s, int n) {
	char* p = s;

	int copy = n;
	n = n < 0 ? -n : n;
	
	for ( ; n; n /= 10) {
		*p = n % 10 + '0';
		p++;
	}
	if (copy < 0) {
		*p = '-';
		p++;
	}
	*p = '\0';
	reverse(s);
}

main () {
	char s[100];
	itoa(s, -45);	printf("%s\n", s);
	itoa(s, 235);	printf("%s\n", s);
}
