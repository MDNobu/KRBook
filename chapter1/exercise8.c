#include "stdio.h"

main() {
	
	int blankNum, tabNum, newlineNum;
	blankNum = tabNum = newlineNum = 0;
	int c;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			newlineNum++;
		} else if(c == '\t') {
			tabNum++;
		} else if(c == ' ') {
			blankNum++;
		}
	}
	
	printf("blanke num = %3d, tab num = %3d, newline num = %3d\n", blankNum, tabNum, newlineNum);
}