#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define BUFSIZE 1024

int sp = 0;
int val[BUFSIZE];

int getch() {
	return --sp > 0 ? val[sp] : getchar();
}

void ungetch(int c) {
	val[sp++] = c;
}