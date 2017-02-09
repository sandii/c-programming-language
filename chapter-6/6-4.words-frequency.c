/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* print word frequecy list in descending order
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h> // strcmp

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

	while (isalpha(c) || c == '_') {
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

struct tnode* addTree ()

main () {
	struct tnode* root = NULL;
	while (getword() != EOF) {
		root = addTree(root, word);
	}
	printTree(root);
}
