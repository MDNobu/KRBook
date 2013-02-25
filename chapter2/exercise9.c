#include "stdio.h"

int bitcount(unsigned x) {
	int i = 0;
	while(x) {
		x &= (x - 1);
		i++;
	}
	return i;
}

int tolower(int c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

main() {
	printf("bitcount = %d\n", bitcount(0x35E));
	printf("%c\n", tolower('a'));
}