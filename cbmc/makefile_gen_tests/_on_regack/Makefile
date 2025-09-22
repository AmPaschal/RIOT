# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/asymcute/asymcute.c

# Harness to utilize, omit the extension!
H_ENTRY = _on_regack

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# Enable asynchronous sock API so sock_async_flags_t is defined
# Also enable GNRC netapi callbacks so gnrc_netreg_entry_cbd_t is declared
# Enable IPv6 support so SOCK_IPV6_EP_ANY is defined in net/sock.h
H_DEF = -DSOCK_HAS_ASYNC=1 -DMODULE_GNRC_NETAPI_CALLBACKS=1 -DSOCK_HAS_IPV6=1

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
