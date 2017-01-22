/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 6, 2017
*
* count words length, print histogram
*/

#include <stdio.h>

#define IN  1
#define OUT 0

main () {
	int c = 0;
	int len = 0;
	int state = OUT;
	int wordLength[10];
	for (int i = 1; i < 10; i++) {
		wordLength[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		bool isEmpty = c == ' ' || c == '\t' || c == '\n';
		if (isEmpty) {
			if (state == IN) {
				state = OUT;
				wordLength[len]++;
			} else {
				continue;
			}
		} else {
			if (state == OUT) {
				state = IN;
				len = 1;
			} else {
				len++;
			}
		}
	}

	// horizontal
	for (int i = 1; i < 10; i++) {
		len = wordLength[i];
		printf("%d - %2d ", i, len);
		for (int j = 0; j < len; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	
	//vertical
	int max = 0;
	for (int i = 1; i < 10; i++) {
		len = wordLength[i];
		if (len <= max) continue;
		max = len;
	}
	for (int i = max; i > 0; i--) {
		for (int j = 1; j < 10; j++) {
			len = wordLength[j];
			if (len >= i) {
				printf(" *");
			}else {
				printf("  ");
			}			
		}
		printf("\n");
	}
	for (int i = 1; i < 10; i++) {
		printf("%2d", wordLength[i]);
	}
	printf("\n");
	for (int i = 1; i < 10; i++) {
		printf("%2d", i);
	}
	printf("\n");
}