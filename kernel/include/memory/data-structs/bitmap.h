#ifndef BITMAP_H
#define BITMAP_H


#include <std/stdint.h>
#include <std/stdbool.h>
#include <types.h>

struct bitmap_t
{
    u8 *bitmap;
};

#define BLOCKS_PER_BYTE 8
#define BLOCK_SIZE 4096
#define INVALID_BLOCK ((size_t)-1)

void bitmap_set(struct bitmap_t *bp, size_t block);
void bitmap_clear(struct bitmap_t *bp, size_t block);
int bitmap_get(struct bitmap_t *bp, size_t block);

#endif