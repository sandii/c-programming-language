/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 7, 2017
*
* sort strings
* -n for numberic
* -r for reverse
* -f for case insensitive
* -d for directory order (compare digit, letter and space only)
*/

#include <stdio.h>
#include <stdlib.h>	// atof abs
#include <string.h>	// strchr
#include <ctype.h>

bool isNumberic = false;
bool isReverse = false;
bool isCaseInsensitive = false;
bool isDirOrder = false;

bool isDirCh (char c) {
	if (c == '\0') true;
	if (isdigit(c) || isalpha(c) || isspace(c)) return true;
	return false;
}

int scmp (char* a, char* b) {
	do {
		if (isDirOrder) {
			while (!isDirCh(*a)) a++;
			while (!isDirCh(*b)) b++;
		}
		if (*a == *b) continue;
		if (isCaseInsensitive && abs(*a - *b) == 'a' - 'A') continue;
		if (*a > *b) return 1;
		if (*a < *b) return -1;
	} while (*++a && *++b);
	return 0;
}

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
	if (strchr(*p, 'n')) isNumberic = true;
	if (strchr(*p, 'r')) isReverse  = true;
	if (strchr(*p, 'f')) isCaseInsensitive = true;
	if (strchr(*p, 'd')) isDirOrder = true;
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
		char* a = ln[left];
		char* b = ln[i];

		int rs = isNumberic ? ncmp(a, b) : scmp(a, b);
		rs = isReverse ? -rs : rs;
		if (rs > 0) {
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
