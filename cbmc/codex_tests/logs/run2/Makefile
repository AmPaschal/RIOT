# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Harness to utilize, omit the extension!
H_ENTRY = _receive

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2

# Env vars
H_DEF = -DMODULE_GNRC_NETTYPE_TCP -DMODULE_GNRC_NETTYPE_IPV6 -DMODULE_GNRC_IPV6 -DMAXTHREADS=1

# Includes
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/ \
        -I$(ROOT)/core/lib/include/ \
        -I$(ROOT)/core/include/ \
        -I$(ROOT)/cpu/native/include/ \
        -I$(ROOT)/drivers/include/ \

# No additional link files needed since the harness includes the implementation directly
LINK =

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
