#include <stdio.h>

// output the input
// merge multi-spaces into one 
main () {
	int last = 0;
	int curr = 0;
	while ((curr = getchar()) != EOF) {
		if (curr == ' ' && last == ' ') continue;
		last = curr;
		putchar(curr);
	}
}
