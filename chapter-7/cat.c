/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 15, 2017
*
* show content of files
* e.g.
* cat.o file1.txt file2.txt file3.txt
*/

#include <stdio.h>

void cat (char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("open %s fail..\n", filename);
		return;
	}
	int c;
	while ((c = getc(fp)) != EOF) {
		putc(c, stdout);
	}
	fclose(fp);
}

main (int argc, char* argv[]) {	
	if (argc == 1) return 1;
	for (int i = 1; i < argc; i++) {
		cat(argv[i]);
	}
}
