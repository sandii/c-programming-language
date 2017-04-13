/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Apr 12, 2017
*
* count number of 1
*
*/

#include <stdio.h>

int bitcount (unsigned x) {
	int n = 0;

	// while (x) {
	// 	if (x & 1 == 1) n++;
	// 	x >>= 1;
	// }

	for ( ; x; x &= (x - 1)) {
		n++;
	}
	return n;
}

main () {
	printf("%d\n", bitcount(8));
	printf("%d\n", bitcount(9));
	printf("%d\n", bitcount(12));
	printf("%d\n", bitcount(15));
}
