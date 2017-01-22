/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 13, 2017
*
* tab to space
*/ 

#include <stdio.h>

#define TABWIDTH 6

main () {
	int c = 0;
	int col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			int num = TABWIDTH - (col - 2) % TABWIDTH;
			for (int i = 0; i < num; i++) {
				putchar(' ');
			}
			col = 0;
		} else if (c == '\n') {
			putchar(c);
			col = 0;
		} else {
			putchar(c);
			col++;
		}
	}
	return 0;
}
