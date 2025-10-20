# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/dhcpv6/client.c

# Harness to utilize, omit the extension!
H_ENTRY = _preparse_advertise

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Env vars, filled in by LLM
# Force-include the header that defines dhcpv6_duid_l2_t so it is visible
# before _dhcpv6.h (the harness includes _dhcpv6.h first)
# Define SOCK_HAS_IPV6 so sock_udp_ep_t has the .ipv6 member
H_DEF = -include $(ROOT)/sys/include/net/dhcpv6/client.h \
       -DSOCK_HAS_IPV6

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include/ \
        -I$(ROOT)/boards/native/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include