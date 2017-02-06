/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 6, 2017
*
* convert space to tab
* since column m, with specified tab-width n
* usage: 5-12-2.entab.o -m +n
*/

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TABWIDTH 8

void getArg (int argc, char* argv[], int* mp, int* np) {
	for (int i = 1; i < argc; i++) {
		char* p = argv[i];
		if (*p == '-') *mp = atoi(++p);
		if (*p == '+') *np = atoi(++p);
	}
}

void entab (int space, int* colp, int m, int n) {
	if (space == 0) return;
	if (space == 1) {
		putchar(' ');
		return;
	}

	int table = 0;
	// all spaces before column m
	if (*colp <= m) {
		table = *colp / DEFAULT_TABWIDTH - (*colp - space) / DEFAULT_TABWIDTH;
		space = table ? *colp % DEFAULT_TABWIDTH : space;
		for (int i = 0; i < table; i++) putchar('\t');
		for (int i = 0; i < space; i++) putchar(' ');

	// all spaces after column m
	} else if (*colp - space >= m) {
		table = *colp / n - (*colp - space) / n;
		space = table ? *colp % n : space;
		for (int i = 0; i < table; i++) putchar('\t');
		for (int i = 0; i < space; i++) putchar(' ');

	// spaces cross column m
	} else {
		int table1 = m / DEFAULT_TABWIDTH - (*colp - space) / DEFAULT_TABWIDTH;
		int space1 = table1 ? m % DEFAULT_TABWIDTH : m - (*colp - space);
		int table2 = (*colp - m) / n;
		int space2 = table2 ? (*colp - m) % n : *colp - m;
		for (int i = 0; i < table1; i++) putchar('\t');
		for (int i = 0; i < space1; i++) putchar(' ');
		for (int i = 0; i < table2; i++) putchar('\t');
		for (int i = 0; i < space2; i++) putchar(' ');
	}
}

void run (int m, int n) {
	int c = 0;
	int col = 0;
	int space = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			col++;
			space++;
		} else if (c == '\n') {
			putchar(c);
			col = 0;
			space = 0;
		} else {
			entab(space, &col, m, n);
			putchar(c);
			col++;
			space = 0;
		}
	}
}

main (int argc, char* argv[]) {
	int m = 0;
	int n = DEFAULT_TABWIDTH;
	getArg(argc, argv, &m, &n);
	run(m, n);
}

