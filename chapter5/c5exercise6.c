#include "stdio.h"

int getline(char *s, int len) {
	int c,count;

	count = 0;
	while(--len > 0 && (*s++ = c = getchar()) != EOF && c != '\n')
		count++;
	if(c == '\n')
		count++;
	*s = '\0';
	return count;
}

