#include <stdio.h>

main() {
	int i;
	for(i = 0; i <= 300; i += 20)
		printf("%4d %6.1f\n", i, (5.0/9.0) * (i - 32));
}