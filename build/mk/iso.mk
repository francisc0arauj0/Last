include mk/config.mk

XORRISO = xorriso
XORRISO_FLAGS = -R -r -J -hfsplus -apm-block-size 2048 --efi-boot boot/limine-uefi-cd.bin -efi-boot-part --efi-boot-image --protective-msdos-label

iso: $(ISO)

$(ISO): ../bootloader $(KERNEL) ../init/limine.conf
	rm -rf iso_root
	mkdir -p iso_root/boot iso_root/EFI/BOOT
	cp -v $(KERNEL) iso_root/boot/kernel
	cp -v ../init/limine.conf iso_root/boot/
	cp -v ../bootloader/limine-uefi-cd.bin iso_root/boot/
	cp -v ../bootloader/BOOTX64.EFI iso_root/EFI/BOOT/
	$(XORRISO) -as mkisofs $(XORRISO_FLAGS) iso_root -o $(IMAGE_NAME)
	rm -rf iso_root