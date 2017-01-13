#include <stdio.h>

int any (char src[], char reg[]) {
	int regCur = 0;
	int c = 0;
	for (int srcCur = 0; (c = src[srcCur]) != '\0'; srcCur++) {
		if (c != reg[regCur]) {
			regCur = 0;
			continue;
		}
		regCur++;
		if (reg[regCur] == '\0') {
			return srcCur - regCur + 1;
		}
	}
	return -1;
}

main () {
	char s[] = "U.S. President Barack Obama said Thursday to end a longstanding policy that granted residency to Cubans without visas.";
	int n1 = any(s, "U.S.");
	int n2 = any(s, "Obama");
	int n3 = any(s, "Trump");
	int n4 = any(s, "withddd");
	printf("%d %d %d %d\n", n1, n2, n3, n4);
}
