#include <stdio.h>

int arrlen (int a[]) {
	return sizeof(&a) / sizeof(a[0]);
}

// void qsort ()

main () {
	int a[] = {4,11,36,1,65,3,16,10};
	// qsort(a);
	printf("%d\n", arrlen(a));

}
