#include <stdio.h>

// remove \t and white space at lines end
// remove lines that only contain \t and white space
#define LIMIT 100

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
int filterSpace (char line[], int len) {
	if (len <= 1) return len;
	int i = len - 2;
	for (; i >= 0; i--) {
		if (line[i] != '\t' && line[i] != ' ') {
			line[i + 1] = '\n';
			break;
		}
		line[i] = '\0';
	}
	return i + 2;
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
		len = filterSpace(currLine, len);
		if (len <= 1) continue;
		copyLine(currLine, rs[index]);
		index++;
	}
	printf("\n\n");
	for (int i = 0; i < index; i++) {
		printf("%s", rs[i]);
	}
	return 0;
}
