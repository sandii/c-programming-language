/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 17, 2017
*
* index of string b in string a's right side
*/


#include <stdio.h>
#include <string.h>

int strindex (char a[], char b[]) {
	int lenA = strlen(a);
	int lenB = strlen(b);
	if (!lenA || !lenB) return -1;
	int readerA = lenA - 1;
	int readerB = lenB - 1;
	int charA = 0;
	int charB = 0;
	for ( ; readerA >= 0; readerA--) {
		charA = a[readerA];
		charB = b[readerB];
		if (charA != charB) {
			readerB = lenB - 1;
			continue;
		}
		if (readerB == 0) return readerA;
		readerB--;
	}
	return -1;
}

main () {
	printf("%d\n", strindex("yes it is", "it"));
	printf("%d\n", strindex("mont stanta monica", "mon"));
	printf("%d\n", strindex("mont stanta monica", "ss"));
}
