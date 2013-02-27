#include "stdio.h"
#include "string.h"

#define swap(t, x, y) { t tmp; tmp = (x); (x) = (y); (y) = (tmp); }

main() {
	int a = 50;
	int b = 60;	
	printf("a = %d, b = %d\n", a, b );
	swap(int, a, b);
	printf("a = %d, b = %d\n", a, b );
}