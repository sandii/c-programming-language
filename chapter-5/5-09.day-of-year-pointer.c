/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Jan 25, 2017
*
* convert year-month-date to nth day of year
* then reverse it
* user pointer instead of array
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
	int maxd = *(*(daytab + leap) + m);
	if (d > maxd) return -1;

	for (int i = 1; i < m; i++) {
		d += *(*(daytab + leap) + i);
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
	int dayNum = 0;
	do {
		dayNum = *(*(daytab + leap) + m);
		d -= dayNum + m;
		m++;
	} while (d > dayNum);
	*mp = m;
	*dp = d;
	return 0;
}


main () {
	int y = 1988;
	int m = 4;
	int d = 10;
	int nth = dayOfYear(y, m, d);
	if (nth == -1) {
		printf("error: illegal month-date\n");
		return 1;
	}
	printf("%d-%d-%d - %d\n", y, m, d, nth);
	nth = 100;
	int status = getMonthDate(y, nth, &m, &d);
	if (status == -1) {
		printf("error: illegal nth day\n");
		return 1;
	}
	printf("%d - %d-%d-%d\n", nth, y, m, d);
}
