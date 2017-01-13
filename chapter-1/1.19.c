#include <stdio.h>

// reverse string
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
int reverse (char src[], char dst[]) {
	int i;
	for (i = 0; i < LIMIT; i++) {
		if (src[i] == '\0') break;
	}
	for (int j = 0; j < i; j++) {
		dst[j] = src[i - j - 1];
	}
	dst[i] = '\0';
}
main () {
	int len = 0;
	char currLine[LIMIT];
	char reversed[LIMIT];

	while ((len = readLine(currLine)) != EOF) {
		reverse(currLine, reversed);
		printf("%s\n\n\n", reversed);
	}
	return 0;
}
