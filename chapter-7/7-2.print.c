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

#define MAX_LINE_LENGTH 20
#define MAX_NUM_LENGTH 20

char buff[MAX_BUFF_LENGTH];
int buffLen = 0;
int getch () {
	return buffLen ? buff[--buffLen] : getchar();
}
void reverseBuff () {
	
}

main (int argc, char* argv[]) {
	char form[] = strstr(argv[1], "-x") == NULL ? "0%o" : "0x%x";
	

	int c;
	int col = 0;
	while ((c = getch()) != EOF) {
		if (!isgraph(c) && !isspace(c)) {
			buffLen = sprintf(buff, form, c);
			reverseBuff();
		}
		putchar(c);
	}
}
