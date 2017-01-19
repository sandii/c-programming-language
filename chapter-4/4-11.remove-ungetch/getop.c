#include <ctype.h>
#include "calc.h"

int getop (char s[]) {
	int c = 0;
	int i = 0;

	//skip spaces
	while ((c = getch(-1)) == ' ' || c == '\t') {
		;
	}

	// deal with letters
	i = 0;
	if (isalpha(c)) {
		while (isalpha(c)) {
			s[i++] = c;
			c = getch(-1);
		}
		s[i] = '\0';
		if (c != EOF) {
			getch(c);
		}
		return LETTER;
	}
	

	// normal operator
	if (!isdigit(c) && c != '.' && c != '-') return c;

	// deal with '-' specificly
	i = 0;
	if (c == '-') {
		int next = getch(-1);
		if (isdigit(next)) {
			s[i++] = c;
			s[i++] = next;
			c = getch(-1);
		} else {
			getch(next);
			return c;
		}
		s[i] = '\0';
		if (c != EOF) {
			getch(c);
		}
		return LETTER;
	}
	
	// deal with number
	while (isdigit(c)) {
		s[i++] = c;
		c = getch(-1);
	}
	if (c == '.') {
		s[i++] = c;
		c = getch(-1);
	}
	while (isdigit(c)) {
		s[i++] = c;
		c = getch(-1);
	}
	s[i] = '\0';

	if (c != EOF) {
		getch(c);
	}
	return NUMBER;
}