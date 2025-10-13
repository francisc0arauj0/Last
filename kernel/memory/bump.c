#include <std/stddef.h>
#include <std/stdint.h>
#include <memory/bump.h>
#include <util.h>

void *bump_alloc(struct bump_alloc_t *alloc, size_t size)
{
    size = ALIGN_UP(size, 16);

    size_t next_ptr = alloc->offset + size;

    if (next_ptr > alloc->size)
    {
        return NULL;
    };

    void *ptr = (u8 *)alloc->pool + alloc->offset;
    alloc->offset = next_ptr;

    return ptr;
}