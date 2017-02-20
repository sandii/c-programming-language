/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 20, 2017
*
* show files content
* with system call functions read write open close
* e.g.
* cat.o file1.txt file2.txt file3.txt
*/

#include <stdio.h>
#include <stdlib.h>	// exit
#include <unistd.h>	// open read write close BUFSIZ
#include <fcntl.h>	// O_RDONLY
#include <stdarg.h>

void error (char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "Error: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	exit(1);
}

void cat (char* filename) {
	int f = open(filename, O_RDONLY, 0);
	if (f == -1) error("fail to open %s", filename);
	
	char buff[BUFSIZ];
	int readNum = 0;
	while ((readNum = read(f, buff, BUFSIZ)) > 0) {
		int writeNum = write(1, buff, readNum);
		if (writeNum != readNum) error("output error");
	}
	close(f);
}

main (int argc, char* argv[]) {	
	if (argc == 1) error("at least one filename");
	for (int i = 1; i < argc; i++) {
		cat(argv[i]);
	}
	return 0;
}
