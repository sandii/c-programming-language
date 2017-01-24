/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 16, 2017
*
* escape or unescape \n and \t
*/

#include <stdio.h>

void escape (char src[], char dst[]) {
	int c = 0;
	int reader = 0;
	int writer = 0;
	while ((c = src[reader]) != '\0') {
		switch (c) {
			case '\t':
				dst[writer++] = '\\';
				dst[writer++] = 't';
				break;
			case '\n':
				dst[writer++] = '\\';
				dst[writer++] = 'n';
				break;
			default:
				dst[writer++] = c;
		}
		reader++;
	}
	dst[writer] = '\0';
}
void unescape (char src[], char dst[]) {
	int c = 0;
	int reader = 0;
	int writer = 0;
	bool slashed = false;
	while ((c = src[reader]) != '\0') {
		switch (c) {
			case '\\':
				if (slashed) {
					dst[writer++] = '\\';
					slashed = false;
				} else {
					slashed = true;					
				}
				break;
			case 'n':
				if (slashed) {
					dst[writer++] = '\n';
					slashed = false;
					break;
				}
			case 't':
				if (slashed) {
					dst[writer++] = '\t';
					slashed = false;
					break;
				}
			default:
				slashed = false;
				dst[writer++] = c;
		}
		reader++;
	}
	dst[writer] = '\0';
}


main () {
	char dst[1000];
	escape("Our binary 		 search makes two tests inside the loop,\n when one would suffice (at the price of more tests outside). Write a version with", dst);
	printf("%s\n\n\n\n", dst);

	unescape("Our binary\\t\\tsearch\\nmakes two tests \\\\ inside the loop,\\n when one would suffice (at the price of more tests out\\\\side). Write a version with", dst);
	printf("%s\n", dst);
}
