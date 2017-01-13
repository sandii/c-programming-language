#include <stdio.h>

int delta = 'a' - 'A';
void lower (char s[]) {
	int c = 0;
	for (int i = 0; (c = s[i]) != '\0'; i++) {
		s[i] = (c >= 'A' && c <= 'Z') ? c + delta : c;
	}
}

main () {
	char s1[] = "AAA";
	char s2[] = "US President Barack Obama";
	char s3[] = "trump is a typical businessman!";

	lower(s1);
	lower(s2);
	lower(s3);
	
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
}
