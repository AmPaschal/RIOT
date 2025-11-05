# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/routing/rpl/srh/gnrc_rpl_srh.c

# Harness to utilize, omit the extension!
H_ENTRY = gnrc_rpl_srh_process

# Extra CBMC flags to be passed during CBMC analysis
# Increase unwinding specifically for the loop in _contains_multiple_of_my_addr
H_CBMCFLAGS = --nondet-static --unwind 2 --unwindset _contains_multiple_of_my_addr.1:3

# Env vars, filled in by LLM
# Ensure gnrc_netif_get_by_ipv6_addr prototype is visible in netif/internal.h
H_DEF = -DMODULE_GNRC_NETIF_IPV6=1

# LLM should add more to this
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include

# Override the report target to avoid permission issues when writing traces
report: cbmc.xml property.xml coverage.xml
	$(VIEWER) \
	--goto build/$(ENTRY).goto \
	--srcdir $(ROOT) \
	--reportdir build/report_alt \
	--result build/reports/cbmc.xml \
	--property build/reports/property.xml \
	--coverage build/reports/coverage.xml