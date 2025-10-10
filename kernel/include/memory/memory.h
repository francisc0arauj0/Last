#ifndef MEMORY_H
#define MEMORY_H

#include <types.h>
#include <std/stdint.h>

void *memset(void *addr, int value, size_t count);
void *memcpy(void *restrict dest, void *restrict src, size_t count);

#endif