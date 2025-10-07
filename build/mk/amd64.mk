CC = gcc
C_FLAGS = -mcmodel=large -ffreestanding -O2 -Wall -Werror -Wextra

SRC = ../kernel/arch/amd64

LD = ld
LD_FLAGS = -nostdlib -T $(SRC)/linker.ld

BUILD_KERNEL:
	mkdir -p obj
	$(CC) $(C_FLAGS) -c $(SRC)/entry/main.c -o obj/main.o
	$(LD) $(LD_FLAGS) -o $(KERNEL) obj/main.o

clean:
	rm -rf obj $(KERNEL) $(ISO)