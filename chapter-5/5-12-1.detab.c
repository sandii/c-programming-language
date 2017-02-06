/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 5, 2017
*
* convert tab to space, with specified tab-width
*/

#include <stdio.h>
#include <ctype.h>


int getArg (int argc, char* argv[]) {
	int arg = 0;

	// no argument
	if (argc == 1) return arg;
	
	// wrong argument format
	argv++;
	char* p = *argv;
	if (*p != '-') return arg;
	
	// get number
	while (isdigit(*++p)) {
		arg = arg * 10 + (*p - '0');
	}
	return arg;
}

void run (int tabWidth) {
	int c = 0;
	int col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			int space = tabWidth - col % tabWidth;
			for (int i = 0; i < space; i++) {
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
}

main (int argc, char* argv[]) {
	int arg = getArg(argc, argv);
	run(arg ? arg : 8);
}

