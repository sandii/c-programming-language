/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 24, 2017
*
* sort strings with strcmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_NUM 10
#define MAX_LINE_LEN 100
#define MAX_CHAR_NUM 1000

int getline (char* p) {
	int len;
	for (len = 0; len < MAX_LINE_LEN - 1; len++) {
		int c = getchar();
		if (c == '\n' || c == EOF) break;
		*p = c;
		p++;
	}
	*p = '\0';
	return len;
}

char allocArr[MAX_CHAR_NUM];
char* allocP = allocArr;
char* alloc (int len) {
	if (allocP - allocArr + len > MAX_CHAR_NUM) return NULL;
	allocP += len;
	return allocP - len;
}

int getlines (char** lines) {
	char line[MAX_LINE_LEN];
	int lineNum = 0;
	int lineLen = 0;
	while (lineLen = getline(line)) {
		char* p = alloc(lineLen + 1);
		if (p == NULL) return -1;
		strcpy(p, line);
		*(lines + lineNum) = p;
		lineNum++;
	}
	return lineNum > MAX_LINE_NUM ? -1 : lineNum;
}

void swap (char** lines, int i, int j) {
	if (i == j) return;
	char* temp = *(lines + i);
	*(lines + i) = *(lines + j);
	*(lines + j) = temp;
}

void qsort (char** lines, int left, int right) {
	if (left >= right) return;
	int pivot = (left + right) / 2;
	swap(lines, pivot, left);
	pivot = left;
	char* v = *(lines + left);
	for (int i = left + 1; i <= right; i++) {
		if (strcmp(v, *(lines + i)) <= 0) continue;
		pivot++;
		swap(lines, pivot, i);
	}
	swap(lines, left, pivot);
	qsort(lines, left, pivot - 1);
	qsort(lines, pivot + 1, right);
}

main () {
	char* lines[MAX_LINE_NUM];
	int lineNum = getlines(lines);
	if (lineNum == -1) printf("error: too many lines to sort..\n"); 
	qsort(lines, 0, lineNum - 1);
	for (int i = 0; i < lineNum; i++) {
		printf("%s\n", *(lines + i));
	}
}
