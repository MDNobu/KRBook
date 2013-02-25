#include "stdio.h"

void escape(char s[], char t[]) {
	int i,j;
	for(i = 0, j = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];	
		}
	}
	s[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i,j;
	for(i = 0, j = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
		case '\\':
			if(t[++i] == 't') {
				s[j++] = '\t';
			} else if(t[i] == 'n') {
				s[j++] = '\n';
			} else if(t[i] == '\0') {
				s[j++] = '\\';
				break;
			}
			break;			
		default:
			s[j++] = t[i];	
		}
	}
	s[j] = '\0';
}

main() {
	char ori[] = "hello	,	world\n";
	char dest[1024];
	
	escape(dest, ori);
	printf("ori = %s,dest = %s\n", ori, dest);	
	char huan[1024];
	unescape(huan, dest);
	printf("%s\n", huan);
}