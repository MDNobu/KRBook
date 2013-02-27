#include "stdio.h"
//#include "string.h"
#include "ctype.h"

void strcat(char *s, char *t) {
	while(*s != '\0')
		s++;

	while(*s++ = *t++)
		;
}
