#include "stdio.h"

main() {
	float fahr, celsius;
	
	for(fahr = 300; fahr >= 0; fahr -= 20) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f  %6.1f\n", fahr, celsius);		
	}
}