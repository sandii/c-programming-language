#include <stdio.h>

// count lines, words and characters in input
#define IN  1
#define OUT 0

main () {
	int c = 0;
	int state = OUT;
	int lNum = 0;
	int wNum = 0;
	int cNum = 0;
	while ((c = getchar()) != EOF) {
		cNum++;
		if (c == '\n') {
			lNum++;
		}
		if (state == OUT && c != '\n' && c != '\t' && c != ' ') {
			state = IN;
			wNum++;
		}
		if (c == '\n' || c == '\t' || c == ' ') {
			state = OUT;
		}
	}
	printf("%d lines, %d words, %d characters.\n", lNum, wNum, cNum);
}
