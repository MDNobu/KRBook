#include "stdio.h"

main() {
	int counter = 0;
	
	int c;
	while((c = getchar()) != EOF) {
		if((c == ' ') && (counter ==0)) {
			counter = 1;
			printf("%c", c);
		} else if((c == ' ') && (counter == 1)) {
			continue;
		} else if(c != ' ') {
			counter = 0;
			printf("%c", c);
		}
	}
}