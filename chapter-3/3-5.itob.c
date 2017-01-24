/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 17, 2017
*
* convert int to string, for specific base
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char s[]) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itob (int n, char s[], int base) {
	int copy = n;
	if (n == 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}

	int i = 0;
	for (; n; n /= base, i++) {
		s[i] = abs(n % base) + '0';
	}
	if (copy < 0) {
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	i++;

	reverse(s);
}


main () {
	char s[100];
	itob(0, s, 2);		printf("%s\n", s);
	itob(-4, s, 2);		printf("%s\n", s);
	itob(8, s, 2);		printf("%s\n", s);
	itob(7, s, 2);		printf("%s\n", s);
	itob(17, s, 2);		printf("%s\n", s);
	itob(17, s, 8);		printf("%s\n", s);
}