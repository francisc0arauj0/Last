#include <memory/data-structs/bitmap.h>

void bitmap_set(struct bitmap_t *bp, size_t block)
{
    size_t addr = block / BLOCKS_PER_BYTE;
    size_t offset = block % BLOCKS_PER_BYTE;
    bp->bitmap[addr] |= (1 << offset);
}

void bitmap_clear(struct bitmap_t *bp, size_t block)
{
    size_t addr = block / BLOCKS_PER_BYTE;
    size_t offset = block % BLOCKS_PER_BYTE;
    bp->bitmap[addr] &= ~(1 << offset);
}

int bitmap_get(struct bitmap_t *bp, size_t block)
{
    size_t addr = block / BLOCKS_PER_BYTE;
    size_t offset = block % BLOCKS_PER_BYTE;
    return (bp->bitmap[addr] & (1 << offset)) != 0;
}