# Defines the root of the project.
# Be aware of how many directories deep you go!

ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
LINK = $(ROOT)/sys/base64/base64.c

# Harness to utilize, omit the extension!
H_ENTRY = base64_encode_base

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2

# Env vars
# Explicitly define module presence to make IS_ACTIVE determinate
# Enable URL-safe mode so urlsafe branches in getsymbol are reachable
H_DEF = -DMODULE_BASE64=1 -DMODULE_BASE64URL=1

# Include paths (no additions needed)
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
