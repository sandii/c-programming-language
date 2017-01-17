#include <stdio.h>
#include <string.h>

// trim string

void trim (char s[]) {
	int len = strlen(s);
	int reader = 0;
	int writer = 0;
	int c = 0;

	// trim right
	for (reader = len - 1; reader >= 0; reader--) {
		c = s[reader];
		if (c != ' ' && c != '\t' && c != '\n') break;
	}
	writer = reader + 1;
	s[writer] = '\0';

	// trim left
	len = strlen(s);
	for (reader = 0; reader < len; reader++) {
		c = s[reader];
		if (c != ' ' && c != '\t' && c != '\n') break;
	}
	if (reader == 0) return;
	for (writer = 0; reader < len; reader++, writer++) {
		s[writer] = s[reader];
	}
	s[writer] = '\0';
}

main () {
	char a[] = "  dfsd sd   \t  ";
	printf("string length: %d\n", strlen(a));
	
	trim(a);
	printf("%s\n", a);
	
	printf("string length: %d\n", strlen(a));
}
