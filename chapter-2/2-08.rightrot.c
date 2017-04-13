/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Apr 12, 2017
*
* move n bits of x rightwards
* insert moveout bits to left side of x
*/

#include <stdio.h>

int intsize = sizeof(int) * 8;

int rightrot (int x, int n) {
	int mask = ~(~0 << n);			// 00000011
	int bits = x & mask;			// get moveout bits
	bits = bits << (intsize - n);	// move bits to left side
	x = x >> n;						// move x rightwards
	return x | bits;				// combine
}

main () {
	printf("%d\n", rightrot(8, 2));
	printf("%d\n", rightrot(15, 3));
}
