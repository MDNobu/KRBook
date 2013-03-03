#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <ctype.h>
#include "string.h"
#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define MAXVAL  100  /* maximum depth of val stack */

void printstacktop();
double getstacktop();
int swaptoptwo();	

	double lastprinted = -1;
   int sp = 0;          /* next free stack position */
   double val[MAXVAL];  /* value stack */
   /* push:  push f onto value stack */
   void push(double f)
   {
       if (sp < MAXVAL)
           val[sp++] = f;
       else
           printf("error: stack full, can't push %g\n", f);
   }
   /* pop:  pop and return top value from stack */
   double pop(void)
   {
       if (sp > 0)
           return val[--sp];
       else {
           printf("error: stack empty\n");
           return 0.0;
       }
   }  
   
   #define MAXLEN 1024
   
   int getline(char s[], int len) {
   	int i = 0;
   	int c;
   	for(;--len > 0 && (c = getchar()) != EOF && c != '\n'; i++) {
   		s[i] = c;
   	}
	s[i++] = c;	
   	s[i] = '\0';
   	return i;
   }
   
   /*int newgetop(char s[]) {
   	static int i = -1;
   	static char buff[1024];
   	if(i = -1) {
	   		getline(buff, 1024);
	   		i = 0;
   	}
   	int j = 0;
   	printf("%s\n", buff);
   	while(buff[i] == ' ' || buff[i] == '\t')
	   		i++;
   	s[1] = '\0';
   	if(!isdigit(buff[i]) && buff[i] != '.')
	   		return buff[i];
	   		
	for(; isdigit(buff[i]); i++ ) {
		s[j++] = buff[i];
	}
	if(buff[i] == '.') {
		for(; isdigit(buff[i]); i++ ) {
			s[j++] = buff[i];
		}
	}
	s[j] = '\0';
	printf("%s\n", s);
	return NUMBER;
   }*/
   
   int getch(void);
   void ungetch(int);
   /* getop:  get next character or numeric operand */
   int getop(char s[])
   {
       int i, c;
       while ((s[0] = c = getch()) == ' ' || c == '\t')
           ;
       s[1] = '\0';
       if (!isdigit(c) && c != '.')
           return c;      /* not a number */
       i = 0;
       if (isdigit(c))    /* collect integer part */
           while (isdigit(s[++i] = c = getch()))
              ;
       if (c == '.')      /* collect fraction part */
           while (isdigit(s[++i] = c = getch()))
              ;
       s[i] = '\0';
       if (c != EOF)
           ungetch(c);
       return NUMBER;
   }
   
   #define BUFSIZE 100
   char buf[BUFSIZE];    /* buffer for ungetch */
   int bufp = 0;         /* next free position in buf */
   int getch(void)  /* get a (possibly pushed-back) character */
   {
       return (bufp > 0) ? buf[--bufp] : getchar();
   }
   void ungetch(int c)   /* push character back on input */
   {
       if (bufp >= BUFSIZE)
           printf("ungetch: too many characters\n");
       else
           buf[bufp++] = c;
   }
   
   char onebuf = -1;
   
   int newgetch(void) {
   	if(onebuf == -1) {
   		return getchar();
   	} else {
   		int tmp = onebuf;
   		onebuf = -1;
   		return tmp;
   	}
   	//return onebuf == -1 ? getchar() : onebuf;
   }
   
   void newungetch(int c) {
   	onebuf = c;
   }
   
   void ungets(char s[]) {
   	int i;
   	for(i = strlen(s) - 1; i >= 0; i--) {
   		ungetch(s[i]);
   	}
   }   
     
   void printstacktop() {
   		if(sp == 0) {
	   			printf("there is no element");
	   			return;
   			 }	   			
   		printf("top = %f\n", val[sp]);
   		lastprinted = val[sp];
   }
   
   double getstacktop() {
   		if(sp == 0) {
   			printf("there is no element");
   			return -1.0;
   		}
   		return val[sp];
   }
   
   /*int swaptoptwo() {
   		if(sp <= 1) {
   			printf("there is no enough elements");
   			return -1;
   		};
   		
   		double tmp;
   		/*tmp1 = pop();
   		tmp2 = popp();
   		push(tmp1);
   		push(tmp2);*/
	 /*  	tmp = val[sp - 1];
	   	val[sp - 1] = val[sp - 2];
	   	val[sp - 2] = tmp;
   		return 0;	   			
   }*/
   
   void clearstack() {
   	sp = 0;
   }
   