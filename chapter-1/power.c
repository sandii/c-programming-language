#include <stdio.h>

int power (int base, int n) {
	int rs = base;
	for (int i = 1; i < n; i++) {
		rs *= base; 
	}
	return rs;
}
int main () {
	printf("%d\n", power(2,5));
	printf("%d\n", power(-2,6));
	printf("%d\n", power(3,5));
	return 0;
}
