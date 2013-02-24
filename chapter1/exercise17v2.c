#include "stdio.h"
#define MAXSIZE 100
#define TEST_SIZE 15

int  getLine(char s[], int lim);

main() {
	int c;
	int len;
	int lim = MAXSIZE;
	char line[MAXSIZE];
	
	while((len = getLine(line, lim)) > 0) {
		if(len > TEST_SIZE)
			printf("%s", line);
	}
}

int getLine(char line[], int lim) {
	int i, j;
	int c;
	for(i= 0; i < lim - 2 && (c = getchar())!= EOF && c != '\n'; i++) {
		line[i] = c;
	}
	if(c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}