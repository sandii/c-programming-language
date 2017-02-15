/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 15, 2017
*
* reverse polish calculator using scanf and sscanf
*/

#include <stdio.h>
#include <string.h>	// strchr strcmp

#define MAX_WORD_LEN 100
char word[MAX_WORD_LEN + 1];

#define MAX_STACK_SIZE 100
float stack[MAX_STACK_SIZE];
float* sp = stack;

float pop () {
	if (sp == stack) {
		printf("empty stack..\n");
		return 0.0;
	}
	return *--sp;
}
void push (float f) {
	if (sp - stack >= MAX_STACK_SIZE) {
		printf("stack full..\n");
		return;
	}
	*sp++ = f;
}

#define NUMBER 1
int getop (float* fp) {
	scanf("%s", word);
	if (strchr(word, EOF) != NULL) return EOF;
	if (strcmp(word, "+")  == 0)   return '+';
	if (strcmp(word, "-")  == 0)   return '-';
	if (strcmp(word, "*")  == 0)   return '*';
	if (strcmp(word, "/")  == 0)   return '/';
	if (strcmp(word, "=")  == 0)   return '=';
	sscanf(word, "%g", fp);
	return NUMBER;
}

main () {	
	float f = 0.0;
	int type = NUMBER;
	while ((type = getop(&f)) != EOF) {
		switch (type) {
			case NUMBER:
				push(f);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				f = pop();
				push(pop() - f);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				f = pop();
				if (f == 0.0) {
					printf("divisor cannot be zero..\n");
					break;
				}
				push(pop() / f);
				break;
			case '=':
				printf("%.8g\n", pop());
				break;
			default:
				break;
		}
	}
}
