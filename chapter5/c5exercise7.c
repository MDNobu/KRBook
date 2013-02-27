#include "stdio.h"
#include "string.h"
#define MAXSTOR 50000
#define MAXSIZE 1024

int getline(char *s, int len);
int readlines(char *lineptr[], int maxline, char *linestor) {
	int len,nlines;
	char line[MAXSIZE];
	char *p = linestor;
	char *max = p + MAXSTOR;

	nlines = 0;
	while((len = getline(line, MAXSIZE)) > 0 ) {
		if(nlines >= maxline || p + len > max) {
			return -1;
		} else {
			line[len - 1] = '\0';
			lineptr[nlines++] = p;
			p += len;
		}
	}

	return nlines;
}