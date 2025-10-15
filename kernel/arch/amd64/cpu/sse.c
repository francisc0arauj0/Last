#include <arch/amd64/sse.h>

static inline void enable_fpu(void) {
    asm volatile (
        "mov %%cr0, %%rax\n"
        "and $0xFFFB, %%ax\n"
        "or $2, %%eax\n"
        "mov %%rax, %%cr0\n"
        :
        :
        : "rax"
    );
}

static inline void enable_sse(void) {
    asm volatile (
        "mov %%cr4, %%rax\n"
        "or $0b11000000000, %%rax\n"
        "mov %%rax, %%cr4\n"
        :
        :
        : "rax"
    );
}

void sse_init()
{
    enable_fpu();
    enable_sse();
}