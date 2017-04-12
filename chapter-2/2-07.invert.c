/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Apr 12, 2017
*
* from right position p of x, turn n bits from 1 to 0, 0 to 1
*/

#include <stdio.h>

int invert (int x, int p, int n) {
	int mask = ~(~0 << n) << (p - n);	// 00001100
	int target = x & mask;				// get target bits from x
	int inverted = ~target & mask;		// invert target bits
	x = x & ~mask;						// remove target bits in x
	return x | inverted;				// combine
}

main () {
	printf("%d\n", invert(8, 4, 2));
	printf("%d\n", invert(15, 3, 3));
}
