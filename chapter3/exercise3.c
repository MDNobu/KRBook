#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#define MAXLEN 1024

enum {ALPDIG, LINE, OTHER};

int expand(char s[], char t[]) {
	int status = OTHER;
	int i,j;
	
	int last;
	for(i = 0, j = 0; t[i] != '\0'; i++) {
		if(status == OTHER) {
			s[j++] = t[i];
			if(isalnum(t[i])) {
				status = ALPDIG;
				last = t[i];
				//pos = i;
			} 
		}else if(status == ALPDIG) {
			if(t[i] == '-') {
				status = LINE;				
			} else if(isalnum(t[i])) {
				s[j++] = t[i];
				last = t[i];
			} else {
				s[j++] = t[i];
				status = OTHER;
			}
		} else if(status == LINE) {
			
			if( (isalpha(last) && isalpha(t[i])) || (isdigit(last) && isdigit(t[i]) ) ) {
				int k;
	//printf("this is a test %c\n", last);
				for(k = last + 1; k <= t[i]; k++) {
					s[j++] = k;
				}
				//printf("t[i] = %c\n", t[i]);
				if(t[i+1] != '-') {	
					status = ALPDIG;
				} else { 
					last = t[i];
				}
			}
		}	
	}
	s[j] = '\0';
	return 0;	
}

int main (int argc, char const* argv[])
{
	char s[MAXLEN];
	char t[] = "  -a-eo-r-u1-5--";
	
	expand(s,t);
	printf("t = %s\n", t);
	printf("s = %s\n", s);
	
	return 0;
}