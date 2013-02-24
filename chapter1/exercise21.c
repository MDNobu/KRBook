#include "stdio.h"
#define MAXSIZE 100
#define TABSIZE 4
#define IN 1
#define OUT 0

char* entab(char str[]);

main() {
	char str[] = "hello,wo     rld";
	printf("%s\n", str);
	char changed[] = entab(str);
	printf("%s\n", changed);
}

char* entab(char str[]) {
	int spaceCounter = 0;
	int i = 0;
	int state = OUT;
	char result[MAXSIZE];
	int j = 0;
	while(str[i] != '\0') {
		if(str[i] != ' ' && state = IN) {
			int k;
			for(k = 0; k < spaceCounter; k++) {
				result[j++] = ' ';
			}
			spaceCounter = 0;
			state = OUT;
			result[j++] = str[i];
		} else if(str[i] != ' ' && state = OUT) {
			result[j++] = str[i];
		} else if( str[i] == ' ') {
			spaceCounter++;
			if(spaceCounter == TABSIZE) {
				result[j++] = '\t';
			}	
		}		
		i++;
	}	
	
	return result;
}