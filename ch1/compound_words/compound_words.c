#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../simple_hash_function/hash_func.h"

#define NUM_BITS 17
#define WORD_LENGTH 16

typedef struct word_node {
	char **word;
	struct word_node *next;
} word_node;

// Read a word from stdin.
char *read_line(int size) {
	char *str;
	int ch, len = 0;

	str = malloc(size);
	
	if(str == NULL) {
		fprintf(stderr, "malloc error");
		exit(1);
	}

	while((ch = getchar()) != EOF && (ch != '\n')) {
		str[len++] = ch;

		if(len == size) {
			size *= 2;
			str = realloc(str, size);
			
			if(str == NULL) {
				fprintf(stderr, "realloc error");
				exit(1);
			}
		}
	}
	str[len] = '\0';
	return str;
}

// checks the hash table contains the word defined by find
int in_hash_table(word_node *hash_table[], char *find, unsigned find_len) {
	unsigned word_code;
	word_node *wordptr;

	word_code = oaat(find, find_len, NUM_BITS);
	wordptr = hash_table[word_code];
	printf("in_hash_table\nword - %s findlen: %d word_code - %d\n", find, find_len, word_code);

	while(wordptr) {
		if((strlen(*(wordptr->word)) == find_len) && 
				(strncmp(*(wordptr->word), find, find_len) == 0))
			return 1;
		wordptr = wordptr->next;
	}
	return 0;
}

void identify_compound_words(char *words[], word_node *hash_table[], int total_words) {
	unsigned len;

	for(int i = 0; i < total_words; i++) {
		len = strlen(words[i]);
		for(int j = 1; j < len + 1; j++) {
			if(in_hash_table(hash_table, words[i], j) &&
					in_hash_table(hash_table, &words[i][j], len - j)) {
				printf("%s\n", words[i]);
				break;
			}
		}
	}
	printf("No compound word found.\n");
}

int main(void) {
	static char *words[1 << NUM_BITS] = {NULL};
	static word_node *hash_table[1 << NUM_BITS] = {NULL};

	int total = 0;
	char *word;
	word_node *wordptr;
	unsigned long length = 0;
	unsigned long word_code;

	word = read_line(WORD_LENGTH);

	while (*word) {
		words[total] = word;
		wordptr = malloc(sizeof(word_node));
		
		if(wordptr == NULL) {
			fprintf(stderr, "malloc error\n");
			exit(1);
		}

		length = strlen(word);
		word_code = oaat(word, length, NUM_BITS);
		printf("main\nword - %s word_code - %lu\n", word, word_code);
		wordptr->word = &words[total];
		wordptr->next = hash_table[word_code];
		
		hash_table[word_code] = wordptr;
		word = read_line(WORD_LENGTH);
		total++;
	}
	identify_compound_words(words, hash_table, total);

	for(int i = 0; i < total; i++)
		printf("%s\n", words[i]);

	return 0;
}

// you'll be calling the same function but it's like you are calling two different
// functions. They'll be producing wonderful outputs.
