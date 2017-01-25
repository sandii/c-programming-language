/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 25, 2017
*
* reverse polish calculator that receive command line arguments
* command line has some problem with * and /
* so use 'x' and 'd' instead
* i.e.
* $ expr.o 2 3 5 + x => (5 + 3) * 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int* sp = stack;
int pop () {
	if (sp - stack == 0) {
		printf("empty stack..\n");
		return 0;
	}
	sp--;
	return *sp;
}
void push (int n) {
	if (sp - stack == MAXSIZE + 1) {
		printf("full stack..\n");
		return;
	}
	*sp = n;
	sp++;
}

void add () {
	push(pop() + pop());
}
void cut () {
	int temp = pop();
	push(pop() - temp);
}
void time () {
	push(pop() * pop());
}
void divide () {
	int temp = pop();
	if (temp == 0) {
		printf("error: cannot divide zero\n");
		push(temp);
	} else {
		push(pop() / temp);	
	}
}

main (int argc, char* argv[]) {
	if (argc == 1) {
		printf("Usage: reverse polish calculator\n");
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		argv++;
		char* p = *argv;
		while (isspace(*p)) {
			p++;
		}
		if (*p == '-' && isdigit(*(p + 1))) {
			push(atoi(p));
			continue;
		}
		if (isdigit(*p)) {
			push(atoi(p));
			continue;
		}
		if (*p == '+') add();
		if (*p == '-') cut();
		if (*p == 'x') time();
		if (*p == 'd') divide();
	}

	printf("%d\n", pop());
	return 0;
}
