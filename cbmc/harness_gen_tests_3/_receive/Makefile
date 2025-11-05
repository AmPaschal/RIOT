# Defines the root of the project.
ROOT ?= ../../..

# Files to link with the harness
LINK = $(ROOT)/sys/net/gnrc/transport_layer/tcp/gnrc_tcp_eventloop.c

# Harness entry (omit extension)
H_ENTRY = _receive

# Extra CBMC flags
H_CBMCFLAGS = --nondet-static --unwind 2

# Preprocessor defines: enable required nettypes and IPv6 module code
H_DEF = -DMODULE_GNRC_NETTYPE_TCP=1 -DMODULE_GNRC_NETTYPE_IPV6=1 -DMODULE_GNRC_IPV6=1

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/transport_layer/tcp

# Include the shared build rules
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include