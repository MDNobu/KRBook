#include "stdio.h"
#include "string.h"

int main (int argc, char const* argv[])
{
	int i,c;	
	int flag = 0;
	int slashindex,flagindex;
	char *arg = argv[0];
	
	
	for(i = 0; arg[i] != '\0'; i++) {
		if(arg[i] == '\\') 
			slashindex = i;
		else if(!strncmp(&arg[i], "big", strlen("big"))) {
			flagindex = i;
			flag = 1;
		} else if(!strncmp(&arg[i], "little", strlen("little"))) {
			flagindex = i;
			flag = -1;
		}			
	}
	if(flagindex < slashindex)
		flag = 0;
		
	printf("flag =%d,%s\n", flag, arg);
	
	while((c = getchar()) != EOF) {
		if(flag == -1) {
			putchar(tolower(c));
		} else if(flag == 1) {
			putchar(toupper(c));
		} else {
			putchar(c);
		}
	}
	return 0;
}