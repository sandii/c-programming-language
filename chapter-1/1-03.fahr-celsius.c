/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 4, 2017
*
* fahrenheit to celsius
*/

#include <stdio.h>

main () {
	float fahr = 0.0;
	float celsius = 0.0;

	printf("fahrenheit  -  celsius\n\n");
	for (; fahr < 200.0; fahr += 20.0) {
		celsius = (fahr - 32.0) * 5.0 / 9.0;
		printf("%8.1f\t%5.1f\n", fahr, celsius);
	}
}
