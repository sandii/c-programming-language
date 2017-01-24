/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 5, 2017
*
* output the input
* merge multi-spaces into one
*/

#include <stdio.h>

main () {
	int last = 0;
	int curr = 0;
	while ((curr = getchar()) != EOF) {
		if (curr == ' ' && last == ' ') continue;
		last = curr;
		putchar(curr);
	}
}
