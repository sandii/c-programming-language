/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 25, 2017
*
* print last n lines of user input
*/
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_NUM 20
#define MAX_CHAR_NUM 1000

char ch[MAX_CHAR_NUM];
char* chp = ch;
char* lnpArr[MAX_LINE_NUM];
char** lnp = lnpArr;

int getline () {
	char c = 0;
	int len = 0;
	while ((c = getchar()) != '\n') {
		if (chp - ch >= MAX_CHAR_NUM - 1) {
			printf("warn: too many words..\n");
			return 0;
		}
		*chp = c;
		chp++; len++;
	}
	if (!len) return 0; // empty line

	*chp = '\0';
	chp++; len++;
	return len;
}
void input () {
	int len = 0;
	while (len = getline()) {
		if (lnp - lnpArr > MAX_LINE_NUM) {
			printf("warn: too many lines..\n");
			return;
		}
		*lnp = chp - len;
		lnp++;
	}
	*lnp = NULL; // no more lines
}
void output (int n) {
	printf("\n");
	lnp = (lnp - lnpArr <= n) ? lnpArr : lnp - n; 
	for ( ; *lnp != NULL; lnp++) {
		printf("%s\n", *lnp);
	}
}

main (int argc, char* argv[]) {
	if (argc == 1) {
		printf("Usage: print last n lines\n");
		return 1;
	}
	char* p = *++argv;
	if (*p != '-') {
		printf("Usage: expect a param -n, n should be integer\n");
		return 1;
	}
	int n = 0;
	while (isdigit(*++p)) {
		n = n * 10 + (*p - '0');
	}
	n = n ? n : 10;
	input();
	output(n);
	return 0;
}

