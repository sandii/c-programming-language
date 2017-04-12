/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Apr 12, 2017
*
* get n bits from rightmost side of y
* setting to right position p of x
*/

#include <stdio.h>

int setbits (int x, int p, int n, int y) {
	y = ~(~0 << n) & y;		// get rightmost bits of y
	y = (y << (p - n));		// make those bits in position
	x = x & ~(~(~0 << n) << (p - n));	// remove bits in x
	return x | y;			// combine 
}

main () {
	printf("%d\n", setbits(8, 4, 2, 15));
	printf("%d\n", setbits(15, 3, 3, 16));
}
