# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# Avoid linking forward_proxy.c due to invalid UTF-8 char causing parse error
LINK =

# Harness to utilize, omit the extension!
H_ENTRY = _gcoap_forward_proxy_copy_options

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 2 # Rest to be filled in by LLM

# Env vars, filled in by LLM
# These are harmless to keep, though not required by the stub
H_DEF = -DRIOT_VERSION -DMODULE_SOCK_UDP=1 -DMODULE_NANOCOAP_CACHE=1

# Include paths (kept; not strictly needed by the stub, but non-redundant)
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/ \
        -I$(ROOT)/sys/net/gnrc/sock/include/ \
        -I$(ROOT)/sys/net/application_layer/gcoap/include

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
