# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/routing/rpl/gnrc_rpl_control_messages.c

# Harness to utilize, omit the extension!
H_ENTRY = _parse_options

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Env vars
# Map evtimer_msg_t to evtimer_t since globals.h only includes evtimer.h
# Enable IPv6 component in gnrc_netif_t so netif->ipv6 exists
# Enable GNRC IPv6 nettype so GNRC_NETTYPE_IPV6 is defined in nettype.h
H_DEF = -Devtimer_msg_t=evtimer_t -DMODULE_GNRC_NETIF_IPV6=1 -DMODULE_GNRC_NETTYPE_IPV6=1

# Include paths (add board-specific include for native to resolve board.h)
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