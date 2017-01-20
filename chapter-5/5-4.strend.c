#include <stdio.h>
#include <string.h>

int strend (char* s, char* t) {
	int slen = strlen(s);
	int tlen = strlen(t);
	s += slen - 1;
	t += tlen - 1;
	for (int i = 0; i < tlen; i++) {
		if (*s != *t) return 0;
		s++; t++;
	}
	return 1;
}

main () {
	printf("%d\n", strend("T_T", "_T"));
	printf("%d\n", strend("Yes it is!", "is"));
}
