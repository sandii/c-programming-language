/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 17, 2017
*
* reverse string
*/

#include <stdio.h>
#include <string.h>

void reverse (char s[]) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

main () {
	char s[] = "abcdefghi";
	reverse(s);
	printf("%s\n", s);
}
