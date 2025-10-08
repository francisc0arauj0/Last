#include <arch/amd64/gdt.h>

void kmain()
{
    gdt_init();

    for (;;)
    {
        asm ("hlt");
    }
}