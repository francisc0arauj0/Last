CC = gcc
C_FLAGS = -mcmodel=large -ffreestanding -O2 -Wall -Werror -Wextra -I../kernel/include/

SRC = ../kernel/arch/amd64

LD = ld
LD_FLAGS = -nostdlib -T $(SRC)/linker.ld

BUILD_KERNEL:
	mkdir -p obj
	$(CC) $(C_FLAGS) -c ../kernel/entry/main.c -o obj/main.o
	$(CC) $(C_FLAGS) -c $(SRC)/arch.c -o obj/arch.o
	$(CC) $(C_FLAGS) -c $(SRC)/cpu/gdt.c -o obj/gdt.o
	$(LD) $(LD_FLAGS) -o $(KERNEL) obj/*.o

clean:
	rm -rf obj $(KERNEL) $(ISO)