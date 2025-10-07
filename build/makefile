include mk/config.mk

ifeq ($(ARCH), amd64)
	include mk/amd64.mk
else
$(error Architecture $(ARCH) not supported)
endif

include mk/iso.mk
include mk/run.mk

all: $(BUILD_KERNEL)