#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#define WORD 1024

struct tnode {
	struct tnode *left;
	struct tnode *right;
	char *word;
	int count;
};

int getword(char *, int );
struct tnode *addNode(struct tnode *,char * );
void printtree(struct tnode *root);
void sort_print(struct tnode *root) ;

int main (int argc, char const* argv[])
{
	char word[WORD];
	struct tnode *root = NULL;
	
	while(getword(word, WORD) != EOF) {
		if(!isalpha(word[0]) )
			continue;
		root = addNode(root, word);
	}
	//printtree(root);

	sort_print(root);
	getchar();
	return 0;
}


char *mymystrdup(char *word) {
	char *result = (char *)malloc(strlen(word) + 1);	
	if(result != NULL)
		strcpy(result, word);
	return result;
}

struct tnode *talloc() {
	return (struct tnode*)malloc(sizeof(struct tnode));
}

struct tnode *addNode(struct tnode *parent,char *word ) {
	int cmp;
	if(parent == NULL) {
		parent = talloc();
		parent->left = NULL;
		parent->right = NULL;
		parent->word = mymystrdup(word);
		parent->count = 1;
	} else if((cmp = strcmp(word, parent->word)) == 0) {
		parent->count++;
	} else if(cmp < 0) {
		parent->left = addNode(parent->left, word);
	} else if(cmp > 0) {
		parent->right = addNode(parent->right, word);
	} 
	return parent;
}

void printtree(struct tnode *root) {
	if(root == NULL) {
		return;
	}
	printtree(root->left);
	
	printf("%s:%d\n", root->word, root->count);
	printf("\n");
	printtree(root->right);
}

struct tnode *sort_list[5000];
int lsp = 0;

void add_to_list(struct tnode *toInsert) {
	int p = lsp - 1;

	for(; p >= 0 && toInsert->count < (sort_list[p])->count; p--) {

		sort_list[p+1] = sort_list[p];
	}
	sort_list[p+1] = toInsert;
	lsp++;
}

void sort_tree(struct tnode *root) {
	if(root == NULL)
		return;	 
	sort_tree(root->left);
	
	add_to_list(root);
	
	sort_tree(root->right);
}


void sort_print(struct tnode *root) {
	
	int i;
	sort_tree(root);
	printf("lsp = %d",lsp); 
	for(i = 0; i < lsp; i++) {
		printf("%s : %d", (sort_list[i])->word, (sort_list[i])->count);
	}
}