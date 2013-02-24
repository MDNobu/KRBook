#include "stdio.h"

main() {
	int alphabetCounts[26];
	int w;
	for(w = 0; w < 26; w++) {
		alphabetCounts[w] = 0;	
	}	
	int c;
	while((c = getchar()) != EOF) {
		if(c >= 'a' && c <= 'z') {
			alphabetCounts[c - 'a']++;
		} else if (c >= 'A' && c <= 'Z') {
			alphabetCounts[c - 'A']++;
		}
	}
	
	int i;
	for(i = 0; i < 26; i++) {
		int alpha = i + 'a';		
		printf("%c = %d", alpha, alphabetCounts[i]);
		int j;
		for(j = 0; j < alphabetCounts[i]; j++) {
			printf("*");
		}
		putchar('\n');
	}
}