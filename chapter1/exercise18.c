#include "stdio.h"
#define MAX_SIZE 100
main() {
	char line[MAX_SIZE];
	int c;
	c ='a';
	while(c != EOF) {
		int i = 0;
		for(;i < MAX_SIZE - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
			line[i] = c;	
		}		
		while(line[i] != '\t' && line[i] != ' ')
			i--;
		if(i == 0) {
			continue;
		}		
		if(c == '\n') {
			line[i++] = '\n';
		}
		line[i++] = '\0';
		printf("%s", line);
	}
	
}

