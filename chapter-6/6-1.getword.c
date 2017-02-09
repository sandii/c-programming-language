/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 9, 2017
*
* get word of user input
* - handle properly underscore (_)
* - ignore comments
* - ignore string constant ("abcd")
* - ignore lines leading with # (#abcd)
*/

#include <stdio.h>
#include <ctype.h>

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
					if (c == '/' && readyToEnd) break;
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

main () {
	while (getword() != EOF) {
		printf("%s\n", word);		
	}
}
