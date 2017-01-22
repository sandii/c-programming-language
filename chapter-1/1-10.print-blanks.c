/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 5, 2017
*
* output the input
* emphasize \t \b and \
*/

#include <stdio.h>

main () {
	int c = 0;
	int o = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
			continue;
		}
		if (c == '\b') {
			printf("\\b");
			continue;
		}
		if (c == '\\') {
			printf("\\\\");
			continue;
		}
		putchar(c);
	}
}
