#include "stdio.h"
#include "string.h"
#include "ctype.h"

int getint(int *p) {
	int c,sign;
	
	sign = 1;
	while(!isdigit(c = getch()) && c != '-' && c != '+' ) 
		;
	if(c == '-')
		sign = -1;
	if(c == '+' || c == '-')
		c = getch();
	if(!isdigit(c))
		ungetch(c);
	while( !isdigit(c) )
		c = getch();
	
	while(isdigit(c)) {
		*p = *p * 10 + (c - '0'); 
	}
		
	*p *= sign;	
	if(c != EOF)
		ungetch(c);
	return 0;
	
}
float getfloat(float *p) {
	int c;
	float power,sign;

	while(!isdigit(c = getch()) && c != '+' && c != '-')
		;
	sign = 1.0f;
	if(c == '-')
		sign = -1.0f;
	if(c == '+' || c == '-')
		c = getch();
	for(*p = 0.0; isdigit(c); c = getch()) {
		*p = *p * 10.0f + (c - '0' ) ;
	}
	if(c == '.') {
		c = getch();
		power = 1.0f;
		for(; isdigit(c); c = getch()) {
			*p = *p * 10.0f + (c - '0' ) ;
			power *= 10.0f;
		}
		*p /= power;

	}	
	if(c != EOF)
		ungetch(c);
	//printf("%f, %f\n", *p, sign);
	*p *= sign;
	return 0.0f;
}

int main (int argc, char const* argv[])
{
	

	float *b,e;
	b = &e;
	getfloat(b);
	printf("%f\n", *b);
	getchar();
	return 0;
}