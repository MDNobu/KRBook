#include "stdio.h"

main() {
	float fahr, celsius;
	int lower, upper, step;
	
	lower = -20;
	upper = 150;
	step = 20;
	celsius = lower;
	while(celsius < upper) {
		fahr = celsius * 9 / 5 + 32;
		printf("%6.1f %5.2f\n", celsius, fahr);
		celsius += step;	
	}	
}