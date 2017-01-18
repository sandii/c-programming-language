#include <stdio.h>
#include "calc.h"

bool hasBuff = false;
char buff;
int getch () {
	if (hasBuff) {
		hasBuff = false;
		return buff;
	} else {
		return getchar();
	}
}
void ungetch (char c) {
	buff = c;
	hasBuff = true;
}