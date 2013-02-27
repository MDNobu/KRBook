#include "stdio.h"
int getline(char *s, int len);

int main (int argc, char const* argv[])
{
	char s[5];
	char *t = "world";
	
	int d = getline(s, 1024);
	printf("%s,count = %d\n", s, d);
	getchar();
	return 0;
}