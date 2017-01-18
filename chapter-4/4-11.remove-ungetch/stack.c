#include <stdio.h>
#include "calc.h"

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

