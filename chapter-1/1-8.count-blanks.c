/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 5, 2017
*
* count \t, \n and spaces
*/

#include <stdio.h>
 
main () {
	int c = 0;
	int spaceNum = 0;
	int tableNum = 0;
	int enterNum = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')  spaceNum++;
		if (c == '\t') tableNum++;
		if (c == '\n') enterNum++;
	}
	printf("%d space, %d table, %d enter.\n", spaceNum, tableNum, enterNum);
}
