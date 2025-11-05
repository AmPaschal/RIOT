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
H_CBMCFLAGS = --nondet-static --unwind 2 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# Enable SFR so the sfr member is present in gnrc_sixlowpan_frag_fb_t
# Enable the nettype so GNRC_NETTYPE_SIXLOWPAN is defined
# Enable 6Lo component so gnrc_netif_t has the 'sixlo' member
# Enable TX_SYNC so IS_USED(MODULE_GNRC_TX_SYNC) evaluates to true
# Enable ECN so _check_for_ecn body becomes reachable
# Also enable ECN submodules so lines 833+ become executable
H_DEF = -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR=1 -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 -DMODULE_GNRC_NETIF_6LO=1 -DMODULE_GNRC_TX_SYNC=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR_ECN=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR_ECN_IF_IN=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR_ECN_IF_OUT=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR_ECN_FQUEUE=1

# LLM should add more to this
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