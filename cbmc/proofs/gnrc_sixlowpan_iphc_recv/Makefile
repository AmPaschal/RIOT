# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = /home/tlelievr/RIOT

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c

# Harness to utilize, omit the extension!
H_ENTRY = gnrc_sixlowpan_iphc_recv

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1


H_DEF = -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_SFR=1 -DMODULE_GNRC_SIXLOWPAN_FRAG=1 -DMODULE_GNRC_SIXLOWPAN_FRAG_MINFWD=1 -DMODULE_GNRC_SIXLOWPAN_IPHC=1 -DCONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE=1 -DMODULE_GNRC_IPV6=1 -DMODULE_GNRC_NETTYPE_IPV6=1

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
            -I$(ROOT)/sys/include/net/gnrc/ \
            -I$(ROOT)/sys/include/net/ipv6/ \
            -I$(ROOT)/sys/include/net/gnrc/netif \
            -I$(ROOT)/sys/include/net/gnrc/sixlowpan \
            -I$(ROOT)/sys/include/net/gnrc/sixlowpan/frag \
            -I$(ROOT)/sys/net/gnrc/pktbuf/include/  \
            -I$(ROOT)/sys/net/gnrc/pktbuf_static/include/  \


# Include our special build file
include ../Makefile.include
