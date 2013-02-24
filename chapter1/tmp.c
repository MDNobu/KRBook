#include "stdio.h"

main() {
	int count = 0;
	int c;
	while((c = getchar())  != EOF ) {
		if( c == '\n') {
			count++;
		}	
	}	
	
	printf("count = %d\n", count);
}