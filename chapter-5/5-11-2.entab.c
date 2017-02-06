/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 5, 2017
*
* convert spaces to tab, with specified tab-width
* usage: 5-11-2.entab.o 10 12 14
*/

#include <stdio.h>
#include <stdlib.h>	// atoi

#define MAX_TAB_tabNo 10
#define DEFAULT_TAB 8

int tabArr[MAX_TAB_tabNo + 1];	// one more space for trailing 0

void getArg (int argc, char* argv[]) {
	int tabtabNo = argc - 1 > MAX_TAB_tabNo
		? MAX_TAB_tabNo
		: argc - 1;

	// if no arguments
	if (tabtabNo == 0) {
		tabArr[0] = DEFAULT_TAB;
		tabArr[1] = 0;
		return;
	}

	int i = 0;
	for ( ; i < tabtabNo; i++) {
		tabArr[i] = atoi(argv[i + 1]);
	}
	tabArr[i + 1] = 0;
}

void run () {
	int c = 0;
	int col = 0;
	int space = 0;
	int tabNo = 0;
	while ((c = getchar()) != EOF) {
		// if space, don't output, just accumulate
		if (c == ' ') {
			col++;
			space++;

		// if \n, clear accumulation
		} else if (c == '\n') {
			putchar(c);
			col = 0;
			space = 0;
			tabNo = 0;

		// if other characters
		// output accumulated spaces as \t and spaces 
		} else {
			if (space == 1) {
				putchar(' ');
			}
			if (space > 1) {
				bool enoughTab = false;
				int table = 0;
				int tabWidth = 0;
				while (!enoughTab) {
					//get tab width
					tabWidth = tabArr[tabNo];
					if (!tabWidth) {
						tabNo = 0;
						tabWidth = tabArr[tabNo];
					}

					if (col - tabWidth < 0) {
						enoughTab = true;
					} else {
						table++;
						tabNo++;
						col -= tabWidth;
					}
				}
				space = table ? col % tabWidth : space;
				for (int i = 0; i < table; i++) putchar('\t');
				for (int i = 0; i < space; i++) putchar(' ');
			}

			putchar(c);
			col = space + 1;
			space = 0;
		}
	}
}

main (int argc, char* argv[]) {
	getArg(argc, argv);
	run();
}
