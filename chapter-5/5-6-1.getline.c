/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 22, 2017
*
* get lines of user input
*/

#include <stdio.h>

#define MAXSIZE 100

int getline (char* p) {
	int len;
	for (len = 0; len < MAXSIZE - 1; len++) {
		char c = getchar();
		if (c == EOF || c =='\n') break;
		*p = c;
		p++;
	}
	*p = '\0';
	return len;
}

main () {
	char line[MAXSIZE];
	int i = 0;
	while (getline(line) != 0) {
		printf("%d %s\n", i++, line);
	}
}