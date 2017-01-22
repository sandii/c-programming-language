/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 6, 2017
*
* print long enough lines
*/

#include <stdio.h>

#define LIMIT 100
#define SHRESHOLD 20

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
	int len = 0;
	char currLine[LIMIT];
	char rs[LIMIT][LIMIT];
	char index = 0;

	while ((len = readLine(currLine)) != EOF) {
		if (len <= SHRESHOLD) continue;
		copyLine(currLine, rs[index]);
		index++;
	}
	for (int i = 0; i < index; i++) {
		printf("%s", rs[i]);
	}
	return 0;
}
