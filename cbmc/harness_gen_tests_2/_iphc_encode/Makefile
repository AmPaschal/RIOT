# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c

# Harness to utilize, omit the extension!
H_ENTRY = _iphc_encode

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# Define IPv6 module so gnrc_netif_hdr_ipv6_iid_from_src/dst are real functions
# Also enable GNRC_NETTYPE_IPV6 so GNRC_NETTYPE_IPV6 enum is available
# Add GNRC_NETTYPE_SIXLOWPAN so GNRC_NETTYPE_SIXLOWPAN becomes available in gnrc/nettype.h
H_DEF = -DMODULE_GNRC_IPV6=1 -DMODULE_GNRC_NETTYPE_IPV6=1 -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include