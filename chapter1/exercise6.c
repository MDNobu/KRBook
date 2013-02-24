#include "stdio.h" 

main() {
	int c;
	int counter = 0;
	
	while(counter++ < 10) {
		c = (getchar() != EOF);
		printf("%3d\n", c);		
	}
	printf("%d\n", EOF);
}