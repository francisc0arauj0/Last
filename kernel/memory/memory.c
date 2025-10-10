#include <memory/memory.h>

void *memset(void *addr, int value, size_t count) 
{
    u8 *ptr = (u8 *)addr;

    for (size_t i = 0; i < count; i++)
    {
        ptr[i] = (u8)value;
    }

    return addr;
}

void *memcpy(void *restrict dest, void *restrict src, size_t count)
{
    u8 *restrict pdest = (u8 *restrict)dest;
    const u8 *restrict psrc = (const u8 *restrict)src;

    for (size_t i = 0; i < count; i++)
    {
        pdest[i] = psrc[i];
    }

    return dest;
}