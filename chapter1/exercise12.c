#include "stdio.h"
#define CL 1
#define NCL 0

main() {
	int c;
	int state = NCL;
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t') {
			state = CL;	
		}
		else {
			if(state == CL) {
				putchar('\n');
			}
			putchar(c);			
			state = NCL;
		}
	}
	putchar('\n');
}