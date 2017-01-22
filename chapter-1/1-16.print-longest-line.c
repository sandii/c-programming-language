/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 6, 2017
*
* print longest line and its length
*/

#include <stdio.h>

#define LIMIT 20

int readLine (char line[]) {
	int c = 0;
	int len = 0;
	while (c = getchar()) {
		if (c == EOF) return EOF;
		if (len < LIMIT - 1) {
			line[len] = c;
		}
		if (len == LIMIT - 1) {
			line[len] = '\0';
		}
		len++;
		if (c == '\n') {
			line[len] = '\0';
			return len;
		}
	}
}
int copyLine (char src[], char dst[]) {
	for (int i = 0; i < LIMIT; i++) {
		int c = src[i];
		dst[i] = c;
		if (c == '\0') break;
	}
}

main () {
	int curLen = 0;
	int maxLen = 0;
	char curLine[LIMIT];
	char maxLine[LIMIT];

	while (curLen = readLine(curLine)) {
		if (curLen == EOF) break;
		if (curLen <= maxLen) continue;
		maxLen = curLen;
		copyLine(curLine, maxLine);
	}
	if (maxLen <= 0) return 0;
	printf("longest line is: %s\n", maxLine);
	printf("its length is: %d\n", maxLen);
	return 0;
}
