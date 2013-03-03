#include "stdio.h"

void filecopy(File *ifp, File *ofp);

int main (int argc, char const* argv[])
{
	File *fp;
	
	if(--argc == 0)
		filecopy(stdin, stdout);
	
	while(argc-- > 0 ) {
		fp = fopen(*++argv, "r");
		if(fp == NULL) {
			printf("there is not this file");
			return 1;
		} 
		filecopy(fp, stdout);
		fclose(fp);
	}
	
	return 0;
}

void filecopy(File *ifp, File *ofp) {
	int c;
	
	while( (c = getc(ifp)) != EOF) {
		put(c, ofp);
	}
}