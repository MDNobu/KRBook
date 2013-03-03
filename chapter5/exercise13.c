#include "stdio.h"
#include "math.h"
#include "string.h"
#include "malloc.h"
#define MAXLINE 1024
#define MAXLEN 1024

int getline(char *s, int len);
int main (int argc, char const* argv[])
{
	int n = 10,count,tailindex,linelen;
	char *lineptr[MAXLINE];
	char oneline[MAXLEN];
	
	if(argc == 2) {
		n = atoi( &(*++argv[1]));
	}
	if(n < 0 || n > MAXLINE)
		return -1;
	for(count = 0,tailindex = 0; (linelen = getline(oneline, MAXLEN)) > 0;  count++) {
		char *tmp = (char *)malloc((linelen+1) * sizeof(char));
		strcpy(tmp, oneline);
		lineptr[tailindex] = tmp;
		tailindex = (tailindex + 1) % n;		
	}
	
	printf("count =%d\n", count);
	printf("count =%d\n", tailindex);
	if(count < n) {
		int i;
		for(i = 0; i < tailindex; i++) {
			printf("%s", lineptr[i]);
		}
	} else {
		int i;
		
		for(i = tailindex; i != (tailindex - 1)%n; i = (i + 1)%n ) {
			printf("%s", lineptr[i]);
		}
		printf("%s", lineptr[i]);
	}
	
	return 0;
}