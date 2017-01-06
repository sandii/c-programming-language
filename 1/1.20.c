#include <stdio.h>

// detab : tab to space
#define LIMIT 100
#define TABSIZE 4

main () {
	char text[LIMIT] = "you\tare\tmy\tfire\nthe\tone\tdesire\nyou\tpack\tthe\tmorning\n\0";
	int count = 0;
	for (int i = 0; i < LIMIT; i++) {
		int c = text[i];
		if (c == '\0') break;
		if (c == '\t') {
			int num = TABSIZE - (count - 2) % TABSIZE;
			for (int j = 0; j < num; j++) {
				printf(" ");
			}
			count = 0;
		} else if (c == '\n') {
			printf("\n");
			count = 0;
		} else {
			printf("%c", c);
			count++;
		}
	}
	// printf("%s\n", text);

	return 0;
}
