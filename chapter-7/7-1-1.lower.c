/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 13, 2017
*
* convert between lower-case and upper-case
* according to argv[0]
*/

#include <stdio.h>
#include <string.h>	// strstr
#include <ctype.h>	// tolower toupper

main (int argc, char* argv[]) {
	bool isLower = strstr(argv[0], "lower") == NULL ? false : true;
	bool isUpper = strstr(argv[0], "upper") == NULL ? false : true;

	char c;
	while ((c = getchar()) != EOF) {
		if (isLower) c = tolower(c);
		if (isUpper) c = toupper(c);
		putchar(c);
	}
}
