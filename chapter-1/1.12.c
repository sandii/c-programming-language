#include <stdio.h>

// output every word in a new line
#define IN  1
#define OUT 0

main () {
	int c = 0;
	int state = OUT;
	while ((c = getchar()) != EOF) {
		bool isEmpty = c == '\n' || c == '\t' || c == ' ';
		if (state == OUT && !isEmpty) {
			state = IN;
			printf("\n");
		}
		if (!isEmpty) {
			putchar(c);
		}
		if (isEmpty) {
			state = OUT;
		}
	}
}
