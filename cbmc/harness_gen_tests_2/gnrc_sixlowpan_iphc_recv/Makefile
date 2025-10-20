# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c

# Harness to utilize, omit the extension!
H_ENTRY = gnrc_sixlowpan_iphc_recv

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Env vars, filled in by LLM
# Enable required modules (avoid defining GNRC_NETTYPE_* which are enum values)
H_DEF = -DMODULE_GNRC_IPV6=1 -DMODULE_GNRC_SIXLOWPAN_IPHC=1 -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 \
        -DMODULE_GNRC_NETTYPE_IPV6=1

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include