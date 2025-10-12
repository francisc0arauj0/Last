CC = gcc
C_FLAGS = -g -mcmodel=large -ffreestanding -mno-sse -O2 -Wall -Werror -Wextra -I../kernel/include/

SRC = ../kernel

LD = ld
LD_FLAGS = -nostdlib -T $(SRC)/arch/amd64/linker.ld

BUILD_KERNEL:
	mkdir -p obj
	$(CC) $(C_FLAGS) -c $(SRC)/entry/main.c -o obj/main.o
	$(CC) $(C_FLAGS) -c $(SRC)/arch/amd64/arch.c -o obj/arch.o
	$(CC) $(C_FLAGS) -c $(SRC)/arch/amd64/cpu/gdt.c -o obj/gdt.o
	$(CC) $(C_FLAGS) -c $(SRC)/memory/memory.c -o obj/memory.o
	$(CC) $(C_FLAGS) -c $(SRC)/graphical/framebuffer.c -o obj/framebuffer.o
	$(LD) $(LD_FLAGS) -o $(KERNEL) obj/*.o

clean:
	rm -rf obj $(KERNEL) $(ISO)