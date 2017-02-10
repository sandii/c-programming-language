/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 10, 2017
*
* undefine varible and its definition in list
*/

#include <stdio.h>
#include <stdlib.h> // malloc free
#include <string.h>	// strcmp strlen strcpy

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
	struct nlist* lp = NULL;
	char key[] = "size";
	char ten[] = "10";
	char thirteen[] = "13";
	char hundred[] = "100";
	char thousand[] = "1000";

	set(key, ten);
	lp = get(key);
	printf("%s\n", lp -> val);

	set(key, thirteen);
	printf("%s\n", lp -> val);

	undef(key);
	lp = get(key);
	printf("%d\n", lp == NULL);
}
