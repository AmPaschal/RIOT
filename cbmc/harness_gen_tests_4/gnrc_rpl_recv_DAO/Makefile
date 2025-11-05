# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/routing/rpl/gnrc_rpl_control_messages.c

# Harness to utilize, omit the extension!
H_ENTRY = gnrc_rpl_recv_DAO

# Extra CBMC flags to be passed during CBMC analysis
# Increase unwinding specifically for the inner for-loop in _find_interface_with_rpl_mcast
H_CBMCFLAGS = --nondet-static --unwind 2 --unwindset _find_interface_with_rpl_mcast.0:5 # Rest to be filled in by LLM

# Env vars
# Map evtimer_msg_t to evtimer_t to match typedef in evtimer_msg.h and enable needed modules
# Force DEBUG(...) to evaluate its arguments (so ipv6_addr_to_str is called)
# and prevent debug.h from redefining DEBUG.
H_DEF = -Devtimer_msg_t=evtimer_t -DMODULE_GNRC_NETIF_IPV6=1 -DMODULE_GNRC_NETTYPE_IPV6=1 -DDEBUG=printf -DDEBUG_H

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