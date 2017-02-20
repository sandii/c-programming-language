/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 20, 2017
*
* copy file-a to file-b
* e.g.
* cp.o file-a file-b
*/

#include <stdio.h>
#include <stdlib.h>	// exit
#include <unistd.h>	// open create read write close BUFSIZ
#include <fcntl.h>	// O_RDONLY
#include <stdarg.h>

#define PERMS 0666

void error (char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "Error: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	exit(1);
}

void cp (char* src, char* dst) {
	int f1 = open(src, O_RDONLY, 0);
	if (f1 == -1) error("fail to open %s", src);	

	int f2 = creat(dst, PERMS);
	if (f2 == -1) error("fail to create %s", dst);

	char buff[BUFSIZ];
	int readNum = 0;
	while ((readNum = read(f1, buff, BUFSIZ)) > 0) {
		int writeNum = write(f2, buff, readNum);
		if (writeNum != readNum) error("fail to write %s", dst);
	}
	close(f1);
	close(f2);
}

main (int argc, char* argv[]) {
	if (argc < 3) error("expect two parameters");
	cp(argv[1], argv[2]);
}

