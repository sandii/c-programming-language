/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 15, 2017
*
* search pattern in files
* - print filename if found
* - print line and column number of found position
* e.g.
* 7-7.search.o pattern filename1 filename2 ..
*/

#include <stdio.h>
#include <string.h>	// strstr strlen

#define MAX_LINE_LEN 200
char line[MAX_LINE_LEN];

int getFileLine (FILE* fp) {
	if (fgets(line, MAX_LINE_LEN, fp) == NULL) return 0;
	return strlen(line);
}

int search (char* pattern, char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("cannot open %s\n", filename);
		return 0;
	}
	int len = 0;
	int lineNo = 1;
	int colmNo = 1;
	while (len = getFileLine(fp)) {
		char* cp = strstr(line, pattern);
		if (cp == NULL) {
			lineNo++;
			continue;
		}
		colmNo = cp - line + 1;
		printf("Found pattern in file %s, at line %d, column %d.\n", filename, lineNo, colmNo);
		return 1;
	}
	fclose(fp);
	return 0;
}

main (int argc, char* argv[]) {
	if (argc < 3) return 1;

	int found = 0;
	char* pattern = argv[1];
	for (int i = 2; i < argc; i++) {
		char* filename = argv[i]; 
		found += search(pattern, filename);
	}
	if (found == 0) printf("nothing found..\n");
}
