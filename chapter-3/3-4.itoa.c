#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int => string

void reverse (char s[]) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itoa (int n, char s[]) {
	int copy = n;
	int writer = 0;
	do {
		s[writer] = abs(n % 10) + '0';
		writer++;
		n /= 10;
	} while (n);

	if (copy < 0) {
		s[writer] = '-';
		writer++;
	}
	s[writer] = '\0';

	reverse(s);
}

main () {
	char dst[10];
	itoa(123, dst);		printf("%s\n", dst);
	itoa(-123, dst);	printf("%s\n", dst);
	itoa(53, dst);		printf("%s\n", dst);
}
