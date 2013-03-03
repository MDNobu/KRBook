#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLINES 5000     /* max #lines to be sorted */
char *lineptr[MAXLINES];  /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,int reverse,
          int (*comp)(void *, void *));
int numcmp(char *, char *);
/* sort input lines */
main(int argc, char *argv[])
{
   int nlines,reverse = 1;        /* number of input lines read */
   int numeric = 0;   /* 1 if numeric sort */
   
	while(--argc > 0 && (*++argv)[0] == '-') {
		int c;
		while( c = *++argv[0] ) {
			switch(c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = -1;
				break;
			}
		}
	}       

   if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
       qsort((void**) lineptr, 0, nlines-1, reverse,
         (int (*)(void*,void*))(numeric ? numcmp : strcmp));
       writelines(lineptr, nlines);
	   
		getchar();
       return 0;
   } else {
       printf("input too big to sort\n");
       return 1;
   }
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int reverse,
          int (*comp)(void *, void *))
{
   int i, last;
   void swap(void *v[], int, int);
   if (left >= right)    /* do  nothing if array contains */
       return;           /* fewer than two elements */
   swap(v, left, (left + right)/2);
   last = left;
   for (i = left+1; i <= right;  i++)
       if (reverse * (*comp)(v[i], v[left]) < 0)
           swap(v, ++last, i);
   swap(v, left, last);
   qsort(v, left, last-1, reverse, comp);
   qsort(v, last+1, right,reverse, comp);
}


/* numcmp:  compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
   double v1, v2;
   v1 = atof(s1);
   v2 = atof(s2);
   if (v1 < v2)
       return -1;
   else if (v1 > v2)
       return 1;
   else
       return 0;
}

int rcmp(int (*cmp)(void *, void *), void *a, void *b) {
	return -(*cmp)(a, b);
}

void swap(void *v[],  int i, int j)
{
   void *temp;
   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

#define MAXLEN 1000  /* max length of any input line */
int getline(char *, int);
char *alloc(int);

int getline(char *s, int len) {
	int c,count;

	count = 0;
	while(--len > 0 && (*s++ = c = getchar()) != EOF && c != '\n')
		count++;
	if(c == '\n')
		count++;
	*s = '\0';
	return count;
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
char *alloc(int n)    /* return pointer to n characters */
{
   if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */
       allocp += n;
              return allocp - n; /* old p */
   } else      /* not enough room */
       return 0;
}

void afree(char *p)  /* free storage pointed to by p */
{
   if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
       allocp = p;
}


/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char *p, line[MAXLEN];
   nlines = 0;
   while ((len = getline(line, MAXLEN)) > 0)
       if (nlines >= maxlines || (p = alloc(len)) == NULL)
           return -1;
       else {
           line[len-1] = '\0';  /* delete newline */
           strcpy(p, line);
           lineptr[nlines++] = p;
       }
   return nlines;
}
/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
   int i;
   for (i = 0; i < nlines; i++)
       printf("%s\n", lineptr[i]);
}