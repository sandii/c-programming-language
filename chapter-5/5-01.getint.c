/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 19, 2017
*
* get interger from user input
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFF_SIZE 100

int buff[BUFF_SIZE];
int buffReader = 0;
int getch () {
	return buffReader ? buff[--buffReader] : getchar();
}
void ungetch (int d) {
	if (buffReader == BUFF_SIZE) {
		printf("buffer full!\n");
		return;
	}
	buff[buffReader++] = d;	
}

int getint (int* p) {
	int c = 0;
	// skip spaces
	while (isspace(c = getch())) {
		;
	}
	// is not digit
	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}
	// sign
	int sign = c == '-' ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
	}

	// number
	*p = 0;
	while (isdigit(c)) {
		*p = *p * 10 + (c - '0');
		c = getch();
	}
	*p *= sign;

	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

main () {
	int a = 0;
	getint(&a);
	printf("%d\n", a * 2);
	printf("%g\n", pow(a, 2));
}
