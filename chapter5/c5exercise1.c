#include "stdio.h"
//#include "string.h"
#include "ctype.h"
char *strncat(char *s, char *t, int n);

int strncmp(char *cs, char *ct, int n);
void strcat(char *, char *);
int getch();
void ungetch(char c);
int strend(char s[], char t[]) ;

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
int c, sign;
while (isspace(c = getch()))   /* skip white space */
    ;
if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  /* it is not a number */
       return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/*int getint(int *p) {
	int c,sign;
	
	sign = 1;
	while(!isdigit(c = getch()) && c != '-' && c != '+' ) 
		;
	if(c == '-')
		sign = -1;
	if(c == '+' || c == '-')
		c = getch();
	while( !isdigit(c) )
		c = getch();
	
	*p = 0;
	while(isdigit(c)) {
		*p = *p * 10 + (c - '0'); 
		c = getch();
	}	
	*p *= sign;	
	if(c != EOF)
		ungetch(c);
	return 0;	
}*/


float getfloat(float *p) {
	int c,sign;
	float power;

	while(!isdigit(c = getch()) && c != '+' && c != '-')
		;
	if(c == '-')
		sign = -1;
	if(c == '+' || c == '-')
		c = getch();
	for(*p = 0.0; isdigit(c); c = getch()) {
		*p = *p * 10.0f + (c - '0' ) ;
	}
	if(c == '.') {
		c = getch();
		power = 1.0f;
		for(*p = 0; isdigit(c); c = getch()) {
			*p = *p * 10.0 + (c - '0' ) ;
			power *= 10.0f;
		}
	}
	*p /= power;
	*p *= sign;
	return 0.0f;
}

