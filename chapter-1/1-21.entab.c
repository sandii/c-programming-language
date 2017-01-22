/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 13, 2017
*
* space to tab
*/

#include <stdio.h>

#define TABWIDTH 8

main() {
    int c = 0;
    int col = 0;
    int space = 0;
    int table = 0;
    while ((c = getchar()) != EOF) {
        // if space, don't output, but accumulate it
        if (c == ' ') {
            col++;
            space++;
            continue;
        }
        // if not space
        // output accumulated spaces as '\t' and ' '
        if (space == 1) {
            putchar(' ');
        }
        if (space > 1) {
            table = col / TABWIDTH - (col - space) / TABWIDTH;
            space = col % TABWIDTH;
            for (int i = 0; i < table; i++) putchar('\t');
            for (int i = 0; i < space; i++) putchar(' ');
        }
        col++;
        space = 0;
        putchar(c);
        // if \n, clear accumulation
        if (c == '\n') {
            col = 0;
        }
    }
}