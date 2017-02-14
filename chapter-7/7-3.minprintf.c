/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 14, 2017
*
* simplified printf
*/

#include <stdio.h>
#include <stdlib.h>	// abs
#include <string.h>	// strlen
#include <math.h>	// pow
#include <stdarg.h>

#define MAX_BUFF_LEN 100
char buff[MAX_BUFF_LEN + 1];

void swap (char s[], int i, int j) {
	if (i == j) return;
	int temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void reverse (char s[]) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		swap(s, i, j);
	}
}

void itoa (int n, char s[]) {
	int copy = n;
	int writer = 0;
	do {
		s[writer++] = abs(n % 10) + '0';
		n /= 10;
	} while (n);

	if (copy < 0) {
		s[writer++] = '-';
	}
	s[writer] = '\0';

	reverse(s);
}

#define PRECISE 6
void ftoa (double f, char s[]) {
	double copy = f;

	char is[MAX_BUFF_LEN];
	int i = abs((int) f);
	itoa(i, is);

	char fs[MAX_BUFF_LEN];
	if (f < 0) f = -f;
	f = f - (double) i;
	i = (int) ceil(f * pow(10, PRECISE));
	while (i % 10 == 0) {
		i /= 10;
	}
	itoa(i, fs);

	char* sp = s;
	if (copy < 0) {
		*sp++ = '-';
	}
	for (char* ip = is; *ip != '\0'; ip++) {
		*sp++ = *ip;
	}
	*sp++ = '.';
	for (char* fp = fs; *fp != '\0'; fp++) {
		*sp++ = *fp;
	}
	*sp = '\0';
}

int minprintf (char* fmp, ...) {
	va_list ap;
	va_start(ap, fmp);

	char* sp;
	int len = 0;

	for (char* wp = fmp; *wp != '\0'; wp++) {
		if (*wp != '%') {
			putchar(*wp); len++;
			continue;
		}
		switch (*++wp) {
			case 'd':
				itoa(va_arg(ap, int), buff);
				for (sp = buff; *sp != '\0'; sp++) {
					putchar(*sp); len++;
				}
				break;
			case 'f':
				ftoa(va_arg(ap, double), buff);
				for (sp = buff; *sp != '\0'; sp++) {
					putchar(*sp); len++;
				}
				break;
			case 's':
				sp = va_arg(ap, char*);
				for ( ; *sp != '\0'; sp++) {
					putchar(*sp); len++;
				}
				break;
			default:
				putchar(*wp); len++;
		}
	}
	return len;
}

main () {
	int n = minprintf("%s %d, %f\n", "April", 10, -19.88);
	minprintf("%d\n", n);
}
