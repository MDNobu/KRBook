#include "stdio.h"

int any(char s1[], char s2[]) {
	//int pos - -1;
	int i;
	for(i = 0; s1[i]; i++) {
		int j;
		for(j =0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if(s2[j] != '\0') {
			return i;
		}
	}	
	return -1;
}

main() {
	
	char s1[] = "hello, worldelw";
	char s2[] = "lw";
	int pos = any(s1, s2);
	
	printf("s1 pos = %d\n", pos);
}