#include <arch/amd64/gdt.h>

void kmain();

void _start()
{
    gdt_init();
    kmain();
}