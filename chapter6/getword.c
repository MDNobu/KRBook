#include "string.h"
#include "ctype.h"

int getch();
void ungetch(int c);
int getword(char *word, int limit) {
	int c;
	char *base = word;
	
	while((c = getch()) == ' ' || c == '\t')
		;
	*word++ = c;
	limit--;
	if(!isalpha(c)) {
		*word = '\0';
		return c;
	}
	
	while(isalnum(c = getch()) && --limit > 0)
		*word++ = c;
	ungetch(c);
	*word = '\0';
	return word[0];
}