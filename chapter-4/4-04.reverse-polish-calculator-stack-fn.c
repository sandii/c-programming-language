/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 18, 2017
*
* a reverse polish calculator
* add features:
* 1. print stack top operant - @
* 2. copy stack top operant - #
* 3. swap two stack top operants - $
* 4. clear stack - ^
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>



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
void printTop () {
	if (!stackReader) {
		printf("empty stack..\n");
		return;
	}
	double top = pop();
	printf("stack top is: %.8g\n", top);
	push(top);
}
void copyTop () {
	if (!stackReader) {
		printf("empty stack..\n");
		return;
	}
	double top = pop();
	push(top);
	push(top);
}
void swapTop () {
	if (stackReader < 2) {
		printf("not enough operants in stack..\n");
		return;
	}
	double top1 = pop();
	double top2 = pop();
	push(top1);
	push(top2);
}
void clearStack () {
	stackReader = 0;
	printf("stack cleared\n");
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

	// normal operator
	if (!isdigit(c) && c != '.' && c != '-') return c;

	// deal with '-' specificly
	int i = 0;
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


main () {
	char s[100];
	int type = NUMBER;
	double temp = 0.0;
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				if (!strlen(s)) {
					printf("input error..\n");
					break;	
				}
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

			// 1. print stack top operant - @
			case '@':
				printTop();
				break;
			// 2. copy stack top operant - #
			case '#':
				copyTop();
				break;
			// 3. swap two stack top operants - $
			case '$':
				swapTop();
				break;
			// 4. clear stack - ^
			case '^':
				clearStack();
				break;

			// print result
			case '\n':
				if (!stackReader) break;
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
