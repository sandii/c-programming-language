#include <stdio.h>

main () {
	int c = 0;
	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	printf("%d\n", EOF);	// -1
	printf("%d\n", (getchar() != EOF));	//0
}
