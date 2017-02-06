/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 6, 2017
*
* convert tab to space
* since colomn m, with specified tab-width n
* usage: 5-12-1.detab.o -m +n
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT_TABWIDTH 8

void getArg (int argc, char* argv[], int* mp, int* np) {
	for (int i = 1; i < argc; i++) {
		char* p = argv[i];
		if (*p == '-') *mp = atoi(++p);
		if (*p == '+') *np = atoi(++p);
	}
}

void detab (int* colp, int m, int n) {
	int col = *colp <= m 
		? *colp 
		: *colp - m;
	int tabWidth = *colp <= m
		? DEFAULT_TABWIDTH
		: n;
	int space = tabWidth - col % tabWidth;
	for (int i = 0; i < space; i++) {
		putchar(' ');
	}
	*colp += space;
}

void run (int m, int n) {
	int c = 0;
	int col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			detab(&col, m, n);
		} else if (c == '\n') {
			putchar(c);
			col = 0;
		} else {
			putchar(c);
			col++;
		}
	}
}

main (int argc, char* argv[]) {
	int m = 0;
	int n = DEFAULT_TABWIDTH;
	getArg(argc, argv, &m, &n);
	run(m, n);
}

