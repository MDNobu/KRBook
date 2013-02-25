#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define MAXLEN 1024


void reverse(char s[])
{
   int c, i, j;
   for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
       c = s[i];
       s[i] = s[j];
       s[j] = c;
   }
}

void myitoa(int x, char s[], int n) {
	int sign,i;
	i = 0;
	if((sign = x) < 0)
		x = -x;
	
	do {
		s[i++] = x % 10 + '0';
	} while( (x /= 10) > 0 );
	
	for(; i < n - 1; i++) {
		s[i++] = ' ';
	}
	if(sign < 0)
		s[i++] = '-';
	s[i] ='\0';
	reverse(s);
}

main() {
	char s[MAXLEN];
	int ori = 56987;
	
	myitoa(ori, s, 16);
	printf("s =%s\n", s);
	return 0;
}
