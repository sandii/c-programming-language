/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* print words and their line number list
*/

#include <stdio.h>
#include <stdlib.h>	// malloc
#include <ctype.h>	// isalpha tolower
#include <string.h> // strcmp strlen strcpy

#define MAX_WORD_LEN 100
#define MAX_LINE 10
char word [MAX_WORD_LEN];
int line = 1;

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
		if (c == '\n' && line < MAX_LINE) line++;
	}

	while (isalpha(c)) {
		if (c == '\n' && line < MAX_LINE) line++;
		*wp = c;
		wp++;
		if (wp - word >= MAX_WORD_LEN - 1) break;
		c = getch();
	}
	ungetch(c);
	*wp = '\0';
	return word[0];
}

void lowerWord () {
	for (char* wp = word; *wp != '\0'; wp++) {
		*wp = tolower(*wp);
	}
}
char* ignoreList[] = {
		"a",
		"and",
		"by",
		"in",
		"of",
		"on",
		"or",
		"the",
		"to"
	};
#define IGNORE_NUM sizeof ignoreList / sizeof ignoreList[0]
bool ignore (char* wp) {
	for (int i = 0; i < IGNORE_NUM; i++) {
		if(strcmp(wp, ignoreList[i]) == 0) return true;
	}
	return false;
}

struct tnode {
	char* word;
	bool line[MAX_LINE + 1];
	struct tnode* left;
	struct tnode* right;
};
#define TNODE_SIZE (sizeof (struct tnode))

struct tnode* addTree (struct tnode* p, char* w) {
	if (p == NULL) {
		p = (struct tnode*) malloc(TNODE_SIZE);
		p -> word = (char*) malloc(strlen(w));
		strcpy(p -> word, w);
		for (int i = 1; i < MAX_LINE + 1; i++) {
			p -> line[i] = false;
		}
		p -> line[line] = true;
		p -> left = NULL;
		p -> right = NULL;
		return p;
	}

	int rs = strcmp(w, p -> word);
	if (rs == 0) {
		p -> line[line] = true;
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
	printf("%12s   - ", p -> word);
	for (int i = 1; i < MAX_LINE + 1; i++) {
		if (!p -> line[i]) continue;
		printf("%3d", i);
	}
	printf("\n");
	printTree(p -> right);
}

main () {
	struct tnode* root = NULL;
	while (getword() != EOF) {
		lowerWord();
		if (ignore(word)) continue;
		root = addTree(root, word);
	}
	printTree(root);
}
