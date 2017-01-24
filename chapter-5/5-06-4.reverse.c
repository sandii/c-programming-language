/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 22, 2017
*
* reverse charactors in string
*/

#include <stdio.h>
#include <string.h>

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

main () {
	char s[] = "hello!";
	reverse(s);
	printf("%s\n", s);
}