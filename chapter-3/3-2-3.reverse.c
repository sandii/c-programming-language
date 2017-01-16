#include <stdio.h>
#include <string.h>

void reverse (char src[], char dst[]) {
	int len = strlen(src);
	dst[len] = '\0';
	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		dst[i] = src[j];
		dst[j] = src[i];
	}
}

main () {
	char dst[100];
	reverse("abcdefghi", dst);
	printf("%s\n", dst);
}
