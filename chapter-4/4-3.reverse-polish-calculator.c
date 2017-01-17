#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define STACK_SIZE 100
#define BUFF_SIZE 100

// stack
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
char buff[BUFF_SIZE];
int buffReader = 0;
int getch () {
	if (buffReader) {
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
int getop (char s[]) {
	int c = 0;

	//skip spaces
	while (isspace(c = getch())) {
		;
	}
	// not a number
	if (!isdigit(c) && c != '.') return c;
	
	// deal with number
	int i = 0;
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
	int type;
	while ((type = getop(s)) != EOF) {
		if (type == '\n') printf("11");
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
				double divisor = pop();
				if (divisor == 0.0) {
					printf("divisor cannot be zero..\n");
				}
				push(pop() / divisor);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("input error..\n");
		}
	}
}
