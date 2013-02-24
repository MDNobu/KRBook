#include "stdio.h"

void squeeze(char s1[], char s2[]) {
	int i,j,k;
	
	i = j = k = 0;
	
	//һ����¼�ַ���ʼһ�µ�λ�õı�������һ��ʱ��-1
	int point = -1;
	for(; s1[i]; i++) {
		if(point == -1) { //û���Ѿ���¼����ͬ����ʱ�Ĵ���
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

