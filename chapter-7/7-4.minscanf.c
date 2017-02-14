/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 14, 2017
*
* simplified scanf
*/

#include <stdio.h>
#include <stdlib.h>	// abs
#include <string.h>	// strlen
#include <math.h>	// pow
#include <ctype.h>	// isdigit
#include <stdarg.h>

int buff = -1;
int getch () {
	if (buff == -1) {
		return getchar();
	} else {
		int c = buff;
		buff = -1;
		return c;
	}
}
void ungetch (int c) {
	buff = c;
}

#define MAX_WORD_LEN 100
char word[MAX_WORD_LEN + 1];


void getInt () {
	char* cp = word;
	*cp = '\0';

	int c;
	while (isspace(c = getch())) ;
	if (c == '-') {
		*cp++ = c;
	} else {
		ungetch(c);
	}

	while (isdigit(c = getch())) {
		*cp++ = c;
	}
	ungetch(c);
	*cp = '\0';
}

void getFloat () {
	char* cp = word;
	*cp = '\0';

	int c;
	while (isspace(c = getch())) ;
	if (c == '-') {
		*cp++ = c;
	} else {
		ungetch(c);
	}

	while (isdigit(c = getch())) *cp++ = c;
	if (c == '.') {
		*cp++ = c;
	} else {
		ungetch(c);
	}
	while (isdigit(c = getch())) *cp++ = c;

	ungetch(c);
	*cp = '\0';
}
void getString () {
	char* cp = word;
	*cp = '\0';

	int c;
	while (isspace(c = getch())) ;
	ungetch(c);
	while (isgraph(c = getch())) *cp++ = c;

	ungetch(c);
	*cp = '\0';
}

int minscanf (char* fmp, ...) {
	va_list ap;
	va_start(ap, fmp);

	int len = 0;
	for ( ; *fmp != '\0'; fmp++) {
		if (isspace(*fmp)) {
			continue;
		}
		if (*fmp != '%') {
			int c;
			while ((c = getch()) != *fmp) ;
			ungetch(c);
			continue;
		}

		switch (*++fmp) {
			case 'd':
				getInt();
				int* ip;
				ip = va_arg(ap, int*);
				*ip = atoi(word);
				len++;
				break;
			case 'f':
				getFloat();
				float* fp;
				fp = va_arg(ap, float*);
				*fp = atof(word);
				len++;
				break;
			case 's':
				getString();
				char* sp;
				sp = va_arg(ap, char*);
				strcpy(sp, word);
				len++;
				break;
			default:
				break;
		}
	}
	va_end(ap);
	return len;
}

main () {
	int d;
	float f;
	char s[20];
	int n = minscanf("%d %f %s", &d, &f, s);
	printf("%d\n%f\n%s\n", d, f, s);
}
