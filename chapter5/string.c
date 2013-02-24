#include "stdio.h"

main() {
	char message[] = "hello world\n";
	printf("%s\n", message);
	//message = 'y';
	printf("%c\n", message[1]);
	message[1] = 'h';
	printf("%s\n", message);
}