# Defines the root of the project.
# Be aware of how many directories deep you go!
<<<<<<< HEAD:cbmc/proofs/clif_decode_link/Makefile
ROOT ?= ../../..
=======
ROOT = ../../..
>>>>>>> nimble_scanlist_update:cbmc/proofs/nimble_scanlist_update/Makefile

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
<<<<<<< HEAD:cbmc/proofs/clif_decode_link/Makefile
LINK = $(ROOT)/sys/clif/clif.c

# Harness to utilize, omit the extension!
H_ENTRY = clif_decode_link

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1
=======
# LINK = $(ROOT)/pkg/nimble/scanlist/nimble_scanlist.c

# Harness to utilize, omit the extension!
H_ENTRY = nimble_scanlist_update

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static 
>>>>>>> nimble_scanlist_update:cbmc/proofs/nimble_scanlist_update/Makefile

H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=y -DSOCK_HAS_IPV6=y

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
<<<<<<< HEAD:cbmc/proofs/clif_decode_link/Makefile
            -I$(ROOT)/sys/clif/include/ \


=======
            -I$(ROOT)/pkg/nimble/scanlist/include/ \
            -I$(ROOT)/pkg/nimble/scanner/include/ \
            -I$(ROOT)/cbmc/include/ \
            -I$(ROOT)/pkg/mynewt-core/include/ \
            -I$(ROOT)/pkg/nimble/npl/include/
>>>>>>> nimble_scanlist_update:cbmc/proofs/nimble_scanlist_update/Makefile

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
