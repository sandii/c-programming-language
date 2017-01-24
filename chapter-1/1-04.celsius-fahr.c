/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 4, 2017
*
* celsius to fahrenheit
*/

#include <stdio.h>

main () {
	float fahr = 0.0;
	float celsius = 0.0;

	printf("celsius  -  fahrenheit\n\n");
	for (; celsius < 100.0; celsius += 10.0) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%8.1f\t%5.1f\n", celsius, fahr);
	}
}
