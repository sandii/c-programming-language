#include <stdio.h>

void squeeze (char src[], char ban[]) {
	int reader = 0;
	int writer = 0;
	int rep = 0;
	int c = 0;
	for (int i = 0; (rep = ban[i]) != '\0'; i++) {
		for (reader = 0, writer = 0; (c = src[reader]) != '\0'; reader++) {
			if (c == rep) continue;
			src[writer++] = c;
		}
		src[writer] = '\0';
	}	
}

main () {
	char s[] = "U.S. President Barack Obama said Thursday to end a longstanding policy that granted residency to Cubans without visas. ccc";
	squeeze(s, "abc");
	printf("%s\n", s);
}
