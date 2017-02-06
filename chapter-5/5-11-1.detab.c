/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 5, 2017
*
* convert tab to space, with specified tab-width
* usage: 5-11-1.detab.o 10 12 14
*/

#include <stdio.h>
#include <stdlib.h>	// atoi

#define MAX_TAB_NUM 10
#define DEFAULT_TAB 8

int tabArr[MAX_TAB_NUM + 1];	// one more space for trailing 0

void getArg (int argc, char* argv[]) {
	int num = argc - 1 > MAX_TAB_NUM
		? MAX_TAB_NUM
		: argc - 1;

	// if no arguments
	if (num == 0) {
		tabArr[0] = DEFAULT_TAB;
		tabArr[1] = 0;
		return;
	}

	int i = 0;
	for ( ; i < num; i++) {
		tabArr[i] = atoi(argv[i + 1]);
	}
	tabArr[i + 1] = 0;
}

void detab (int col, int* tabNoP) {
	int tabWidth = tabArr[*tabNoP]
		? tabArr[*tabNoP]
		: tabArr[*tabNoP = 0];
	int space = tabWidth - col % tabWidth;
	for (int i = 0; i < space; i++) {
		putchar(' ');
	}
}

void run () {
	int c = 0;
	int col = 0;
	int tabNo = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') { 
			detab(col, &tabNo);
			col = 0;
			tabNo++;
		} else if (c == '\n') {
			putchar(c);
			col = 0;
			tabNo = 0;
		} else {
			putchar(c);
			col++;
		}
	}
}

main (int argc, char* argv[]) {
	getArg(argc, argv);
	run();
}

