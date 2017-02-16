/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 18, 2017
*
* a reverse polish calculator
* add support for % and negative number
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// stack
#define STACK_SIZE 100
double stack[STACK_SIZE];
int stackReader = 0;
double pop () {
	if (!stackReader) {
		printf("empty stack..\n");
		return 0.0;
	}
	stackReader--;
	return stack[stackReader];
	
}
void push (double g) {
	if (stackReader == STACK_SIZE) {
		printf("full stack..\n");
		return;
	}
	stack[stackReader] = g;
	stackReader++;
}


// buffer
#define BUFF_SIZE 100
char buff[BUFF_SIZE];
int buffReader = 0;
int getch () {
	if (buffReader > 0) {
		buffReader--;
		return buff[buffReader];
	} else {
		return getchar();
	}
}
void ungetch (char c) {
	if (buffReader == BUFF_SIZE) {
		printf("full buffer\n");
		return;
	}
	buff[buffReader] = c;
	buffReader++;
}

// read user input
#define NUMBER '0'
int getop (char s[]) {
	int c = 0;

	//skip spaces
	while ((c = getch()) == ' ' || c == '\t') {
		;
	}

	// not a number
	if (!isdigit(c) && c != '.' && c != '-') return c;

	// deal with '-' specificly
	int i = 0;
	if (c == '-') {
		int next = getch();
		if (isdigit(next)) {
			s[i] = c;
			i++;
			s[i] = next;
			i++;
			c = getch();
		} else {
			ungetch(next);
			return c;
		}
	}
	
	// deal with number
	while (isdigit(c)) {
		s[i] = c;
		i++;
		c = getch();
	}
	if (c == '.') {
		s[i] = c;
		i++;
		c = getch();
	}
	while (isdigit(c)) {
		s[i] = c;
		i++;
		c = getch();
	}
	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}


main () {
	char s[100];
	int type = NUMBER;
	double temp = 0.0;
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(0 - (pop() - pop()));
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				temp = pop();
				if (temp == 0.0) {
					printf("divisor cannot be zero..\n");
				}
				push(pop() / temp);
				break;
			case '%':
				temp = pop();
				if (temp == 0) {
					printf("modulus cannot be zero..\n");
				}
				push(fmod(pop(), temp));
				break;
			case '\n':
				printf("%.8g\n", pop());
				stackReader = 0;
				buffReader = 0;
				break;
			default:
				printf("input error..\n");
				stackReader = 0;
				buffReader = 0;
		}
	}
}
