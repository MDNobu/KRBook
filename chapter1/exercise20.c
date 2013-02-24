#include "stdio.h"
#define MAXSIZE 100
#define TAB_SIZE 4
	void detab(char str[]);

main() {
	char* str = "hello,wo	rld";
	printf("%s\n", str);
	char changed[] = detab(str);
	printf("%s\n", changed);
}

char[] detab(char str[]) {
	char tmp[MAXSIZE];
	int indexStr, indexTmp;
	indexStr = indexTmp = 0;
	
	while(str[indexStr] != '\0' && indexTmp < MAXSIZE - 1) {
		if(str[indexStr] != '\t') {
			tmp[indexTmp++] = str[indexStr++];
		} else {
			int i;
			for(i = 0; i < TAB_SIZE; i++, indexTmp++) {
				tmp[indexTmp] = '0';
			}
			indexStr++;
		}
	}
	tmp[indexTmp] = '\0';
	printf("%s\n", tmp);
	return tmp;
	
}