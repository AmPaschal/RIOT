# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/cord/lc/cord_lc.c

# Harness to utilize, omit the extension!
H_ENTRY = _on_rd_init

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2

# Env vars, filled in by LLM
# Define R IOT_VERSION so nanocoap.h includes RIOT headers (incl. bitfield.h)
# Define MODULE_SOCK_UDP so nanocoap.h uses net/sock/udp.h and does not typedef sock_udp_ep_t again
H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=1

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include/ \
        -I$(ROOT)/sys/clif/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include