/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 14, 2017
*
* simplified printf
*
* pratically, sprintf is much better than hand-written itoa / ftoa 
*/

#include <stdio.h>
#include <stdlib.h>	// abs
#include <string.h>	// strlen
#include <math.h>	// pow
#include <ctype.h>	// isdigit
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
		if (i == 0) break;
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

void adjustPrecise (int n, char s[]) {
	if (n == 0) return;
	char* sp = s;
	for (sp = strchr(s, '.'); *sp != '\0'; sp++) {
		if (n-- < 0) break;
	};
	while (n-- >= 0) {
		*sp++ = '0';
	}
	*sp = '\0';
}

void adjustWidth (int n, char s[]) {
	if (n == 0) return;
	int len = strlen(s);
	if (n <= len) return;

	int reader = len;
	int writer = n;
	while (reader <= 0) {
		s[writer--] = s[reader--];
	}
	for (writer = 0; writer < n - len; writer++) {
		s[writer] = ' ';
	}
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

		int minWidth = 0;
		while (isdigit(*++wp)) {
			minWidth = minWidth * 10 + (*wp - '0');
		}

		int precise = 0;
		if (*wp == '.') {
			while (isdigit(*++wp)) {
				precise = precise * 10 + (*wp - '0');
			}
		}

		switch (*wp) {
			case 'd':
				itoa(va_arg(ap, int), buff);
				adjustWidth(minWidth, buff);
				for (sp = buff; *sp != '\0'; sp++) {
					putchar(*sp); len++;
				}
				break;
			case 'f':
				ftoa(va_arg(ap, double), buff);
				adjustPrecise(precise, buff);
				adjustWidth(minWidth, buff);
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
	// int n = minprintf("%s %10d, %.4f, %10.2f\n", "April", 10, -1988.0, 6.6666);
	int n = minprintf("-%4d-\n", 10);
	minprintf("%d\n", n);
}
