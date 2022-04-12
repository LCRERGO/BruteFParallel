#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#include "bench.h"

#define MAX 10

typedef unsigned char byte;
char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

/*
 * Print a digest of MD5 hash.
*/
void print_digest(byte * hash){
	int x;

	for(x = 0; x < MD5_DIGEST_LENGTH; x++)
        	printf("%02x", hash[x]);
	printf("\n");
}

/*
 * This procedure generate all combinations of possible letters
*/
void iterate(byte *hash1, byte *hash2, char *str, int len, int *ok)
{
    int i, v, aux_v;
    int alph_len = strlen(letters);
    uint64_t num_entries = (uint64_t)pow(alph_len, len);

    for (v = 0; v < num_entries; v++) {
        str[len] = 0;
        aux_v = v;
        for (i = len - 1; i >= 0; --i) {
            str[i] = letters[aux_v % alph_len];
            aux_v /= alph_len;
        }
        MD5((byte *) str, strlen(str), hash2);
        if(strncmp((char*)hash1, (char*)hash2, MD5_DIGEST_LENGTH) == 0){
            printf("found: %s\n", str);
            // print_digest(hash2);
            *ok = 1;
            return;
        }
    }
}

/*
 * Convert hexadecimal string to hash byte.
*/
void strHex_to_byte(char * str, byte * hash){
	char * pos = str;
	int i;

	for (i = 0; i < MD5_DIGEST_LENGTH/sizeof *hash; i++) {
		sscanf(pos, "%2hhx", &hash[i]);
		pos += 2;
	}
}

int main(int argc, char **argv) {
	char str[MAX+1];
	int lenMax = MAX;
	int len;
	int ok = 0, r;
	char hash1_str[2*MD5_DIGEST_LENGTH+1];
	byte hash1[MD5_DIGEST_LENGTH]; // password hash
	byte hash2[MD5_DIGEST_LENGTH]; // string hashes

	// Input:
	r = scanf("%s", hash1_str);

	// Check input.
	if (r == EOF || r == 0)
	{
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	// Convert hexadecimal string to hash byte.
	strHex_to_byte(hash1_str, hash1);

	memset(hash2, 0, MD5_DIGEST_LENGTH);
	//print_digest(hash1);

	// Generate all possible passwords of different sizes.
	for(len = 1; len <= lenMax && !ok; len++){
		memset(str, 0, len+1);
                iterate(hash1, hash2, str, len, &ok);
	}
}
