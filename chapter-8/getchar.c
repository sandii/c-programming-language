/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 20, 2017
*
* implement getchar of stdio.h
*/

#include <stdio.h>
#include <unistd.h>	// read BUFSIZ

int _getchar () {
	int c;
	int n = read(0, &c, 1);
	return n ? c : EOF;
} 

int __getchar () {
	static char buff[BUFSIZ];
	static char* buffp = buff;
	static int n = 0;
	if (n == 0) {
		n = read(0, buff, sizeof buff);
		buffp = buff;
	}
	if (n == 0) return EOF;
	int c = *buffp;
	buffp++;
	n--;
	return c; 
}

main () {	
	int c;
	while ((c = _getchar()) != EOF) {
		putchar(c);
	}
	printf("single end.");
	while ((c = __getchar()) != EOF) {
		putchar(c);
	}
	printf("multiple end.");
}
