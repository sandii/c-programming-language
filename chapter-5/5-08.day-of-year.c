/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 25, 2017
*
* convert year-month-date to nth day of year
* then reverse it
*/

#include <stdio.h>

bool isLeapYear (int y) {
	if (y % 400 == 0) return true;
	if (y % 100 == 0) return false;
	if (y % 4 == 0) return true;
	return false; 
}

static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int dayOfYear (int y, int m, int d) {
	int leap = isLeapYear(y) ? 1 : 0;
	if (m < 1 || m > 12 || d < 1) return -1;
	int maxd = daytab[leap][m];
	if (d > maxd) return -1;

	for (int i = 1; i < m; i++) {
		d += daytab[leap][i];
	}
	return d;
}

int getMonthDate (int y, int nth, int* mp, int* dp) {
	int leap = isLeapYear(y) ? 1 : 0;
	if (nth < 1) return -1;
	if (!leap && nth > 365) return -1;
	if (leap  && nth > 366) return -1;

	int m = 1;
	int d = nth;
	while (d > daytab[leap][m]) {
		d -= daytab[leap][m];
		m++;
	}
	*mp = m;
	*dp = d;
	return 0;
}

void getOrdinal (char *ordinal, int n) {
	int remain = n % 10;
	if (remain == 1) { ordinal[0] = "s"; ordinal[1] = "t"; }
	if (remain == 2) { ordinal[0] = "n"; ordinal[1] = "d"; }
	if (remain == 3) { ordinal[0] = "r"; ordinal[1] = "d"; }
	ordinal[0] = "s"; ordinal[1] = "t";
}

main () {
	int y = 1988;
	int m = 4;
	int d = 10;
	int nth = dayOfYear(y, m, d);
	char ordinal[2] = {"t", "h"};
	if (nth == -1) {
		printf("error: illegal month-date\n");
		return 1;
	}
	getOrdinal(nth);
	printf("%d-%d-%d is the %d%s day of the year\n", y, m, d, nth, ordinal);
	nth = 100;
	int status = getMonthDate(y, nth, &m, &d);
	if (status == -1) {
		printf("error: illegal nth day\n");
		return 1;
	}
	getOrdinal(nth);
	printf("%d%s day of %d is %d-%d-%d\n", nth, ordinal, y, y, m, d);
}
