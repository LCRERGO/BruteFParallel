#include <stdint.h>
#include <openssl/md5.h>

#ifndef BUFFER_H
#define BUFFER_H

#define MAX_BUFFER_SIZE 4096
#define MAX_KEY_SIZE 10

typedef struct buffer_t {
    char key[MAX_BUFFER_SIZE][MAX_KEY_SIZE];
    unsigned char hash_val[MAX_BUFFER_SIZE][2*MD5_DIGEST_LENGTH+1];
    uint64_t size;
} Buffer;


void buffer_create(Buffer *buf);
int buffer_full(const Buffer *buf);
int buffer_empty(const Buffer *buf);
int buffer_add(Buffer *buf, char *key, unsigned char *hash_val);
void buffer_clear(Buffer *buf);
#endif
