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

int getfloat (double* p) {
	int c = 0;
	// skip spaces
	while (isspace(c = getch())) {
		;
	}
	// is not digit
	if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
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
	int power = 0;
	while (isdigit(c)) {
		*p = *p * 10 + (c - '0');
		c = getch();
	}
	if (c == '.') {
		c = getch();
	}
	while (isdigit(c)) {
		*p = *p * 10 + (c - '0');
		c = getch();
		power++;
	}
	for (int i = 0; i < power; i++) {
		*p *= 0.1;
	}
	*p *= sign;

	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

main () {
	double a = 0.0;
	getfloat(&a);
	printf("%g\n", a * 2);
	printf("%g\n", pow(a, 2));
}
