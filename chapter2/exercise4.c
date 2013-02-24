#include "stdio.h"

void squeeze(char s1[], char s2[]) {
	int i,j,k;
	
	i = j = k = 0;
	
	//一个记录字符开始一致的位置的变量，不一致时置-1
	int point = -1;
	for(; s1[i]; i++) {
		if(point == -1) { //没有已经记录的相同变量时的处理
			if(s1[i] != s2[j]) {
				s1[k++] = s1[i];
			}else {
				point = i;
				j++;
			}
		} else {
			if(s1[i] == s2[j]) {
				j++;
			} else {
				if(s2[j] != '\0') {				
					int w;
					for(w = point; w < i; w++) {
						s1[k++] = s1[w];
					}
				}
				j = 0;
				i--;
				point = -1;
			}
		}
	}
	s1[k] = '\0';	
}

main() {
	
	char s1[] = "hello, worldelw";
	char s2[] = "el";
	squeeze(s1, s2);
	
	printf("s1 = %s\n", s1);
}

