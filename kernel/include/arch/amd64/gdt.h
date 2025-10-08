#ifndef GDT_H
#define GDT_H

#include <std/stdint.h>

struct gdt_segement_t
{
    u16 limit;
    u16 base1;
    u8 base2;
    u8 access;
    u8 flags;   
    u8 base3;
} __attribute__((packed));

struct gdtr_t
{
    u16 size;
    u64 offset;
} __attribute__((packed));

void gdt_init();

#endif
