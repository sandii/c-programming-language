/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 15, 2017
*
* print files in pages
* - start every file on a new page
* - print every file's title and page number
* e.g.
* 7-8.page-print.o -maxLineNumber filename1 filename2 ..
*/

#include <stdio.h>
#include <stdlib.h>	// exit atoi
#include <string.h>	// strstr strlen

#define MAX_LINE_NUM 10
#define MAX_LINE_LEN 200
char line[MAX_LINE_LEN];

int getFileLine (FILE* fp) {
	if (fgets(line, MAX_LINE_LEN, fp) == NULL) return 0;
	return strlen(line);
}

void printPageNo (int pageNo) {
	printf("\n- Page %d -\n\n", pageNo);
}

void print (char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("cannot open %s\n\n", filename);
		exit(1);
	}
	printf("\nTitle: %s\n\n", filename);

	int len = 0;
	int lineNo = 1;
	while ((len = getFileLine(fp)) != 0) {
		printf("%s", line);
		lineNo++;

		// page end, print page number
		if (lineNo % MAX_LINE_NUM != 0) continue;
		printPageNo(lineNo / MAX_LINE_NUM);
	}

	// print empty line at file end
	while (lineNo % MAX_LINE_NUM != 0) {
		printf("\n");
		lineNo++;
	}
	printPageNo(lineNo / MAX_LINE_NUM);

	fclose(fp);
}

main (int argc, char* argv[]) {
	if (argc < 2) return 1;
	for (int i = 1; i < argc; i++) {
		print(argv[i]);
	}
}
