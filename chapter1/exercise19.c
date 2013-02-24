#include "stdio.h"
#define MAX_SIZE 100

void reverse(char str[]);

main() {
	char str[] = "hello,world";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
}

void reverse(char str[]) {
	//char tmp[MAX_SIZE];
	int i = 0;
	while(str[i] != '\0')
		i++;
	i--;
	int j = 0;
	while(i > j) {
		int tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
		j++;
	}
}