#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "ctype.h"
#include "stdlib.h"
#define WORD 1024
#define GROUPSIZE 500

//int nletter = 6;
int getch(void);
void ungetch(int c);
struct key *binsearch(char *word, struct key *tab, int n);

char *mystrdup(char *s)   /* make a duplicate of s */
{
   char *p;
   p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
   if (p != NULL)
       strcpy(p, s);
   return p;
}

char *get_firstn_word(char *word, int n) {
	int i;
	char tmp[WORD];
	for(i = 0; i < n && (tmp[i] =word[i]) != '\0'; i++) {
		
	}
	if(i == n)
		tmp[i] = '\0';
	return mystrdup(tmp);
}

struct key {
   char *word;
   int count;
} keytab[] = {
	"float"
   "auto", 0,
   "break", 0,
   "case", 0,
   "char", 0,
   "const", 0,
   "continue", 0,
   "default", 0,
   "double",0,
   "float",0,
   "int", 0,
   "unsigned", 0,
   "void", 0,
   "volatile", 0,
   "while", 0
};

struct key *binsearch(char *word, struct key *tab, int n);
int getword(char *word, int lim);

struct treenode {
	struct treenode *leftchild;
	struct treenode *rightchild;
	char *key;
	char *value[GROUPSIZE];
	int sp;
};

struct treenode *talloc(void) {
	return (struct treenode *)malloc(sizeof(struct treenode));
}

struct treenode *add_treenode(struct treenode *parent, char * data, int nletter) {
	char *lkey = get_firstn_word(data, nletter);
	if(parent == NULL) {//if node is null, create a node
		parent = talloc();
		parent->leftchild = NULL;
		parent->rightchild = NULL;
		parent->key = lkey;
		parent->value[0] = mystrdup(data);
		parent->sp = 1;
	} else if(strcmp(lkey, parent->key) == 0){
		parent->value[parent->sp++] = mystrdup(data);
	} else if(strcmp(lkey, parent->key) < 0) {
		parent->leftchild = add_treenode(parent->leftchild, data, nletter);
	} else if(strcmp(lkey, parent->key) > 0) {
		parent->rightchild = add_treenode(parent->rightchild, data, nletter);
	}
	return parent;
};

void printtree(struct treenode *root) {
	int i;
	if(root == NULL) {
		return;
	}
	printtree(root->leftchild);
	
	for(i = 0; i < root->sp; i++) {
		printf("%s, ", root->value[i]);
	}
	printf("\n");
	printtree(root->rightchild);
}

int main (int argc, char const* argv[])
{
	char word[WORD];
	struct key *p;
	struct treenode *root = NULL;
	int nletter = 6;
	
	//printf("%d", sizeof keytab / sizeof(struct key));

	while(getword(word, WORD) != EOF) {
		if( !isalpha(word[0]))
			continue;
		p = binsearch(word, keytab, sizeof keytab / sizeof(struct key));
		printf("%d ", p == NULL);
		if(p != NULL) {
			continue;
		}
		root = add_treenode(root, word, nletter);
	}
	printtree(root);
	getchar();
	return 0;
}

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
   int c, getch(void);
   void ungetch(int);
   char *w = word;
   while (isspace(c = getch()))
       ;
   if (c != EOF)
       *w++ = c;
   if (!isalpha(c)) {
       *w = '\0';
       return c;
   }
   for ( ; --lim > 0; w++)
       if (!isalnum(*w = getch())) {
           ungetch(*w);
           break;
       }
   *w = '\0';
   return word[0];
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n)
{
   int cond;
   struct key *low = &tab[0];
   struct key *high = &tab[n];
   struct key *mid;
   while (low < high) {
       mid = low + (high-low) / 2;
       if ((cond = strcmp(word, mid->word)) < 0)
           high = mid;
       else if (cond > 0)
           low = mid + 1;
       else
           return mid;
   }
   return NULL;
}

#define BUFSIZE 1024

int sp = 0;
int val[BUFSIZE];
int getch(void) {
	return --sp > 0 ? val[sp] : getchar();
}

void ungetch(int c) {
	val[sp++] = c;
}