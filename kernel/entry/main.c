#include <graphical/framebuffer.h>
#include <limine/limine.h>

static volatile LIMINE_BASE_REVISION(3);

void kmain()
{
    framebuffer_init();

    for (;;)
    {
        asm ("hlt");
    }
}