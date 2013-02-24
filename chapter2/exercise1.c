#include "stdio.h"
#include <limits.h>
#define printint(a) printf("%d\n", a)

	int strlen(char []);

void impletation1() {
	printf("signed char min = %d\n", SCHAR_MIN);
	printf("signed char max = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n", SHRT_MAX);
	printf("signed int min = %d\n", INT_MIN);
	printf("signed int max = %d\n", INT_MAX);
	printf("signed long min = %ld\n", LONG_MIN);
	printf("signed long max = %ld\n", LONG_MAX);
	
	//unsigned types
	printf("unsigned char max = %u\n", UCHAR_MAX);
	printf("unsigned short max = %u\n", USHRT_MAX);	
	printf("unsigned int max = %u\n", UINT_MAX);
	printf("unsigned long max = %lu\n", ULONG_MAX);
	printf("%d\n", sizeof(int));
}

void impletation2() {
	//signed types
	printf("unsigned char max = %d\n", (unsigned char)(~0) );
	printf("unsigned int min = %d\n", (unsigned int)(~0));

	//unsigned types
	printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1));
	printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1));
	printf("signed int max = %d\n", -(int)((unsigned int) ~0 >> 1));
	printf("signed int max = %d\n", -(int)((unsigned int) ~0 >> 1));
	printf("%d\n", sizeof(int));
	
}


main() {
	
	//impletation1();
	
	printf("impletation2\n");
	//impletation2();
	
	int cont = strlen("hello, world");
	int cont2 = strlen("");
	printint(cont);
	printint(cont2);
	printf("%d\n", cont);
}

int strlen(char s[]) {
	int i;
	
	for(i = 0; s[i]; i++)
		;
	return i;
}
