# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/pkg/nimble/scanlist/nimble_scanlist.c

# Harness to utilize, omit the extension!
H_ENTRY = nimble_scanlist_update

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Env vars, filled in by LLM
H_DEF = 

# Include paths
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/ \
        -I$(ROOT)/core/lib/include/ \
        -I$(ROOT)/core/include/ \
        -I$(ROOT)/cpu/native/include/ \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/pkg/nimble/scanlist/include \
        -I$(ROOT)/pkg/nimble/scanner/include \
        -I$(ROOT)/pkg/nimble/contrib/include \
        -I$(ROOT)/pkg/nimble/npl/include \
        -I$(ROOT)/build/pkg/nimble/mynewt-nimble/nimble/include \
        -I$(ROOT)/build/pkg/nimble/mynewt-nimble/nimble/host/include \
        -I$(ROOT)/build/pkg/nimble/mynewt-nimble/nimble/transport/include \
        -I$(ROOT)/build/pkg/nimble/mynewt-nimble/porting/npl/riot/include \
        -I$(ROOT)/build/pkg/nimble/mynewt-nimble/porting/nimble/include \
        -I$(ROOT)/pkg/nimble/nimble/include \
        -I$(ROOT)/pkg/nimble/nimble/host/include \
        -I$(ROOT)/pkg/nimble/nimble/transport/include \
        -I$(ROOT)/pkg/nimble/porting/npl/riot/include \
        -I$(ROOT)/pkg/nimble/porting/nimble/include

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include