# Defines the root of the project.
# Be aware of how many directories deep you go!

ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
LINK = $(ROOT)/sys/net/application_layer/dhcpv6/client.c

# Harness to utilize, omit the extension!
H_ENTRY = _parse_advertise

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2 \
              --unwindset _preparse_advertise.0:4,_preparse_advertise.1:4,_preparse_advertise.2:4,_preparse_advertise.3:4,_preparse_advertise.4:4,_preparse_advertise.5:4

# Compile-time defines
# Enable IPv6, IA_PD (already enabled), and IA_NA with at least one address lease
H_DEF = -DSOCK_HAS_IPV6=1 \
       -DMODULE_DHCPV6_CLIENT_IA_PD=1 \
       -DCONFIG_DHCPV6_CLIENT_PFX_LEASE_MAX=1 \
       -DMODULE_DHCPV6_CLIENT_IA_NA=1 \
       -DCONFIG_DHCPV6_CLIENT_ADDR_LEASE_MAX=1

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include \
        -I$(ROOT)/boards/native/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include