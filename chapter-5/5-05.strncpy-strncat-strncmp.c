#include <stdio.h>

void strncpy (char* s, char* t, int n) {
	for (int i = 0; i < n; i++) {
		if (*t == '\0') break;
		*s = *t;
		s++; t++;
	}
	*s = '\0';
}
void strncat (char* s, char* t, int n) {
	for ( ; *s; s++) ;
	strncpy(s, t, n);
}
int strncmp (char* s, char* t, int n) {
	for (int i = 0; i < n; i++) {
		if (*t == '\0') break;
		if (*t != *s) return *s - *t;
		t++; s++;
	}
	return 0;
}

main () {
	char s[100] = "halo!";
	printf("%s\n", s);

	strncpy(s, "hello world! yes!", 12);
	printf("%s\n", s);
	
	strncat(s, " i'm sandii! nice to meet you!", 12);
	printf("%s\n", s);
	
	printf("%d\n", strncmp(s, "hello", 4));
	printf("%d\n", strncmp(s, "hahaha", 5));
}
