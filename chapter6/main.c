/*
 * main.c
 *
 *  Created on: 2013-3-2
 *      Author: qin
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

#define WORD 1024
struct nlist { /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name */
	char *defn; /* replacement text */
};

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s) ;
int getword(char *word, int lim);
void ungetchword(char *word);

int main(int argc, char *argv[]) {
	int c;
	char word[WORD], name[WORD], defn[WORD];

	while((c = getword(word, WORD)) != EOF) {
		if(c == '#' ) {
			c = getword(word, WORD);
			if(strcmp(word, "define")) {
				getword(name, WORD);
				getword(defn, WORD);
				install(name, defn);
			} else {
				ungetchword(word);
			}
			continue;
		}
		if(!isalpha(c))
			continue;

		if(lookup(word) != NULL) {
			ungetchword(word);
		} else {
			printf("%s", word);
		}
	}


	return 0;
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash:  form hash value for string s */
unsigned hash(char *s) {
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup:  look for s in hashtab */
struct nlist *lookup(char *s) {
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL ; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL ; /* not found */
}

/*struct nlist *lookup(char *);*/
char *mystrdup(char *);
/* install:  put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL ) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = mystrdup(name)) == NULL )
			return NULL ;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		/* already there */
		free((void *) np->defn); /*free previous defn */
	if ((np->defn = mystrdup(defn)) == NULL )
		return NULL ;
	return np;
}

struct nlist *undef(char *name) {
	struct nlist *cur, *pre;
	/*if((p = lookup(name)) == NULL) {
	 return NULL;
	 }*/
	cur = hashtab[hash(name)];
	if (strcmp(cur->name, name)) {
		hashtab[hash(name)] = cur->next;
		cur->next = NULL;
		return cur;
	}

	for (cur = cur->next; cur != NULL && strcmp(cur->name, name);
			cur = cur->next) {
		pre = cur;
	}
	if (cur == NULL )
		return NULL ;
	pre->next = cur->next;
	cur->next = NULL;
	return cur;
}
