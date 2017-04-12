/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Apr 12, 2017
*
* get n bits from right position p
*/

#include <stdio.h>

unsigned getbits (unsigned x, int p, int n) {
	return (x >> (p - n)) & ~(~0 << n);
}

main () {
	printf("%d\n", getbits(8,  4, 2));
	printf("%d\n", getbits(15, 4, 3));
	printf("%d\n", getbits(7,  2, 2));
}
