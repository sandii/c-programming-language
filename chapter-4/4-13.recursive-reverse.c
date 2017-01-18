#include <stdio.h>
#include <string.h>

void reverse (char s[], int i, int j) {
	if (i > j) return;
	int temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	
	i++;
	j--;
	reverse(s, i, j);
}

main () {
	char s[] = "abcdefghijk";
	reverse(s, 0, strlen(s) - 1);
	printf("%s\n", s);
}