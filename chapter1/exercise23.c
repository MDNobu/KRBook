#include "stdio.h"
#define IN 1
#define OUT 0

main() {
	int c;
	int slashCounter = 0;
	char judge[2];
	int state = OUT;
	
	while((c = getchar())  != EOF) {
		if(state == OUT) {
			if(c != '/' && c!= '*') {
				putchar(c);
			} else if(c == '*'){
				
			}				
		}
		
		if(c != )	
	}
	
}