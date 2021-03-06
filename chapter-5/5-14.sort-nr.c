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

int (*compare)(char*, char*) = (int (*)(char*, char*))strcmp;
bool isReverse = false;

int ncmp (char* a, char* b) {
	double _a = atof(a);
	double _b = atof(b);
	if (_a < _b) return -1;
	if (_a ==_b) return 0;
	if (_a > _b) return 1;
}

void getArg (int argc, char* argv[]) {
	if (argc == 1) return;
	char** p = argv;
	p++;
	if (**p != '-') return;
	if (strchr(*p, 'n')) compare = ncmp;
	if (strchr(*p, 'r')) isReverse  = true;
}

#define MAX_CHAR_NUM 1000
#define MAX_LINE_NUM 20

char  ch[MAX_CHAR_NUM];
char* ln[MAX_LINE_NUM + 1];
char*  chp = ch;
char** lnp = ln;

int getline () {
	int c = 0;
	int len = 0;
	while ((c = getchar()) != '\n') {
		if (chp - ch >= MAX_CHAR_NUM) {
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
		if (lnp - ln >= MAX_LINE_NUM) {
			printf("too many lines..\n");
			return;
		}
		*lnp = chp - len;
		lnp++;
	}
	*lnp = NULL;
}

void swap (int i, int j) {
	if (i == j) return;
	char* temp = ln[i];
	ln[i] = ln[j];
	ln[j] = temp;
}

void qsort (int left, int right) {
	if (left >= right) return;	// only 1 element
	int pivot = (left + right) / 2;
	swap(left, pivot);
	pivot = left;
	for (int i = left + 1; i <= right; i++) {
		int rs = compare(ln[left], ln[i]);
		if ( (rs > 0 && !isReverse) || (rs < 0 && isReverse) ) {
			pivot++;
			swap(pivot, i);
		}
	}
	swap(left, pivot);
	qsort(left, pivot - 1);
	qsort(pivot + 1, right);
}

void output () {
	lnp = ln;
	while (*lnp != NULL) {
		printf("%s\n", *lnp);
		lnp++;
	}
}

main (int argc, char* argv[]) {
	getArg(argc, argv);
	input();
	qsort(0, lnp - ln - 1);
	output();
}
