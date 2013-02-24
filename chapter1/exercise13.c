#include "stdio.h"
#define WORD_MAX_SIZE 20

main ()
{
	int counters[WORD_MAX_SIZE];
	int c;
	int i;
	for(i = 0; i < WORD_MAX_SIZE; i++) {
		counters[i] = 0;	
	}	
	
	int curLength = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n' || c == '\t' || c ==' ') {
			counters[curLength]++;			
			curLength = 0;
		} else {
			curLength++;
		}	
	}
	counters[curLength]++;
	
	int t;
	for(t = 0; t < WORD_MAX_SIZE; t++) {
		int j;
		for(j = 0; j < counters[t]; j++) {
			printf("*");
		}
		printf("\n");	
	}		
}