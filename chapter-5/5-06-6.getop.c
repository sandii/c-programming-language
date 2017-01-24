/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 23, 2017
*
* get operants and operators from input lines
*/

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int getline (char* p) {
	int len;
	for (len = 0; len < MAXSIZE - 1; len++) {
		int c = getchar();
		if (c == '\n' || c == EOF) break;
		*p = c;
		p++;
	}
	*p = '\0';
	return len;
}

int getop (char* p, char* op) {
	int len = 0;

	if (*p == '\0') return len;

	// skip blanks
	while (isspace(*p)) {
		p++;
		len++;
	}

	// charactors
	if (isalpha(*p)) {
		while (isalpha(*p)) {
			*op = *p;
			p++; op++; len++;
		}
		*op = '\0';
		return len;
	}

	// -
	if (*p == '-' && isdigit(*(p + 1))) {
		*op = *p;
		p++; op++; len++;
	}

	// number
	if (isdigit(*p)) {
		while (isdigit(*p)) {
			*op = *p;
			p++; op++; len++;
		}
		*op = '\0';
		return len;
	}

	// operator
	if (*p == '+' || *p == '-' || *p == '*' || *p == '%') {
		*op = *p;
		p++; op++; len++;
		*op = '\0';
		return len;
	}

	return len;
}

main () {
	char s[MAXSIZE];
	char op[MAXSIZE];
	getline(s);
	char* p = s;
	while (int len = getop(p, op)) {
		printf("%s\n", op);
		p += len;
	}
}
