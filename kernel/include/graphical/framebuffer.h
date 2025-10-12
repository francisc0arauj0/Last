#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <std/stdint.h>
#include <types.h>

struct framebuffer_t
{
    u8 *addr;
	size_t width;
	size_t height;
	size_t pitch;
	size_t bpp;
	
	size_t red_shift;
	size_t red_size;
	size_t green_shift;
	size_t green_size;
	size_t blue_shift;
	size_t blue_size;
};

void framebuffer_init();

#endif