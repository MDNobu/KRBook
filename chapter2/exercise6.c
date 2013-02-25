#include "stdio.h"

//get n bits from position p
unsigned getbits(unsigned x,int p, int n) {
	return (x >> (p - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	
	unsigned nlowbits = ~(~0 << n); //n个低位1，其余位0
	return x & ~(nlowbits << (p - n)) | ((y & nlowbits) << (p - n));
}

unsigned invert(unsigned x, int p, int n) {
	
	unsigned nlowbits = ~(~0 << n); //n个低位1，其余位0
	return x ^ (nlowbits << (p - n));
}

unsigned rightrot(unsigned x, int n) {
	int wordlength(void);
	
	unsigned nlowbits = ~(~0 << n); //n个低位1，其余位0
	//printf("%s%d\n", "nolowbits = ", nlowbits);
	unsigned rnbits = x & nlowbits;
	printf("%d\n", wordlength());
	
	return (x >> n) | (rnbits << (wordlength() - n));
}

int wordlength(void) {
	unsigned v = ~0;
	int i;
	
	for(i = 1; (v = v >> 1) > 0; i++) {
		
	}
	
	return i;
}

main() {
	unsigned a = 0x35E;
	unsigned b = 0x2B;
	/*unsigned aoff = getbits(a, 5, 2);	
	printf("%d\n", aoff);*/
	
	unsigned aset = setbits(a, 8, 4, b);
	printf("%d\n", a);
	printf("%d\n", aset);
	printf("%d\n", invert(a, 8, 4));
	printf("rightrots = %u\n", rightrot(a, 5));
}