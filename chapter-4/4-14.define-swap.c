/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 19, 2017
*
* define function swap
*/

#include <stdio.h>

#define swap(type, a, b) {type temp; temp = a; a = b; b = temp;}

main () {
	int a = 1;
	int b = 2;
	printf("%d %d\n", a, b);
	swap(int, a, b);
	printf("%d %d\n", a, b);

	double c = 1.0;
	double d = 2.0;
	printf("%g %g\n", c, d);
	swap(double, c, d);
	printf("%g %g\n", c, d);
}

