# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/gcoap/forward_proxy.c

# Harness to utilize, omit the extension!
H_ENTRY = _gcoap_forward_proxy_copy_options

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# Enable MODULE_NANOCOAP_CACHE so IS_USED(MODULE_NANOCOAP_CACHE) evaluates to true
H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=1 -DSOCK_HAS_IPV6=1 -DMODULE_NANOCOAP_CACHE=1

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include \
        -I$(ROOT)/sys/net/application_layer/gcoap/include

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include