/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* print word frequecy list in descending order
*/

#include <stdio.h>
#include <stdlib.h>	// malloc
#include <ctype.h>	// isalpha
#include <string.h> // strcmp strlen strcpy

#define MAX_WORD_LEN 100
char word [MAX_WORD_LEN];

int buff;
int getch () {
	if (buff == -1) {
		return getchar();
	} else {
		int c = buff;
		buff = -1;
		return c;
	}
}
void ungetch (int c) {
	buff = c;
}

int getword () {
	char* wp = word;
	int c;

	while (!isalpha(c = getch())) {
		if (c == EOF) return c;
	}

	while (isalpha(c)) {
		*wp = c;
		wp++;
		if (wp - word >= MAX_WORD_LEN - 1) break;
		c = getch();
	}
	ungetch(c);
	*wp = '\0';
	return word[0];
}

struct tnode {
	char* word;
	int count;
	struct tnode* left;
	struct tnode* right;
};
#define TNODE_SIZE (sizeof (struct tnode))

struct tnode* addTree (struct tnode* p, char* w) {
	if (p == NULL) {
		p = (struct tnode*) malloc(TNODE_SIZE);
		p -> word = (char*) malloc(strlen(w));
		strcpy(p -> word, w);
		p -> count = 1;
		p -> left = NULL;
		p -> right = NULL;
		return p;
	}

	int rs = strcmp(w, p -> word);
	if (rs == 0) {
		p -> count++;
	} else if (rs < 0) {
		p -> left = addTree(p -> left, w);
	} else {
		p -> right = addTree(p -> right, w);
	}
	return p;
}
void printTree (struct tnode* p) {
	if (p == NULL) return;
	printTree(p -> left);
	printf("%2d - %s\n", p -> count, p -> word);
	printTree(p -> right);
}

int tnodeNum = 0;
void countTnode (struct tnode* p) {
	if (p == NULL) return;
	tnodeNum++;
	countTnode(p -> left);
	countTnode(p -> right);
}

int tnodeWriter = 0;
void getTnodeArr (struct tnode* p, struct tnode* arr[]) {
	if (p == NULL) return;
	arr[tnodeWriter++] = p;
	getTnodeArr(p -> left, arr);
	getTnodeArr(p -> right, arr);
}

void swap (struct tnode* arr[], int i, int j) {
	struct tnode* temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void qsort (struct tnode* arr[], int left, int right) {
	if (left >= right) return;
	int pivot = (left + right) / 2;
	int pv = arr[pivot] -> count;
	swap(arr, left, pivot);
	pivot = left;
	for (int i = left + 1; i <= right; i++) {
		if (pv <= arr[i] -> count) continue;
		pivot++;
		swap(arr, pivot, i);
	}
	swap(arr, left, pivot);
	qsort(arr, left, pivot - 1);
	qsort(arr, pivot + 1, right);
}

main () {
	struct tnode* root = NULL;
	while (getword() != EOF) {
		root = addTree(root, word);
	}
	printTree(root);

	printf("-------\n");

	countTnode(root);
	struct tnode* arr[tnodeNum];
	getTnodeArr(root, arr);
	qsort(arr, 0, tnodeNum - 1);
	for (int i = 0; i < tnodeNum; i++) {
		printf("%2d - %s\n", arr[i] -> count, arr[i] -> word);
	}
}
