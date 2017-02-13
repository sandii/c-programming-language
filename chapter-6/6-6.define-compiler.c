/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 13, 2017
*
* compile #define
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // malloc free
#include <string.h>	// strcmp strlen strcpy

#define MAX_WORD_LEN 100
char word [MAX_WORD_LEN];

int buff = -1;
int getch () {
	if (buff == -1) {
		return getchar();
	} else {
		int c = buff;
		buff = -1;
		return c;
	}
}
void ungetch (int c) {
	buff = c;
}

int getword () {
	char* wp = word;
	int c;

	while (c = getch()) {
		if (c == EOF) return c;

		// string constant
		if (c == '"') {
			while ((c = getch()) != '"') {
				if (c == EOF) return c;
			}
			c = getch();
		}

		// char constant
		if (c == '\'') {
			while ((c = getch()) != '\'') {
				if (c == EOF) return c;
			}
			c = getch();
		}

		// comment
		if (c == '/') {
			// //
			if ((c = getch()) == '/') {
				while ((c = getch()) != '\n') {
					if (c == EOF) return c;
				}
				c = getch();
			// /* ... */		
			} else if (c == '*') {
				bool readyToEnd = false;
				while (c = getch()) {
					if (c == EOF) return c;
					if (c == '/' && readyToEnd) break;
					readyToEnd = c == '*';
				}
				c = getch();
			}
		}

		// # leading word
		if (isalnum(c) || c == '#' || c == '_') {
			if (c == '#') {
				*wp++ = '#';
				while (isalpha(c = getch())) {
					*wp++ = c;
					if (wp - word >= MAX_WORD_LEN - 1) break;
				}
			
			// number
			} else if (isdigit(c)) {
				ungetch(c);
				while (isdigit(c = getch())) {
					*wp++ = c;
					if (wp - word >= MAX_WORD_LEN - 1) break;
				}
			
			// word
			} else if (isalpha(c) || c == '_') {
				ungetch(c);
				while (isalnum(c = getch()) || c == '_') {
					*wp++ = c;
					if (wp - word >= MAX_WORD_LEN - 1) break;
				}
			}
			ungetch(c);
			*wp = '\0';
			return word[0];
		}
	}
}


struct nlist {
	struct nlist* next;
	char* key;
	char* val;
};

#define HASH_SIZE 101
struct nlist* hashtab[HASH_SIZE];

unsigned hash (char* cp) {
	unsigned hashVal = 0;
	for ( ; *cp != '\0'; cp++) {
		hashVal = hashVal * 31 + *cp;
	}
	return hashVal % HASH_SIZE;	
}

struct nlist* get (char* key) {
	struct nlist* np = hashtab[hash(key)];
	for ( ; np != NULL; np = np -> next) {
		if (strcmp(key, np -> key) == 0) return np;
	}
	return NULL;
}

struct nlist* set (char* key, char* val) {
	struct nlist* np = get(key);

	// not found
	if (np == NULL) {
		np = (struct nlist*) malloc(sizeof (struct nlist));
		np -> key = (char*) malloc(strlen(key) + 1);
		strcpy(np -> key, key);
		unsigned hashVal = hash(key);
		np -> next = hashtab[hashVal];
		hashtab[hashVal] = np;

	// already there
	} else {
		free((void*) np -> val);
	}
	np -> val = (char*) malloc(strlen(val) + 1);
	strcpy(np -> val, val);
	return np;
}

bool undef (char* key) {
	unsigned hashVal = hash(key);
	struct nlist* prev = NULL;
	struct nlist* curr = hashtab[hashVal];
	while (curr != NULL) {
		if (strcmp(key, curr -> key) == 0) break;
		prev = curr;
		curr = curr -> next;
	}
	// not found
	if (curr == NULL) return false;

	// is root of link-list
	if (prev == NULL) {
		hashtab[hashVal] = NULL;
	} else {
		prev -> next = curr -> next;
	}

	free((void*) curr -> key);
	free((void*) curr -> val);
	free((void*) curr);
	return true;
}

main () {
	struct nlist* np = NULL;
	char key[MAX_WORD_LEN];
	char val[MAX_WORD_LEN];
	while (getword() != EOF) {
		if (strcmp(word, "#define") == 0) {
			getword(); strcpy(key, word);
			getword(); strcpy(val, word);
			set(key, val);
			continue;
		}
		printf("%s\n", (np = get(word)) == NULL ? word : np -> val);
	}
}
