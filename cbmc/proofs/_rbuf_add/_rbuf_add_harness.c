// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

/**
 * @brief Starting point for formal analysis
 * 
 */

#include <stdlib.h>
#include <stdint.h>

// #include "net/gnrc/pkt.h"
// #include "net/gnrc/netif/hdr.h"

// #include "sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c"
// #include "sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c"

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "net/ieee802154.h"
#include "net/eui64.h"
#include "net/ipv6.h"
#include "net/ipv6/hdr.h"
#include "net/ipv6/addr.h"
#include "net/gnrc.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
#include "net/gnrc/sixlowpan/ctx.h"
#ifdef  MODULE_GNRC_SIXLOWPAN_FRAG_STATS
#include "net/gnrc/sixlowpan/frag/stats.h"
#endif  /* MODULE_GNRC_SIXLOWPAN_FRAG_STATS */
#include "net/gnrc/sixlowpan/frag/minfwd.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"
#include "net/sixlowpan.h"
#include "net/sixlowpan/sfr.h"
#include "thread.h"
#include "xtimer.h"
#include "utlist.h"
#include "net/gnrc/nettype.h"

#include "net/gnrc/sixlowpan/frag/rb.h"


extern gnrc_sixlowpan_frag_rb_t rbuf[CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE];

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, size_t src_len, unsigned src_tag) {
    //I believe this can return null
    gnrc_sixlowpan_frag_vrb_t* vrb = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
    if(vrb == NULL) {
        return vrb;
    }

    //Need super defined
    gnrc_sixlowpan_frag_rb_base_t super;
    gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
    __CPROVER_assume(interval != NULL);
    //Assume it's a 1 entry LL
    //Can we assume this?
    __CPROVER_assume(interval -> next == NULL);

    super.ints = interval;
    vrb -> super = super;

    return vrb;
}

// int _rbuf_get(const void *src, size_t src_len,
//                      const void *dst, size_t dst_len,
//                      size_t size, uint16_t tag,
//                      unsigned page) {

//                         return ret;
//                      }

// int gnrc_pktbuf_realloc_data(gnrc_pktsnip_t *pkt, size_t size) {
//     int new_size;
//     __CPROVER_assume()
//     gnrc_pktsnip_t new_pkt = malloc()


// }

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    //Original function can change pkt data and size

    // This exposes CVE-2023-24825 but makes the run time far longer so I'm leaving it commented
    // __CPROVER_havoc_object(pkt);

    gnrc_pktsnip_t *new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    //Based on the original function this can return null
    if(new_pkt == NULL) {
        return new_pkt;
    }

    uint8_t size;
    uint8_t *data = malloc(size);
    __CPROVER_assume(data != NULL);
    new_pkt->data = data;
    new_pkt->size = size;
    new_pkt->next = NULL;

    return new_pkt;
}

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_id(uint8_t id) {
    gnrc_sixlowpan_ctx_t* context = malloc(sizeof(gnrc_sixlowpan_ctx_t));
    return context;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt,
                                         gnrc_nettype_t type) {
    gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(new_pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //This part of the buffer can be read as quite a few different things
    //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

    __CPROVER_assume(size <= 100 && size >= sizeof(gnrc_netif_hdr_t));

    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    new_pkt -> data = data;
    new_pkt -> size = size;
    new_pkt -> next = NULL;

    return new_pkt;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));
    //It CAN be NULL
    //Kind of just praying it doesn't need those function pointers in ops
    return new_netif;

}

void harness(void)
{

    //Constrain to 8 to address a potential vulnerability that causes an OOB read in _rbuf_get
    uint8_t src_addr;
    __CPROVER_assume(src_addr <= 8);

    uint8_t dest_addr;
    __CPROVER_assume(dest_addr <= 8); 

    //This type has a PDU beyond the end of the header
    gnrc_netif_hdr_t* netif_hdr = malloc(sizeof(gnrc_netif_hdr_t) + src_addr + dest_addr);
    __CPROVER_assume(netif_hdr != NULL);
    netif_hdr -> src_l2addr_len = src_addr;
    netif_hdr -> dst_l2addr_len = dest_addr;   

    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    size_t size;

    //This part of the buffer can be read as quite a few different things
    //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

    // __CPROVER_assume(size <= 100);

    //There is a function up the call stack that would crash if the header isn't long enough
    //So I'll assume this is large enough to fit the largest header format
    
    //Adding ipv6_hdr_t to the minimum size fixes two potential vulns
    //One OOB read/write in _iphc_ipv6_decode, where payload_len increments past the end of the buffer
    //One OOB read in _check_hdr

    __CPROVER_assume(size >= sizeof(sixlowpan_sfr_rfrag_t) + sizeof(ipv6_hdr_t));
    //Remove the above check to expose vuln CVE-2023-24821
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    pkt -> data = data;

    //Doing this to specifically expose CVE-2023-24821 without raising false positives 
    //Caused by the actual buffer being less than 4 bytes
    size_t fake_size;
    __CPROVER_assume(fake_size < 4);
    pkt -> size = fake_size;
    pkt -> next = NULL;

    size_t offset;
    //Prevents an OOB arithmatic overflow issue
    __CPROVER_assume(offset < 1000);

    //This check prevents a potential bug (OOB read on line 509)
    __CPROVER_assume(offset != 0 || sixlowpan_frag_1_is(pkt->data) || sixlowpan_sfr_rfrag_is(data));

    unsigned page;

    gnrc_sixlowpan_frag_rb_t entry;

    gnrc_pktsnip_t* entry_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(entry_pkt != NULL);

    size_t entry_size;
    __CPROVER_assume(entry_size > 0);
    uint8_t* entry_data = malloc(entry_size);
    __CPROVER_assume(entry_data != NULL);
    entry_pkt -> data = entry_data;
    entry_pkt -> size = entry_size;
    entry_pkt -> next = NULL;


    entry.pkt = entry_pkt;

    gnrc_sixlowpan_frag_rb_base_t super;

    gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
    __CPROVER_assume(interval != NULL);
    //Assume it's a 1 entry LL
    __CPROVER_assume(interval -> next == NULL);

    uint16_t datagram_size;
    __CPROVER_assume(datagram_size <= entry_size);
    super.datagram_size = datagram_size;

    super.ints = interval;

    entry.super = super;

        // Added this to fix a bug. Not sure how best to model it
    int8_t offset_diff;
    __CPROVER_assume(offset_diff >= 0); // Basically, offset diff should not be negative that it overflows.
    entry.offset_diff = offset_diff;

    rbuf[0] = entry;

    _rbuf_add(netif_hdr, pkt, offset, page);
}
