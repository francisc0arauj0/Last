#ifndef BUMP_H
#define BUMP_H

#include <types.h>

struct bump_alloc_t
{
    void *pool;
    size_t size;
    size_t offset;
};

void *bump_alloc(struct bump_alloc_t *alloc, size_t size);

#endif