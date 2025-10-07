include mk/config.mk

QEMU = qemu-system-$(ARCH)
QEMU_FLAGS = -M q35 -m 2G -monitor stdio -d int -M smm=off

run: ovmf-code-$(ARCH).fd $(ISO)
	$(QEMU) -drive if=pflash,unit=0,format=raw,file=ovmf-code-$(ARCH).fd,readonly=on $(QEMU_FLAGS) -cdrom $(ISO)