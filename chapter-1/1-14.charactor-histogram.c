/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 6, 2017
*
* count charactors, print histogram
*/

#include <stdio.h>

#define LEN 40

main () {
	int c = 0;
	int key[LEN];
	int val[LEN];
	int width = 0;
	int height = 0;
	for (int i = 0; i < LEN; i++) {
		key[i] = EOF;
		val[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') continue;
		bool exist = false;
		int i = 0;
		for (i = 0; key[i] != EOF; i++) {
			if (key[i] == c) {
				val[i]++;
				exist = true;
				break;
			}
		}
		if (exist) continue;
		key[i] = c;
		val[i] = 1;
		width = i + 1;
	}

	//print
	for (int i = 0; i < width; i++) {
		if (val[i] <= height) continue;
		height = val[i];
	}
	for (int i = height; i > 0; i--) {
		for (int j = 1; j < width; j++) {
			if (val[j] >= i) {
				printf(" *");
			}else {
				printf("  ");
			}			
		}
		printf("\n");
	}
	for (int i = 1; i < width; i++) {
		printf("%2d", val[i]);
	}
	printf("\n");
	for (int i = 1; i < width; i++) {
		printf("%2c", key[i]);
	}
	printf("\n");
}
