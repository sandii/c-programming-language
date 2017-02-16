/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 15, 2017
*
* judge character is uppercase or not,
* - time-efficient plan
* - space-efficient plan
*/

#include <stdio.h>

#define SPACE_LEN 256
int space[SPACE_LEN];

int isupperSaveSpace (int c) {
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int isupperSaveTime (int c) {
	return space[c];
}

main (int argc, char* argv[]) {
	// init
	for (int i = 0; i < SPACE_LEN; i++) {
		space[i] = isupperSaveSpace(i);
	}

	// run
	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') continue;
		printf("%s\n", isupperSaveTime(c)  ? "true" : "false");
		printf("%s\n", isupperSaveSpace(c) ? "true" : "false");
	}
}
