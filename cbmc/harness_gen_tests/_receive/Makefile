# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/transport_layer/tcp/gnrc_tcp_eventloop.c

# Harness to utilize, omit the extension!
H_ENTRY = _receive

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# Enable GNRC_NETTYPE_TCP, and provide default for the eventloop message queue exp
H_DEF = -DMODULE_GNRC_NETTYPE_TCP=1 \
       -DCONFIG_GNRC_TCP_EVENTLOOP_MSG_QUEUE_SIZE_EXP=3

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
