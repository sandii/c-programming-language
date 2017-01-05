#include <stdio.h>

// output the input
// emphasize \t \b and \
main () {
	int c = 0;
	int o = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
			continue;
		}
		if (c == '\b') {
			printf("\\b");
			continue;
		}
		if (c == '\\') {
			printf("\\\\");
			continue;
		}
		putchar(c);
	}
}
