/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 17, 2017
*
* convert string to float
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

float atof (char s[]) {
	int len = strlen(s);
	float f = 0.0;
	int i = 0;
	int c = 0;
	
	// skip spaces
	for ( ; i < len; i++) {
		c = s[i];
		if (!isspace(c)) break;
	}

	// positive or negative
	int sign = c == '-' ? -1 : 1;
	if (c == '-' || c == '+') {
		i++;
	}

	// integer part
	for ( ; i < len; i++) {
		c = s[i];
		if (!isdigit(c)) break;
		f = 10.0 * f + (c - '0');
	}

	// fraction part
	if (c == '.') {
		i++;
	}
	int fractionCount = 0;
	for ( ; i < len; i++) {
		c = s[i];
		if (!isdigit(c)) break;
		f = 10.0 * f + (c - '0');
		fractionCount++;
	}
	float fractionPower = 1.0;
	for (int j = 0; j < fractionCount; j++) {
		fractionPower /= 10.0;
	}

	// exponent part
	if (c == 'e') {
		i++;
	}
	c = s[i];
	int exponentSign = c == '-' ? -1 : 1;
	if (c == '-' || c == '+') {
		i++;
	}
	int exponent = 0;
	for ( ; i < len; i++) {
		c = s[i];
		if (!isdigit(c)) break;
		exponent = 10 * exponent + (c - '0');
	}
	float exponentPower = 1.0;
	for (int j = 0; j < exponent; j++) {
		exponentPower *= 10.0;
	}
	if (exponentSign == -1) {
		exponentPower = 1.0 / exponentPower;
	}

	// result
	return f * fractionPower * exponentPower;
}

main () {
	printf("%.3f\n", atof("623.456"));
	printf("%.2f\n", atof("1.00"));
	printf("%.1f\n", atof("15"));
	printf("%.1f\n", atof("1.5e3"));
	printf("%.8f\n", atof("89e-8"));
}

