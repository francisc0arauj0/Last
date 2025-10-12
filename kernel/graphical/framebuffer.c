#include <graphical/framebuffer.h>
#include <limine/limine.h>

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

struct limine_framebuffer *framebuffer_response;
struct framebuffer_t framebuffer;

void framebuffer_init()
{
    framebuffer_response = framebuffer_request.response->framebuffers[0];

    framebuffer.addr = framebuffer_response->address;
    framebuffer.height = framebuffer_response->height;
    framebuffer.width = framebuffer_response->width;
    framebuffer.pitch = framebuffer_response->pitch;
    framebuffer.bpp = framebuffer_response->bpp;
    framebuffer.red_shift = framebuffer_response->red_mask_shift;
	framebuffer.red_size = framebuffer_response->red_mask_size;
	framebuffer.green_shift = framebuffer_response->green_mask_shift;
	framebuffer.green_size = framebuffer_response->green_mask_size;
	framebuffer.blue_shift = framebuffer_response->blue_mask_shift;
	framebuffer.blue_size = framebuffer_response->blue_mask_size;
}