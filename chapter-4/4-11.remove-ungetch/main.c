#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"


// deal with letters
double result = 0.0; // cache lattest printed value
void letter (char s[]) {
	double temp = 0.0;
	if (strcmp(s, "x") == 0) {
		push(result);
	} else if (strcmp(s, "pow") == 0) {
		temp = pop();
		push(pow(pop(), temp));
	} else if (strcmp(s, "sqrt") == 0) {
		push(sqrt(pop()));
	} else if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	} else if (strcmp(s, "exp") == 0) {
		push(exp(pop()));
	} else {
		printf("input error..\n");
	}
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
			case LETTER:
				letter(s);
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

			// print result
			case '\n':
				result = pop();
				printf("%.8g\n", result);
				break;
			default:
				printf("input error..\n");
		}
	}
}
