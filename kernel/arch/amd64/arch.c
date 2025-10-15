#include <arch/amd64/gdt.h>
#include <arch/amd64/sse.h>

void kmain();

void _start()
{
    gdt_init();
    sse_init();
    kmain();
}