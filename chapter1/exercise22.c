#include "stdio.h"
#define LINESIZE 25
#define IN 1
#define OUT 0

main() {
	int c;
	int counter = 0;
	int state = OUT;
	char blankStr[1000];
	int blankSize = 0; 
	int isLastBlank = 0;
	
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			counter = 0;
			state = OUT;
			blankSize = 0;
			putchar(c);
		} else if(state == OUT && c != '\t' && c != ' ') {
			putchar(c);
			if(++counter >= LINESIZE) {
				counter = 0;
				state = OUT;
				blankSize = 0;
				putchar('\n');
			}
		} else if(state == IN && c != '\t' && c != ' ') {
			int i;
			if(!isLastBlank) {
				for(i = 0; i < blankSize; i++)
					putchar(blankStr[i]);
			}
			isLastBlank = 0;
			blankSize = 0;
			putchar(c);
			counter++;
		} else if(c == '\t' || c == ' ') {			
			blankStr[blankSize++] = c;
			state = IN;	
			if(++counter >= LINESIZE) {
				counter = 0;
				state = OUT;
				blankSize = 0;
				putchar('\n');
				isLastBlank = 1;
			}
		}		
	}
}