#include "string.h"
#include "stdio.h"
#include "ctype.h"

int strindex(char s[], char t[]) {
	int i,j,k;
	if(strlen(t) <= 0 || strlen(s) <= 0) {
		return -1;
	}
	
	for(i = strlen(s) - 1; i >= 0; i--) {
		
		for(j = i, k = strlen(t) - 1; k >= 0 && t[k] == s[j]; k--, j--) 
			;
		if(k < 0)
			return i;			
	}
	return -1;
}

int main (int argc, char const* argv[])
{
	
	int index = strindex("helrlo, world", "rl");
	printf("%d\n", index);
	return 0;
}
