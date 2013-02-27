#include "stdio.h"
#include "string.h"

void reverse(char s[]) {
	void reverser(char s[], int low ,int high);
	
	reverser(s, 0, strlen(s) - 1);
}

void reverser(char s[], int low, int high) {
	//int j = high - 1;
	if(low < high) {
		int t = s[low];
		s[low] = s[high];
		s[high] = t;
		reverser(s, low +1, high - 1);
	}
}

void itoa(int x, char s[]) {	
	static int i = 0;
	if(x == 0) {
		s[i] = '\0';
		printf("%s\n", s);
		reverse(s);
		return;
	} else {		
		s[i++] = x % 10 + '0';
		itoa(x / 10, s);
	}
}



main() {
	int test = 56889;
	char s[1024];
	itoa(test, s);
	printf("%s\n", s);
}