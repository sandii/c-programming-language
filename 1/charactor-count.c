#include <stdio.h>

// count digit 1-9, white space and other charactors
main () {
	int c = 0;
	int spaceNum = 0;
	int otherNum = 0;
	int digitNum[10];
	for (int i = 0; i < 10; i++) {
		digitNum[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			spaceNum++;
		} else if (c > '0' && c < '9') {
			digitNum[c - '0']++;
		} else {
			otherNum++;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d - %d\n", i, digitNum[i]);
	}
	printf("space - %d\n", spaceNum);
	printf("other - %d\n", otherNum);
}