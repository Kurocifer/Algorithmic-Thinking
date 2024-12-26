#include <stdio.h>
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

// one-at-a-time hash function
unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
	unsigned long hash;
	

	for(int i = 0, hash = 0; i < len; i++) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += (hash << 3);
	hash += (hash >> 1);
	hash ^= (hash << 15);

	// Why assign it to a variable before returning instead of just returning directly...
	// for some readon when I return directly it does not work as expected and I can't even phantom why :)
	unsigned long final_hash = hash & hashmask(bits);
	return final_hash;
}

/*
int main(void) {
	long snowflake[] = {1, 2, 3, 4, 5, 6};

	unsigned long code = oaat((char *)snowflake, sizeof(snowflake), 17);
	
	printf("%lu\n", code);
	return 0;
}
*/
