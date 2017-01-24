/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 16, 2017
*
* convert string to int 
*/

#include <stdio.h>
#include <ctype.h>

int atoi (char s[]) {
	int i = 0;
	int sign = 1;
	int rs = 0;
	for ( ; isspace(s[i]); i++) {
		;
	}
	if (s[i] == '-') {
		sign = -1;
	}
	for ( ; s[i] == '-' || s[i] == '+'; i++) {
		;
	}
	for ( ; isdigit(s[i]); i++) {
		rs = rs * 10 + (s[i] - '0');
	}
	return sign * rs;
}

main () {
	printf("%d\n", atoi("15"));
	printf("%d\n", atoi("  +100ss"));
	printf("%d\n", atoi("-113") + atoi("-13"));
}
