/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 19, 2017
*
* convert integer to string, recursively
*/

#include <stdio.h>

int i = 0;

void itoa (int d, char s[]) {
	if (d < 0) {
		s[0] = '-';
		i = 1;
		d = -d;
	}
	if (d / 10 > 0) {
		itoa(d / 10, s);
	}
	s[i] = d % 10 + '0';
	i++;
	s[i] = '\0'; 
}

main () {
	char s[100];
	i = 0; itoa(21, s);		printf("%s\n", s);
	i = 0; itoa(-180, s);	printf("%s\n", s);
	i = 0; itoa(1343, s);	printf("%s\n", s);
}