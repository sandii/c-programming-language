/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* count number of keywords in user input
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

	while (!isalpha(c = getch()) && c != '_') {
		if (c == EOF) return c;

		// string constant
		if (c == '"') {
			while ((c = getch()) != '"') {
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


struct key {
	char* word;
	int count;
};
// the array should be ordered
// otherwise binsearch won't work
struct key keytab[] = {
	{"break", 	0},
	{"for", 	0},
	{"int", 	0},
	{"var", 	0},
	{"while", 	0}
};
#define KEY_NUM (sizeof keytab / sizeof keytab[0])

struct key* binsearch () {
	struct key* low  = &keytab[0];
	struct key* high = &keytab[KEY_NUM];
	struct key* mid;
	while (low < high) {
		mid = low + (high - low) / 2; 	// adding two pointers is illegal
		int rs = strcmp(word, mid -> word);
		if (rs > 0) {
			low = mid + 1;
		} else if (rs < 0) {
			high = mid;
		} else {
			return mid;
		}
	}
	return NULL;
}

main () {
	struct key* keyp = keytab;
	while (getword() != EOF) {
		if (keyp = binsearch()) {
			keyp -> count++;
		}
	}
	for (int i = 0; i < KEY_NUM; i++) {
		keyp = &keytab[i];
		printf("%4d %s\n", keyp -> count, keyp -> word);
	}
}
