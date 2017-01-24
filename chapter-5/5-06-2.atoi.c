/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 22, 2017
*
* convert string to integer
*/

#include <stdio.h>
#include <ctype.h>

int atoi (char* p) {
	// skip blanks
	while (isspace(*p)) {
		p++;
	}

	// positive or nagative
	int sign = *p == '-' ? -1 : 1;
	if (*p == '-' || *p == '+') {
		p++;
	}

	// is not a number
	if (!isdigit(*p)) return 0;

	// number
	int rs = 0;
	while (isdigit(*p)) {
		rs = rs * 10 + (*p - '0');
		p++;
	}
	return sign * rs;	
}

main () {
	printf("%d\n", atoi(" 123"));
	printf("%d\n", atoi("-12.3"));
	printf("%d\n", atoi("573a.3"));
}

