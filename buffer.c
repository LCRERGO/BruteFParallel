#include <string.h>

#include "buffer.h"

/*
 * Creates a buffer(buf) setting it's size to 0
*/
void
buffer_create(Buffer *buf)
{
    buf->size = 0;
}

/* Returns 1 case buffer is full and 0 otherwise */
int
buffer_full(const Buffer *buf)
{
    return (buf->size == MAX_BUFFER_SIZE - 1) ? 1 : 0;
}

/* Returns 1 case buffer is empty and 0 otherwise */
int
buffer_empty(const Buffer *buf)
{
    return (buf->size == 0) ? 1 : 0;
}

/*
 * Add an element(str) to buffer (buf). In case buffer is full returns -1
 * return 1 in case of success.
*/
int
buffer_add(Buffer *buf, char *key, unsigned char *hash_val)
{
    if (buffer_full(buf))
        return -1;

    memcpy(buf->hash_val[buf->size + 1], hash_val, 2*MD5_DIGEST_LENGTH+1);
    strncpy(buf->key[buf->size + 1], key, MAX_KEY_SIZE);
    buf->size++;

    return 0;
}

/*
 * Logically clears the buffer (buf), sets size to 0
*/
void
buffer_clear(Buffer *buf)
{
    buf->size = 0;
}
