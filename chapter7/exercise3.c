#include "stdio.h"
#include "string.h"
#include <stdarg.h>

void minscanf(char *fmt, ...) {
	
	va_list ap;
	char *p,*sval;
	double dval;
	int val;
	int spliter;
	
	
	va_start(ap, fmt);
	for(p = fmt; *p; p++) {
		
	}	
}