#include "stdio.h"
#include "ctype.h"


void mystrcat(char *s, char *t) {
	while(*s != '\0')
		s++;

	while(*s++ = *t++)
		;
}



int main (int argc, char const* argv[])
{
	char s[1024] = "ni hao";
	char *t = "hello, world";
	mystrcat(s, t);
	printf("%s\n", s);
	getchar();
	return 0;
}