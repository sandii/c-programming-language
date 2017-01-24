/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 23, 2017
*
* getchar() != EOF is 0 or 1
*/

#include <stdio.h>

main () {
	int d = 0;
	while (d = (int)(getchar() != EOF)) {
		printf("%d", d);
	}
	printf("%d\n", d);
}
