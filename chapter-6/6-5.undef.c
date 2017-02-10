/*
* author: chenzhi <chenzhibupt@qq.com>
* data: Feb 10, 2017
*
* undefine varible and its definition in list
*/

#include <stdio.h>
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

	// no node
	if (np == NULL) {
		np = (struct nlist*) malloc(sizeof struct nlist);
		np -> key = (char*) malloc(strlen(key) + 1);
		np -> val = (char*) malloc(strlen(key) + 1);
		strcpy(np -> key, key);
		strcpy(np -> val, val);
		unsigned hashVal = hash(key);
		np -> next = hashtab[hashVal];
		hashtab[hashVal] = np;
	}
	// node exist
	return np;
}



main () {
	struct nlist* lp = NULL;
	set("size", "100");
	lp = get("size");
	printf("%s\n", lp -> val);
}
