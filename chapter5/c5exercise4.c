#include "string.h"

int strend(char s[], char t[]) {
	int i, j;

	for(i = strlen(s) - 1, j = strlen(t) - 1; j > 0 && s[i] == t[j]; i--, j--) 
		;
	if(j == 0)
		return 1;
	return 0;
}