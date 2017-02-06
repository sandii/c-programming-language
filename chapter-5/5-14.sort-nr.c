/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 6, 2017
*
* sort strings
* -n for numberic
* -r for reverse
*/

#include <stdio.h>
#include <stdlib.h>	// atof
#include <string.h>	// strchr strcmp

bool isNumberic = false;
bool isReverse = false;

void getArg (int argc, char* argv[]) {
	if (argc == 1) return;
	char** p = argv;
	p++;
	if (**p != '-') return;
	if (strchr(*p, 'n')) isNumberic = true;
	if (strchr(*p, 'r')) isReverse  = true;
}

#define MAX_CHAR_NUM 1000
#define MAX_LINE_NUM 20

char  chArr[MAX_CHAR_NUM];
char* lnArr[MAX_LINE_NUM + 1];
char*  chp = chArr;
char** lnp = lnArr;

int getline () {
	int c = 0;
	int len = 0;
	while ((c = getchar()) != '\n') {
		if (chp - chArr >= MAX_CHAR_NUM) {
			printf("too many characters..\n");
			return 0;
		}
		*chp = c;
		chp++; len++;
	}
	if (!len) return len;

	*chp = '\0';
	chp++; len++;
	return len;
}

void input () {
	int len = 0;
	while (len = getline()) {
		if (lnp - lnArr >= MAX_LINE_NUM) {
			printf("too many lines..\n");
			return;
		}
		*lnp = chp - len;
		lnp++;
	}
	*lnp = NULL;
}

void swap (int i, int j) {
	char** temp = lnArr[i];
	lnArr[i] = lnArr[j];
	lnArr[j] = temp;
}

void qsort (left, right) {}

void output () {
	lnp = lnArr;
	while (*lnp != NULL) {
		printf("%s\n", *lnp);
		lnp++;
	}
}

main (int argc, char* argv[]) {
	getArg(argc, argv);
	input();
	qsort(0, lnp - lnArr);
	output();
}
