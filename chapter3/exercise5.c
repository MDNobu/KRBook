#include "stdio.h"
#include "ctype.h"
#define MAXLEN 1024
	#define abs(x) (x) > 0 ? (x) : -(x)

void itob(int, char s[], unsigned)

int main (int argc, char const* argv[])
{
	char s[MAXLEN];
	int ori = 56987;
	
	itob(ori, s, 16);
	printf("%s\n", s);
	return 0;
}

int parsetodig(int c) {
	if(c > 36 || c < 0)
		return -1;
	else if(c >= 10) {
		return 'a' + c - 10;
	} else {
		return '0' + c;
	}
}

void itob(int n, char s[], unsigned b) {
	int sign,i;
	
	sign = n;
	i = 0;
	do {
		s[i++] = parsetodig(n % b);
	} while( n/b != 0);
	s[i] = '\0';
	reverse(s);	
}