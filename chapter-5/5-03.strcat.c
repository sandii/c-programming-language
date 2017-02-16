/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 20, 2017
*
* strcat
*/

#include <stdio.h>

void strcat (char* s, char* t) {
	for ( ; *s; s++) ;
	for ( ; *s = *t; s++, t++) ;
	*s = '\0';
}

main () {
	char s[100] = "123 ";
	printf("%s\n", s);
	strcat(s, " T_T "); printf("%s\n", s);
	strcat(s, " *_* "); printf("%s\n", s);
	strcat(s, " -_- "); printf("%s\n", s);
}
