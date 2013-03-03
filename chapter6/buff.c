#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#define BUFSIZE 1024

int sp = 0;
int val[BUFSIZE];

char *mystrdup(char *s)   /* make a duplicate of s */
{
   char *p;
   p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
   if (p != NULL)
       strcpy(p, s);
   return p;
}

int getch() {
	return --sp > 0 ? val[sp] : getchar();
}

void ungetch(int c) {
	val[sp++] = c;
}

void ungetchword(char *word) {
	int i;
	for (i = strlen(word) - 1; i >= 0; i--) {
		ungetch(word[i]);
	}
}

/* getword:  get next word or character from input */
int getword(char *word, int lim) {
	int c, getch();
	char *w = word;
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
