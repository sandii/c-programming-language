/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 22, 2017
*
* substring's index in string, left to right
*/

#include <stdio.h>
#include <string.h>

int strindex (char* str, char* sub) {
	char* _str = str;
	char* _sub = sub;
	for ( ; *str != '\0'; str++) {
		if (*str != *sub) {
			sub = _sub;
			continue;
		}
		sub++;
		if (*sub == '\0') {
			return str - _str - strlen(_sub) + 1;
		}
	}
	return -1;
}

main () {
	char str[] = "hello world!";
	char a[] = "orl";
	char b[] = "eel";
	printf("%d\n", strindex(str, a));
	printf("%d\n", strindex(str, b));
}
