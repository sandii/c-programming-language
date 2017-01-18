#include <ctype.h>
#include "calc.h"

int getop (char s[]) {
	int c = 0;
	int i = 0;

	//skip spaces
	while ((c = getch()) == ' ' || c == '\t') {
		;
	}

	// deal with letters
	i = 0;
	if (isalpha(c)) {
		while (isalpha(c)) {
			s[i++] = c;
			c = getch();
		}
		s[i] = '\0';
		if (c != EOF) {
			ungetch(c);
		}
		return LETTER;
	}
	

	// normal operator
	if (!isdigit(c) && c != '.' && c != '-') return c;

	// deal with '-' specificly
	i = 0;
	if (c == '-') {
		int next = getch();
		if (isdigit(next)) {
			s[i++] = c;
			s[i++] = next;
			c = getch();
		} else {
			ungetch(next);
			return c;
		}
		s[i] = '\0';
		if (c != EOF) {
			ungetch(c);
		}
		return LETTER;
	}
	
	// deal with number
	while (isdigit(c)) {
		s[i++] = c;
		c = getch();
	}
	if (c == '.') {
		s[i++] = c;
		c = getch();
	}
	while (isdigit(c)) {
		s[i++] = c;
		c = getch();
	}
	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}