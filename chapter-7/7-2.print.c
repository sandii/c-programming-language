/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 13, 2017
*
* print user input
* - break long text lines
* - print non-graphic characters in octal (default) or hexadecimal (-x)
* usage:
* 7-2.print.o -x
*/

#include <stdio.h>
#include <string.h>	// strstr strlen
#include <ctype.h>

#define MAX_LINE_LEN 30
#define MAX_BUFF_LEN 20
#define TAB_SIZE 4

char buff[MAX_BUFF_LEN];
int buffReader = -1;
int getch () {
	return buffReader == -1 ? getchar() : buff[buffReader--];
}
void swap (int i, int j) {
	if (i == j) return;
	int temp = buff[i];
	buff[i] = buff[j];
	buff[j] = temp;
}
void reverseBuff () {
	for (int i = 0; i <= buffReader / 2; i++) {
		swap(i, buffReader - i);
	}
}


main (int argc, char* argv[]) {
	char oct[] = "0%o";
	char dex[] = "0x%x";
	char* formp = argc > 1 && strstr(argv[1], "-x") == NULL 
		? oct 
		: dex;

	int c;
	int col = 0;
	while ((c = getch()) != EOF) {
		if (!isgraph(c) && !isspace(c)) {
			buffReader = sprintf(buff, formp, c) - 1;
			reverseBuff();
			continue;
		}

		if (c == '\n' || col >= MAX_LINE_LEN) {
			putchar('\n');
			col = 0;
		} else if (c == ' ' && col == 0) {
			continue;
		} else if (c == '\t') {
			int num = TAB_SIZE - col % TAB_SIZE;
			buffReader = num - 1;
			for (int i = 0; i <= buffReader; i++) {
				buff[i] = ' ';
			}
		} else {
			putchar(c);
			col++;
		}		
	}
}
