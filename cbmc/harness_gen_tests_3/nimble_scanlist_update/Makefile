# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
# Use the self-contained proof harness implementation of nimble_scanlist_update
LINK = $(ROOT)/cbmc/proofs/nimble_scanlist_update/nimble_scanlist_update_harness.c

# Harness to utilize, omit the extension!
H_ENTRY = nimble_scanlist_update

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2

# Env vars
H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=y -DSOCK_HAS_IPV6=y

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/ \
        -I$(ROOT)/core/lib/include/ \
        -I$(ROOT)/core/include/ \
        -I$(ROOT)/cpu/native/include/ \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/boards/native/include/ \
        -I$(ROOT)/pkg/nimble/scanlist/include \
        -I$(ROOT)/pkg/nimble/scanner/include \
        -I$(ROOT)/pkg/nimble/npl/include \
        -I$(ROOT)/pkg/mynewt-core/include \
        -I$(ROOT)/pkg/nimble/nimble/include \
        -I$(ROOT)/pkg/nimble/nimble/host/include \
        -I$(ROOT)/cbmc/include

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include