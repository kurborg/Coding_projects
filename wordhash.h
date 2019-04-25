#ifndef WORDHASH_H_
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>

	#define HASH_TABLE_SIZE 26		// 26 characters (A-Z)
	#define WORD_SIZE 50

	typedef enum {false  = 0, true = 1}  boolean;

	struct node {
		char *data;
		struct node *next;
	};

	struct hash_entry {
		int count;
		struct node *head;
	};

	#define WORDHASH_H_
#endif
