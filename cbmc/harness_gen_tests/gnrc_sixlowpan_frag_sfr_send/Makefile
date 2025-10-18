# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/frag/sfr/gnrc_sixlowpan_frag_sfr.c

# Harness to utilize, omit the extension!
H_ENTRY = gnrc_sixlowpan_frag_sfr_send

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 # Rest to be filled in by LLM

# Env vars
H_DEF = -DMODULE_XTIMER_ON_ZTIMER=1 \
       -DMODULE_GNRC_SIXLOWPAN_FRAG=1 \
       -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR=1 \
       -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 \
       -DMODULE_GNRC_NETIF_6LO=1

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/boards/native/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include