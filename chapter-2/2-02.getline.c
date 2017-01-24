/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 24, 2017
*
* getline without && and ||
*/

#include <stdio.h>

#define MAXSIZE 100

void getline (char* s) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		int c = getchar();
		if (c == '\n') break;
		if (c == EOF) break;
		s[i] = c;
	}
	s[i] = '\0';
}

main () {
	char s[MAXSIZE];
	getline(s);
	printf("%s\n", s);
}

