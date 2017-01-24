/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 24, 2017
*
* convert hexadecimal string to decimal integer
* hexadecimal string may be prefixed with optional '0x' or '0X'
* and its number part may contains 0-9, a-f or A-F
*/

#include <stdio.h>
#include <ctype.h>

int hexaCharToInt (int c) {
	if (isdigit(c)) return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

int htoi (char* s) {
	int i = 0;
	int d = 0;

	// skip space
	while (isspace(s[i])) {
		i++;
	}

	// positive or negative
	int sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') {
		i++;
	}

	// optional prefix '0x' or '0X'
	if (s[i] == '0') {
		if (s[i + 1] == 'x' || s[i + 1] == 'X') {
			i += 2;
		} else {
			return 0;
		}
	}

	// number part
	for ( ; s[i] != '\0'; i++) {
		int v = hexaCharToInt(s[i]);
		if (v == -1) break;
		d = d * 16 + v;
	}

	return d;
}

main () {
	printf("%d\n", htoi("0xaf"));
	printf("%d\n", htoi(" -af1"));
}

