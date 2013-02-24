#include "stdio.h"
#include "string.h"

int htoi(char s[]) {
	int result,i;
	if(strlen(s) < 3 || s[0] != '0' || (s[1] != 'x' && s[1] != 'X'))
		return -1;
	
	result = 0;
	for(i = 2; s[i]; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			result = result * 16 +  s[i] - '0';
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			result = result * 16 +  s[i] - 'A' + 10;
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			result = result * 16 +  s[i] - 'a' + 10;
		}
	}
	return result;
}

int main (int argc, char const* argv[])
{
	char s[] = "0xa34";
	char s2[] = "0X52F";
	char s3[] = "5";
	printf("s = %d\n", htoi(s));
	printf("s2 = %d\n", htoi(s2));
	printf("s3 = %d\n", htoi(s3));
	return 0;
}
