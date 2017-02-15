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
#include <stdlib.h>	// exit
#include <string.h>	// strcmp strlen

#define MAX_LINE_LEN 200
char line1[MAX_LINE_LEN];
char line2[MAX_LINE_LEN];

int getFileLine (char* line, int max, FILE* fp) {
	char* sp = fgets(line, max, fp);
	if (sp == NULL) return 0;
	return strlen(line);
}

int compare (FILE* fp1, FILE* fp2) {
	int lineNo = 1;
	int len1 = 0;
	int len2 = 0;
	do {
		len1 = getFileLine(line1, MAX_LINE_LEN, fp1);
		len2 = getFileLine(line2, MAX_LINE_LEN, fp2);
		if (strcmp(line1, line2) != 0) return lineNo;
		lineNo++;
	} while (len1 != 0 && len2 != 0);
	return 0;
}

main (int argc, char* argv[]) {
	if (argc < 3) return 1;
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");
	if (fp1 == NULL) { printf("open %s fail..\n", argv[1]); exit(1); }
	if (fp2 == NULL) { printf("open %s fail..\n", argv[2]); exit(1); }

	int lineNo = compare(fp1, fp2);
	if (lineNo == 0) {
		printf("No difference!\n");
	} else {
		printf("Line %d is different:\n", lineNo);
		printf("%s: %s", argv[1], line1);
		printf("%s: %s", argv[2], line2);
	}
	fclose(fp1);
	fclose(fp2);
}
