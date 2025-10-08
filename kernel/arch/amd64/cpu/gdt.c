#include <arch/amd64/gdt.h>

struct gdt_segement_t entries[7];
struct gdtr_t gdtr;

static void gdt_set_segment(u8 id, u64 base, u64 limit, u8 access, u8 flags)
{
    entries[id].base1 = base & 0xFFFF;
    entries[id].base2 = (base >> 16) & 0xFF;
    entries[id].base3 = (base >> 24) & 0xFF;

    entries[id].limit = limit & 0xFFFF;
    entries[id].flags = (limit >> 16) & 0x0F;
    entries[id].flags |= flags & 0xF0;

    entries[id].access = access;
}

static void gdt_load()
{
    asm volatile("lgdt %0" : : "m"(gdtr));
}

static void gdt_flush()
{
    asm volatile (
        "pushq $0x08\n"
        "lea reload_seg(%%rip), %%rax\n"
        "pushq %%rax\n"
        "lretq\n"
        "reload_seg:\n"
        "mov $0x10, %%ax\n"
        "mov %%ax, %%ds\n"
        "mov %%ax, %%es\n"
        "mov %%ax, %%fs\n"
        "mov %%ax, %%gs\n"
        "mov %%ax, %%ss\n"
        : : : "eax", "memory"
    );
}

void gdt_init()
{
    gdtr.size = sizeof(struct gdt_segement_t) * 7 - 1;
    gdtr.offset = (u64)&entries;

    gdt_set_segment(0, 0, 0, 0, 0);
    gdt_set_segment(1, 0, 0, 0x9A, 0xA0);
    gdt_set_segment(2, 0, 0, 0x92, 0xC0);
    gdt_set_segment(3, 0, 0, 0xFA, 0xA0);
    gdt_set_segment(4, 0, 0, 0xF2, 0xC0);

    gdt_load();
    gdt_flush();
}