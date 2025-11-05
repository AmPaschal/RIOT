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
H_CBMCFLAGS = --nondet-static --unwind 2 # Rest to be filled in by LLM

# Env vars
# Enable IPv6 module, nettype enums for IPv6 and 6LoWPAN, IPHC module, GNRC netif IPv6 support, and NHC support
H_DEF = -DMODULE_GNRC_IPV6=1 -DMODULE_GNRC_SIXLOWPAN_IPHC=1 -DMODULE_GNRC_NETTYPE_IPV6=1 -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 -DMODULE_GNRC_NETIF_IPV6=1 -DMODULE_GNRC_SIXLOWPAN_IPHC_NHC=1

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
