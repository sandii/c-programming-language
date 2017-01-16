#include <stdio.h>

// a-c => abc

void expand (char src[], char dst[]) {
	int reader = 0;
	int writer = 0;
	int c = 0;
	for ( ; (c = src[reader]) != '\0'; reader++) {
		if (c != '-' || reader == 0) {
			dst[writer] = c;
			writer++;
			continue;
		}
		int prev = src[reader - 1];
		int next = src[reader + 1];
		if (prev == ' ' || next == ' ' || next == '\0') {
			dst[writer] = c;
			writer++;
			continue;
		}

		for (int curr = prev + 1; curr <= next; curr++) {
			dst[writer] = curr;
			writer++;
		}
	}
	dst[writer] = '\0';
}

main () {
	char dst[100];
	expand("a-d yes it is 1-9", dst);
	printf("%s\n", dst);
	expand("a-g-q- dd -0-9 a-b-f dd", dst);
	printf("%s\n", dst);
}
