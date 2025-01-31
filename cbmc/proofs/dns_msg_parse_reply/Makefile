# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = /home/tlelievr/RIOT

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/dns/msg.c

# Harness to utilize, omit the extension!
H_ENTRY = dns_msg_parse_reply

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset dns_msg_parse_reply.0:10 --unwindset dns_msg_parse_reply.3:10

H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=y -DSOCK_HAS_IPV6=y

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
            -I$(ROOT)/sys/net/gnrc/sock/include/ \
            -I$(ROOT)/sys/posix/include \     



# Include our special build file
include ../Makefile.include
