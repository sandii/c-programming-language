/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 5, 2017
*
* convert spaces to tab, with specified tab-width
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
	int space = 0;
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

		// if other charactors
		// output accumulated spaces as \t and spaces 
		} else {
			if (space == 1) {
				putchar(' ');
			}
			if (space > 1) {
				int table = col / tabWidth - (col - space) / tabWidth;
				space = !table ? space : col % tabWidth;
				for (int i = 0; i < table; i++) putchar('\t');
				for (int i = 0; i < space; i++) putchar(' ');
			}

			putchar(c);
			col++;
			space = 0;
		}
	}
}

main (int argc, char* argv[]) {
	int arg = getArg(argc, argv);
	run(arg ? arg : 8);
}
