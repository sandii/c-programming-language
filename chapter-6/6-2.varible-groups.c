/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* I. print varibles c program source code
* - ignore comments
* - ignore string constant ("abc")
* - ignore char constant ('a')
* - ignore # leading lines
*
* II. classify these varibles into groups
* according to leading n letters
* n is program argument or default number 6
* 
* III. usage: 
* 6-2.varible-groups.o < src.c -2
*/

#include <stdio.h>
#include <stdlib.h>	// malloc atoi
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

	while (!isalpha(c = getch()) && c != '_') {
		if (c == EOF) return c;

		// string constant
		if (c == '"') {
			while ((c = getch()) != '"') {
				if (c == EOF) return c;
			}
		}

		// char constant
		if (c == '\'') {
			while ((c = getch()) != '\'') {
				if (c == EOF) return c;
			}
		}

		// # leading line
		if (c == '#') {
			while ((c = getch()) != '\n') {
				if (c == EOF) return c;
			}
		}

		// comment
		if (c == '/') {
			// //
			if ((c = getch()) == '/') {
				while ((c = getch()) != '\n') {
					if (c == EOF) return c;
				}	
			// /* ... */		
			} else if (c == '*') {
				bool readyToEnd = false;
				while (c = getch()) {
					if (c == EOF) return c;
					readyToEnd = c == '*';
					if ((c = getch()) == '/' && readyToEnd) break;
					ungetch(c);
				}
			}
		}
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
	struct tnode* left;
	struct tnode* right;
};
#define TNODE_SIZE (sizeof (struct tnode))

struct tnode* addTree (struct tnode* p, char* w) {
	if (p == NULL) {
		p = (struct tnode*) malloc(TNODE_SIZE);
		p -> word = (char*) malloc(strlen(w));
		strcpy(p -> word, w);
		p -> left = NULL;
		p -> right = NULL;
		return p;
	}

	int rs = strcmp(w, p -> word);
	if (rs < 0) p -> left = addTree(p -> left, w);
	if (rs > 0)	p -> right = addTree(p -> right, w);
	return p;
}

char* keywords[] = {
	"EOF",
	"NULL",
	"bool",
	"break",
	"char",
	"continue",
	"else",
	"false",
	"if",
	"int",
	"main",
	"return",
	"true",
	"void",
	"while"
};
#define KEYWORDS_NUM (sizeof keywords / sizeof keywords[0])
bool iskeyword (char* wp) {
	int low = 0;
	int high = KEYWORDS_NUM;
	while (low < high) {
		int mid = (low + high) / 2;
		int rs = strcmp(wp, keywords[mid]); 
		if (rs < 0) {
			high = mid;
		} else if (rs > 0) {
			low = mid + 1;
		} else {
			return true;
		}
	}
	return false;
}

int getArg (int argc, char* argv[]) {
	if (argc == 1) return 0;
	char* wp = argv[1];
	if (*wp != '-') return 0;
	return atoi(++wp);
}

void traverse (struct tnode* p, char* leading, int n) {
	if (p == NULL) return;
	traverse(p -> left, leading, n);
	if (strlen(p -> word) < n || strncmp(leading, p -> word, n) != 0) {
		strncpy(leading, p -> word, n);
		printf("\n");
	}
	printf("%s ", p -> word);
	traverse(p -> right, leading, n);
}

main (int argc, char* argv[]) {
	struct tnode* root = NULL;
	while (getword() != EOF) {
		if (iskeyword(word)) continue;
		root = addTree(root, word);
	}

	int n = getArg(argc, argv);
	n = n ? n : 6;
	char leading[n];
	traverse(root, leading, n);
}
